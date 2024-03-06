#!/usr/bin/env python3

from scipy.io import wavfile
from scipy import signal
from scipy.stats import mstats
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import transforms
import argparse
import multiprocessing 
import os.path
import os
import subprocess
import time
import wave as wv
import math

# only needed for pyinstaller bug workaround
#import numpy.random.common
#import numpy.random.bounded_integers
#import numpy.random.entropy

####################################################################################

class SoundSpecLocks:

    def __init__(self):
        self.print_lock = None
        self.read_file_lock = None
        self.plot_file_lock = None
        
            
    def enable(self):
        self.print_lock = multiprocessing.Lock()
        self.read_file_lock = multiprocessing.Lock()
        self.plot_file_lock = multiprocessing.Lock()    # probably not needed 


locks = SoundSpecLocks()

####################################################################################

def main():
    argpar = get_argument_parser()
    args = argpar.parse_args()
    task = SoundSpec(args)
    task.process()
    
####################################################################################

def get_argument_parser():
    argpar = argparse.ArgumentParser(description="soundspec v0.1.9 - generate spectrogram from sound file")
    num_cores_avail = multiprocessing.cpu_count()
    
    # add options:
    argpar.add_argument('-a', '--amplitude-projection', dest='add_amplitude_projection', help='add amplitude projection', 
                        action='store_true')
    argpar.add_argument('-b', '--batch', help='batch run, no display, save image to disk', action='store_true')
    argpar.add_argument('-c', type=int, dest='num_cores', default = num_cores_avail,
                        help='number of cores to use, default is ' + str(num_cores_avail) + 
                        ' (set to smaller value if not enough memory, or to 1 to force single core processing)')
    argpar.add_argument('-C', type=int, dest='channel', default = 0,
                        help='set channel to process [1..N], default is to process all channels')
    argpar.add_argument('-d', '--debug', type=int, dest='debug_level', help='set debug level', default=0)
    argpar.add_argument('-l', '--linear', dest='use_linear_amplitude', help='use linear amplitude', action='store_true')
    argpar.add_argument('-p', '--ppi', type=int, help='set print resolution for batch mode (default is 200)', default=200)
    argpar.add_argument('-r', '--resolution', type=int, help='set resolution (default is 1000)', default=1000)
    argpar.add_argument('-w', '--window', help='set window for FFT (default is blackmanharris)', default='blackmanharris')

    # add arguments:
    argpar.add_argument('audiofile', type=str, nargs='+', 
                        help='audio file (WAV) to process, or a directory containing audio files')

    return argpar
        
####################################################################################


class SoundSpec:
  
    def __init__(self, options):
        self.args = options
        self.logger = SoundSpecLogger(options)
        if not self.args.batch:
            self.args.num_cores = 1 # force single core processing when not in batch mode
        self.audioFileConverter = AudioFileConverter(self.args, self.logger)
        

    def process(self):
        audio_files = self.__get_list_of_files(self.args.audiofile)
        num_files = len(audio_files)
        if num_files > 0 and self.args.num_cores > 1:
            num_errors = self.__process_files_multi_process(audio_files)
        else:
            num_errors = self.__process_files_single_process(audio_files)
        if num_errors > 0:
            self.logger.log_message('failed for ' + str(num_errors) + ' of ' + str(num_files) + ' files.')
        else:
            if num_files > 1:
                self.logger.log_message('succeeded for ' + str(num_files) + ' files')
                
    #-------------------------------------------------------------------------------

    def __get_list_of_files(self, audiofiles):
        list_of_files = []
        for file in audiofiles:
            if os.path.isdir(file):
                self.__add_files_in_dir(file, list_of_files)
            else:
                if self.audioFileConverter.is_audio_file(file):
                    list_of_files.append(file)
                else:
                    self.logger.log_message('ignored file ' + file + ': file type not supported or no audio file')
        return list_of_files
    
    
    def __process_files_multi_process(self, audiofiles):
        process_list = []
        num_errors = 0
        locks.enable()
        
        with multiprocessing.Pool(self.args.num_cores, ) as pool:
            for audiofile in audiofiles:
                process = pool.apply_async(self.process_file, (audiofile,))
                process_list.append(process)

            for process in process_list:
                num_errors += process.get()

        return num_errors

                
    def __process_files_single_process(self, audiofiles):
        num_errors = 0
        for audiofile in audiofiles:
            num_errors += self.process_file(audiofile)
        return num_errors

    #-------------------------------------------------------------------------------

    def __add_files_in_dir(self, directory, list_of_files):
        for root, dirs, files in os.walk(directory, topdown = True):
            for name in files:
                if self.audioFileConverter.is_audio_file(name):
                    path = os.path.join(root, name)
                    list_of_files.append(path)
        

    def process_file(self, audiofile):
        audiofile_reader = AudioFileReader(self.logger, self.audioFileConverter)
        sf, bw, audio = audiofile_reader.read(audiofile)
        # starting from here the code runs concurrently in batch mode
        if sf != None: 
            spectrogram_creator = SpectrogramCreator(self.args, self.logger)
            spectrogram_creator.create(audiofile, sf, bw, audio)
            return 0
        else:
            return 1


class AudioFileReader:
    
    def __init__(self, logger, audioFileConverter):
        self.logger = logger
        self.audioFileConverter = audioFileConverter
        
    def read(self, audiofile):
        if not os.path.exists(audiofile):
            self.logger.log_message(audiofile + ': not found')
            return None, None, None

        # use a lock to prevent concurrent reads (if available)
        if locks.read_file_lock:
            locks.read_file_lock.acquire()
        wav_file = None
        
        try:
            if self.__is_wav_file(audiofile):
                wav_file = audiofile
            else:    
                # convert audiofile into wav_file:
                wav_file = self.audioFileConverter.convert_to_wav(audiofile)
                if wav_file == None:
                    return None, None, None
                    
            self.logger.log_message(audiofile + ': reading WAV file ...')
            try:
                sf, audio = wavfile.read(wav_file) # sf = samplerate in Hz, audio.shape[] = #samples, [#channels (if > 1)]
            except:
                if wav_file != audiofile:
                    self.logger.log_message(audiofile + ': error reading converted WAV file')
                    return None, None, None
                # try again converting a possible 24 bit wav to 16 bit which can be handled
                self.logger.log_message(audiofile + ': reading failed, try conversion to 16 Bit ...')
                wav_file = self.convert_to_wav(audiofile)
                if wav_file == None:
                    return None, None, None
                sf, audio = wavfile.read(wav_file) # sf = samplerate in Hz, audio.shape[] = #samples, [#channels (if > 1)]
            
            num_samples = audio.shape[0]
            num_channels = 1;
            if len(audio.shape) > 1:
                num_channels = audio.shape[1]
            run_time = num_samples / sf
            run_time_str = time.strftime("%H:%M:%S", time.gmtime(run_time))
            bit_width = self.__get_bit_width(wav_file)
            format = str(int(sf/1000)) + '/' + str(bit_width)
            self.logger.log_message(audiofile + ': ' + str(num_channels) + ' channel(s) at ' + format + ' with ' + run_time_str + ' runtime')
        
        except:
            self.logger.log_message(audiofile + ': error reading audio data')
            return None, None, None
        finally:
            if wav_file != None and wav_file != audiofile:
                os.unlink(wav_file)
            if locks.read_file_lock:
                locks.read_file_lock.release()
        return sf, bit_width, audio

    #-------------------------------------------------------------------------------

    def __get_bit_width(self, audiofile):
        wavefile = None
        try:
            wavefile = wv.open(audiofile, 'rb')
            bw = 8 * wavefile.getsampwidth()
        except:
            self.logger.log_message(audiofile + ': cannot determine bit width, assume 16')
            bw = 16 # 24 would be OK since this is probably the reason why it failed, but scipy.io.wavfile handles 24 bit files as 16 bit
        finally:
            if wavefile != None:
                wavefile.close()
        return bw
    
        
    def __is_wav_file(self, filename):
        root, ext = os.path.splitext(filename)
        if ext.lower() == '.wav':
            return True
        return False
    
    
class AudioFileConverter:

    def __init__(self, options, logger):
        self.args = options
        self.logger = logger
        self.known_extensions = ['.wav']  # WAV files

        # settings for ffmpeg
        self.ffmpeg = 'ffmpeg'  # set full path to ffmpeg if required 
        self.ffmpeg_loglevel = 'error'
        if self.ffmpeg != None:
            # add all file types handled by ffmpeg: (incomplete)
            self.known_extensions.append('.flac')
            self.known_extensions.append('.mp3')
            self.known_extensions.append('.mp4')
            self.known_extensions.append('.m4a')
            self.known_extensions.append('.mkv')
            self.known_extensions.append('.avi')
            self.known_extensions.append('.ogg')
            self.known_extensions.append('.webm')

        
    def is_audio_file(self, filename):
        root, ext = os.path.splitext(filename)
        for known_ext in self.known_extensions:
            if ext.lower() == known_ext:
                return True
        return False

        
    def convert_to_wav(self, audiofile):
        # convert audiofile into wav_file:
        self.logger.log_message(audiofile + ': converting into 16 bit wav format ...')
        wav_file = audiofile + '_tmp-soundspec.wav'
        if os.path.exists(wav_file):
            os.unlink(wav_file)
        
        try:
            args = [self.ffmpeg, '-loglevel', self.ffmpeg_loglevel, '-nostdin', '-i', audiofile, wav_file]
            completed_process = subprocess.run(args, capture_output=True, check=True)
        except subprocess.SubprocessError as ex:
            self.logger.log_message(audiofile + ': failed to convert into wav format: ' + ex.stderr.decode())
            return None
        except:
            self.logger.log_message(audiofile + ': failed to convert into wav format: unknown exeption')
            return None
        if not os.path.exists(wav_file):
            self.logger.log_message(audiofile + ': failed to convert into wav format: missing file')
            return None
        return wav_file


class SpectrogramCreator:
  
    def __init__(self, options, logger):
        self.args = options
        self.logger = logger
        
        # FFT at high resolution makes way too many frequencies
        # set some lower number of frequencies we would like to keep
        # final result will be even smaller after pruning
        self.nf = self.args.resolution

    
    def create(self, audiofile, sf, bw, audio):
        # common sense limits for frequency
        fmin = 10
        if sf < fmin:
            self.logger.log_message(audiofile + ': Sampling frequency too low')
            return 1 # error

        self.logger.log_message(audiofile + ': processing ...')
        fmax = self.__determine_max_freq_to_show(sf)

        spg = Spectrogram(self.args, self.logger)
        num_errors, f, t, Sxx = spg.create_spectrogram(audiofile, audio, sf)
        if num_errors > 0:
            return num_errors
        self.logger.debug_message_range(2, 'spectrum', Sxx)

        self.logger.log_message(audiofile + ': downscaling spectra ...')
        # generate an exponential distribution of frequencies
        # (as opposed to the linear distribution from FFT)
        freqs = self.__exponential_distribution_of_frequencies(fmin, fmax)

        # delete frequencies lower than fmin
        fnew = f[f >= fmin]
        cropsize = f.size - fnew.size
        f = fnew
        Sxx = np.delete(Sxx, np.s_[0:cropsize], axis=0)

        # delete frequencies higher than fmax
        fnew = f[f <= fmax]
        cropsize = f.size - fnew.size
        f = fnew
        Sxx = Sxx[:-cropsize, :]
        self.logger.debug_message2(1, 'Sxx.shape: ', Sxx.shape)

        # find FFT frequencies closest to calculated exponential frequency distribution
        findex = []
        for i in range(freqs.size):
            f_ind = (np.abs(f - freqs[i])).argmin()
            findex.append(f_ind)
        if self.args.debug_level > 2:
            self.logger.debug_message2(2, 'findex: len=', len(findex))
            self.logger.debug_message2(4, 'findex=', findex)

        # keep only frequencies closest to exponential distribution
        # this is usually a massive cropping of the initial FFT data
        fnew = []
        for i in findex:
            fnew.append(f[i])
        f = np.asarray(fnew)

        num_errors, Sxxnew = self.__scale_down(freqs.size, findex, Sxx)
        if num_errors > 0:
            return num_errors
        Sxx = Sxxnew

        self.logger.debug_message2(1, 'Sxx.shape: ', Sxx.shape)
        
        if self.args.add_amplitude_projection:
            self.logger.log_message(audiofile + ': creating amplitude projection ...')
#            max_possible_value = 2 ** (bw - 1)
#            percent_correction = 100.0 / max_possible_value
            projection_ampl = np.amax(Sxx, axis=0) # * percent_correction # in%
        else:
            projection_ampl = None

        if not self.args.use_linear_amplitude:
            Sxx = self.__convert_into_dB(Sxx, sf, bw)
            self.logger.debug_message_range(2, 'spectrum range in dB: ', Sxx)

        self.logger.debug_message2(3, 'Sxx:\n', Sxx)

        self.logger.log_message(audiofile + ': creating frequency projection ...')
        projection_fr = np.amax(Sxx, axis=1)

        self.logger.log_message(audiofile + ': generating the image ...')
        plotter = SpectrogramPlotter(self.args, fmin, fmax, self.logger)
        plotter.plot_spectrogram(t, f, Sxx, projection_fr, projection_ampl, audiofile)
        return 0 # no error
    
    #-------------------------------------------------------------------------------
    
    def __determine_max_freq_to_show(self, sf):
        fmax = 20000
        if sf >= 48000:
            fmax = 22000
        if sf >= 88000:
            fmax = 40000
        if sf >= 176000:
            fmax = 80000
        if sf >= 352000:
            fmax = 160000
        if sf >= 704000:
            fmax = 320000
        return fmax


    def __exponential_distribution_of_frequencies(self, fmin, fmax):
        # generate an exponential distribution of frequencies
        # (as opposed to the linear distribution from FFT)
        b = fmin - 1
        a = np.log10(fmax - fmin + 1) / (self.nf - 1)
        freqs = np.empty(self.nf, int)
        for i in range(self.nf):
            freqs[i] = np.power(10, a * i) + b
        # list of frequencies, exponentially distributed:
        freqs = np.unique(freqs)    # remove duplicates
        self.logger.debug_message2(1, 'freqs.size: ', freqs.size)
        return freqs
    
        
    def __scale_down(self, num_freqs, findex, Sxx):
        # determine range for each frequency bin findex[i]
        findex_begin = []
        findex_end = []
        for i in range(num_freqs):
            if i == 0:
                begin = 0                                       # at 1st point
                findex_begin.append(begin)

                end = self.__get_mean(findex[0 : 2])              # geometric mean of 1st two points
                end = min(int(end + 0.5), findex[1] - 1)        # limit to valid range (no overlap with next range)
                end = max(end, 0)
                findex_end.append(end)
            else:
                if i < (num_freqs - 1):
                    begin = findex_end[i-1] + 1                 # at 1st point after previous range
                    findex_begin.append(begin)

                    end = self.__get_mean(findex[i : i+2])        # geometric mean of current and next point
                    end = min(int(end+0.5), findex[i+1] - 1)    # limit to valid range (no overlap with next range
                    end = max(end, findex[i])
                    findex_end.append(end)
                else:
                    begin = findex_end[i-1] + 1                 # at 1st point after previous range
                    findex_begin.append(begin)

                    end = findex[i]                             # at last point
                    findex_end.append(end)
        self.logger.debug_message2(6, 'findex_begin: ', findex_begin)
        self.logger.debug_message2(6, 'findex_end: ', findex_end)

        # sanity check
        num_errors = self.__downscale_sanity_check(num_freqs, findex, findex_begin, findex_end)
        if num_errors > 0:
            return num_errors, None

        self.logger.debug_message2(2, 'Sxx.shape: ', Sxx.shape)
        maximum_spectra = np.empty((num_freqs, Sxx.shape[1]))  # 85 frequencies in 91 spectra
        self.logger.debug_message2(2, 'maximum_spectra.shape :', maximum_spectra.shape)
        for i in range(num_freqs):
            # select those spectra which shall be used to find the maximum for each frequency
            ssx_range = range(findex_begin[i], findex_end[i] + 1)
            self.logger.debug_message2(4, 'ssx_range             : ', ssx_range)
            selected_spectra = Sxx[ssx_range, :]
            self.logger.debug_message2(4, 'selected_spectra.shape: ', selected_spectra.shape)
            self.logger.debug_message2(5, 'selected_spectra: ', selected_spectra)
            maximum_spectra[i] = np.amax(selected_spectra, axis=0)

        return 0, maximum_spectra
    
    #-------------------------------------------------------------------------------

    def __convert_into_dB(self, Sxx, npts, bit_width):
        max_possible_value = 2 ** (bit_width - 1)
        Sxx_dB = 20 * np.log10(Sxx / max_possible_value)

        # set lower limit according to FFT gain and bit width
        fft_gain = self.__get_fft_gain(npts)
        min_value_dB = - (bit_width * 6 + fft_gain)
        Sxx_dB[Sxx_dB < min_value_dB] = min_value_dB
        return Sxx_dB   
        
        
    #-------------------------------------------------------------------------------

    def __downscale_sanity_check(self, num_freqs, findex, findex_begin, findex_end):
        for i in range(num_freqs):
            if findex_begin[i] > findex[i]:
                self.logger.log_message(audiofile + ': findex[' + str(i) + ']: begin error')
                return 1
            if findex_end[i] < findex[i]:
                self.logger.log_message(audiofile + ': findex[' + str(i) + ']: end error')
                return 1
            if i == 0:
                if findex_end[i] >= findex_begin[i+1]:
                    self.logger.log_message(audiofile + ': findex[' + str(i) + ']: end overlap error')
                    return 1
            else:
                if i < (num_freqs - 1):
                    if findex_begin[i] <= findex_end[i-1]:
                        self.logger.log_message(audiofile + ': findex[' + str(i) + ']: begin overlap error')
                        return 1
                    if findex_end[i] >= findex_begin[i+1]:
                        self.logger.log_message(audiofile + ': findex[' + str(i) + ']: end overlap error')
                        return 1
                else:
                    if findex_begin[i] <= findex_end[i-1]:
                        self.logger.log_message(audiofile + ': findex[' + str(i) + ']: begin overlap error')
                        return 1
        return 0

    def __get_fft_gain(self, npts):
        fft_gain = 3 * math.log(npts) / math.log(2) - 3 # 3dB per doubling
        return fft_gain
 

    def __get_mean(self, values):
        try:
            np.seterr(divide = 'raise') 
            mean_value = mstats.gmean(values) # may fail with "RuntimeWarning: divide by zero encountered in log"
        except:
            mean_value = np.mean(values)  # use arithmetic mean if geometric mean fails, e.g. for [0, 1]
        finally:
            np.seterr(divide = 'warn')
        return mean_value
       

class Spectrogram:
  
    def __init__(self, options, logger):
        self.args = options
        self.logger = logger
        
        # FFT at high resolution makes way too many frequencies
        # set some lower number of frequencies we would like to keep
        # final result will be even smaller after pruning
        self.nf = self.args.resolution

    # return num_errors, f[], t[], spectrum[][]
    def create_spectrogram(self, audiofile, audio, sf):
        self.logger.log_message(audiofile + ': calculating FFT ...')
        if audio.ndim > 1:
            if self.args.channel > 0:
                num_channels = audio.shape[1]
                if self.args.channel > num_channels:
                    self.logger.log_message('Error: ' + audiofile + ' does not contain channel ' + str(self.args.channel))
                    return 1, None, None, None
                channel = audio[:, self.args.channel - 1]
                f, t, Sxx = self.__create_mono_spectrogram(audiofile, channel, sf)
                return 0, f, t, Sxx
            f, t, Sxx = self.__create_multi_channel_spectrogram(audiofile, audio, sf)
            return 0, f, t, Sxx
        f, t, Sxx = self.__create_mono_spectrogram(audiofile, audio, sf)
        return 0, f, t, Sxx
 
    #-------------------------------------------------------------------------------

    def __create_multi_channel_spectrogram(self, audiofile, audio, sf):
        # calculate spectrogram for each channel, then sum them up to one channel
        num_channels = audio.shape[1]
        f_array = []
        t_array = []
        s_array = []
        for i in range(num_channels):
            channel = audio[:, i]
            self.logger.debug_message_range(2, 'audio ch' + str(i+1), channel)
            f, t, Sxx = self.__create_single_spectrogram(audiofile, channel, sf)
            self.logger.debug_message_range(2, 'spectrum ch' + str(i+1), Sxx)
            if i == 0:
                f_array.append(f)   # we need only the first one (they are all identical) to return to the caller
                t_array.append(t)   # --- dito ---
            s_array.append(Sxx)
        self.logger.log_message(audiofile + ': converting to mono ...')

        # take the sum over the spectra and scale it back according to the number of channels:
        correction_factor = self.__get_window_function_correction_factor() / num_channels
        spectrum = np.sum(np.asarray(s_array), axis = 0) * correction_factor 
        return np.asarray(f_array[0]), np.asarray(t_array[0]), spectrum
        
        
    def __create_mono_spectrogram(self, audiofile, audio, sf):
        self.logger.debug_message_range(2, 'audio', audio)
        f, t, Sxx_nocorr = self.__create_single_spectrogram(audiofile, audio, sf)
        Sxx = Sxx_nocorr * self.__get_window_function_correction_factor()
        return f, t, Sxx
       
    #-------------------------------------------------------------------------------

    def __create_single_spectrogram(self, audiofile, sig, sf):
        # vertical resolution (frequency)
        # number of points per segment; more points = better frequency resolution
        # if equal to sf, then frequency resolution is 1 Hz
        npts = int(sf)

        # horizontal resolution (time)
        num_overlap = self.__get_number_of_overlaps(sf, npts, len(sig))

        # create the spectrogram, returns:
        # - f = [0..sf/2], 
        # - t = [0.5 .. run_time-0.5],
        # - Sxx = array[f.size, t.size]
        f, t, Sxx = signal.spectrogram(sig, sf, nperseg=npts, noverlap=num_overlap, window = self.args.window, mode='magnitude')
        self.logger.debug_message2(6, 'f.shape: ', f.shape)
        self.logger.debug_message2(6, 't.shape: ', t.shape)
        self.logger.debug_message2(6, 'Sxx.shape: ', Sxx.shape)
        return f, t, Sxx
       
    #-------------------------------------------------------------------------------

    def __get_window_function_correction_factor(self):
        # this is the factor with which the spectra values must be multiplied 
        # to correct for the loss due to the window applied in the FFT
        if self.args.window == 'blackmanharris':
            return 2.831593
        if self.args.window == 'boxcar':
            return 2.000000
        return 1.000000 # yet unknown, so stick with 1
    
       
    def __get_number_of_overlaps(self, sf, npts, num_samples):
        # fudge factor to keep the number of frequency samples close to self.nf
        # (assuming an image width of about self.nf px)
        # negative values ought to be fine
        run_time = num_samples / sf
        winfudge = 1 - (run_time / self.nf)
        num_overlap = int(winfudge * npts)  # = (1 - (num_samples / sf / self.nf)) * sf
        return num_overlap
    

class SpectrogramPlotter:
    
    def __init__(self, options, fmin, fmax, logger):
        self.args = options
        self.fmin = fmin
        self.fmax = fmax
        self.logger = logger


    def plot_spectrogram(self, t, f, Sxx, projection_fr, projection_ampl, audiofile):
        if locks.plot_file_lock:
            locks.plot_file_lock.acquire()
        try:
            if self.args.add_amplitude_projection:
                fig = plt.figure(figsize = (10, 8))
                gs = fig.add_gridspec(ncols = 2, nrows = 2,  
                                      width_ratios = [2, 8], wspace = 0.02,
                                      height_ratios = [1.8, 6.2], hspace = 0.1)

                self.__plot_amplitude_projection(fig, gs[0, 1], t, projection_ampl)
                self.__plot_frequency_projection(fig, gs[1, 0], f, projection_fr)
                self.__plot_spectrogram(fig, gs[1, 1], t, f, Sxx)
            else:
                fig = plt.figure(figsize = (10, 6))
                gs = fig.add_gridspec(ncols = 2, nrows = 1,  
                                      width_ratios = [2, 8], wspace = 0.02)

                self.__plot_frequency_projection(fig, gs[0], f, projection_fr)
                self.__plot_spectrogram(fig, gs[1], t, f, Sxx)

            plt.suptitle(self.__get_plot_title(audiofile))
            if self.args.batch:
                image_file = audiofile + '.png'
                self.logger.log_message(audiofile + ': create spectrogram ' + os.path.basename(image_file))
                plt.savefig(image_file, dpi=self.args.ppi)
            else:
                plt.show()
        finally:
            if locks.plot_file_lock:
                locks.plot_file_lock.release()

    #-------------------------------------------------------------------------------

    def __plot_amplitude_projection(self, fig, pos, t, projection):
        ax_a_proj = fig.add_subplot(pos)
        ax_a_proj.plot(t, projection)
        ax_a_proj.fill_between(t, projection)
        ax_a_proj.set_title('Amplitude over Time')
        self.__set_amplitude_projection_xaxis(ax_a_proj, t)
        self.__set_amplitude_projection_yaxis(ax_a_proj)
        ax_a_proj.grid(True)


    def __plot_frequency_projection(self, fig, pos, f, projection):
        ax_f_proj = fig.add_subplot(pos)
            
        # rotate plot by 90 degree
        # see https://stackoverflow.com/questions/22540449/how-can-i-rotate-a-matplotlib-plot-through-90-degrees
        proj_base = ax_f_proj.transData
        rotation = transforms.Affine2D().rotate_deg(90)
        ax_f_proj.plot(f, projection, transform = rotation + proj_base)
            
        ax_f_proj.set_title('Frequency Response')
        self.__set_frequency_projection_xaxis(ax_f_proj)
        self.__set_frequency_projection_yaxis(ax_f_proj)
        ax_f_proj.grid(True)


    def __plot_spectrogram(self, fig, pos, t, f, Sxx):
        ax_spgr = fig.add_subplot(pos)
        ax_spgr.pcolormesh(t, f, Sxx)
        self.__set_spectrogram_xaxis(ax_spgr, t)
        self.__set_spectrogram_yaxis(ax_spgr)
        ax_spgr.grid(True)
        ax_spgr.set_title('Spectrogram')
            
            
    def __get_plot_title(self, audiofile):
        title = os.path.basename(audiofile)
        if self.args.channel > 0:
            return title + ' (channel ' + str(self.args.channel) + ')'
        return title
    
    #-------------------------------------------------------------------------------
        
    def __set_amplitude_projection_xaxis(self, ax, t):
        time_s = t[t.size-1]
        ax.set_xlim(0, time_s)

        ticks = self.__get_time_ticks(time_s)
        if ticks != None:
            labels = self.__get_time_labels(time_s, ticks, empty=True)
            ax.set_xticks(ticks)
            ax.set_xticklabels(labels)
    
    
    def __set_amplitude_projection_yaxis(self, ax):
        ax.set_ylabel('Level')
        ax.set_ylim(0, None)    # for linear level
#        ax.set_ylim(-120, 0)    # for level in dB
    
    
    def __set_frequency_projection_xaxis(self, ax):
        # for anknown reasons pyplot insists that the xscale has the wrong direction
        if self.args.use_linear_amplitude:
            # crude workaround: just don't display any ticks
            ax.set_xticks([])
        else:
            # crude workaround: invert the names of the ticks
            # TODO: calculate the ticks according to the bit width
            ax.set_xticks(     [0,   20,   40,  60,   80, 100,   120])
            ax.set_xticklabels(['0', '', '-40', '', '-80', '', '-120']) # workaround for negative scale???
        ax.set_xlabel('Peak Amplitude')
    
    
    def __set_frequency_projection_yaxis(self, ax):
        ax.set_ylabel('Frequency [Hz]')
        ax.set_yscale('symlog')
        ax.set_ylim(self.fmin, self.fmax)
        # ax.get_yaxis().tick_right()    # show ticks on right side of the plot
        ticks = self.__get_frequency_ticks()
        labels = self.__get_frequency_labels(ticks, empty=False)
        ax.set_yticks(ticks)
        ax.set_yticklabels(labels)
    
    
    def __set_spectrogram_xaxis(self, ax, t):
        time_s = t[t.size-1]
        ax.set_xlabel(self.__get_time_label(time_s))

        ticks = self.__get_time_ticks(time_s)
        if ticks != None:
            labels = self.__get_time_labels(time_s, ticks, empty=False)
            ax.set_xticks(ticks)
            ax.set_xticklabels(labels)
            

    def __set_spectrogram_yaxis(self, ax):
#        ax.set_ylabel('Frequency [Hz]')
        ax.set_yscale('symlog')
        ax.set_ylim(self.fmin, self.fmax)
        
        ticks = self.__get_frequency_ticks()
        labels = self.__get_frequency_labels(ticks, empty=True)
        ax.set_yticks(ticks)
        ax.set_yticklabels(labels)

    #-------------------------------------------------------------------------------

    def __get_time_label(self, time_s):
        if time_s <= 60:
            return 'Time [sec]'
        if time_s <= (5 * 60):
            return 'Time [min:sec]'
        return 'Time [min]'


    def __get_time_ticks(self, time_s):
        if time_s <= 60:
            return None # use standard x-axis
        num_minutes = time_s / 60
        step = 10               # 0:10 ...
        if num_minutes > 1.7:
            step = 20           # 0:20 ...
        if num_minutes > 3:
            step = 30           # 0:30 ...
        if num_minutes > 5:
            step = 60           # 1:00 ...
        if num_minutes > 10:
            step = 120          # 2:00 ...
        if num_minutes > 30:
            step = 300          # 5:00
        if num_minutes > 60:
            step = 600          # 10:00
        if num_minutes > 120:
            step = 1200         # 20:00
        ticks = np.arange(step, time_s, step)
        return ticks.tolist()
    
    
    def __get_time_labels(self, time_s, ticks, empty):
        num_minutes = time_s / 60
        if num_minutes > 5: 
            time_format= "%M"       # returns mm
        else:
            time_format = "%M:%S"   # returns mm:ss
        labels = []
        for tick in ticks:
            if empty == True:
                label = ''
            else:
                label = time.strftime(time_format, time.gmtime(tick))
                if label[0] == '0':
                    label = label[1:]   # strip leading 0
            labels.append(label)
        return labels
    
    
    def __get_frequency_ticks(self):
        yt = np.arange(10, 100, 10)                                         # creates [10, 20, 30, ... 80, 90]
        yt = np.concatenate((yt, 10 * yt, 100 * yt, 1000 * yt, 10000 * yt)) # extend to 100, 1k, 10k, 100k
        yt = yt[yt <= self.fmax]
        ticks = yt.tolist()
        return ticks


    def __get_frequency_labels(self, ticks, empty):
        labels = []
        for tick in ticks:
            if empty == True:
                label = ''
            else:
                if tick >= 1000:
                    label = str(int(tick/1000)) + 'k'
                else:
                    label = str(int(tick))
                if label[0] != '1' and label[0] != '2' and label[0] != '5':
                    label = ''
            labels.append(label)
        return labels


class SoundSpecLogger:
  
    def __init__(self, options):
        self.args = options
        self.print_lock = None
        
        
    def initialize_lock(self, print_lock):
        self.print_lock = print_lock


    def log_message(self, msg):
        if locks.print_lock:
            locks.print_lock.acquire()
        try:
            print(msg)
        finally:
            if locks.print_lock:
                locks.print_lock.release()


    def debug_message(self, level, msg):
        if self.args.debug_level > level:
            self.log_message(msg)
          
          
    # use this function for big data - the str() function is only called when used
    def debug_message2(self, level, msg, data):
        if self.args.debug_level > level:
            self.log_message(msg + str(data))
          
          
    # use this function for big data - the amin/amax() functions are only called when used
    def debug_message_range(self, level, name, data):
        if self.args.debug_level > level:
            minval = np.amin(np.amin(data))
            maxval = np.amax(np.amax(data))
            self.log_message(name + ' range: [' + str(minval) + ' .. ' + str(maxval) + ']')


####################################################################################

if __name__ == "__main__":
    main()

