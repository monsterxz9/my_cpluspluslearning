# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Program\C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Program\build

# Include any dependencies generated for this target.
include CMakeFiles/C++.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/C++.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/C++.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C++.dir/flags.make

CMakeFiles/C++.dir/main.cpp.obj: CMakeFiles/C++.dir/flags.make
CMakeFiles/C++.dir/main.cpp.obj: E:/Program/C++/main.cpp
CMakeFiles/C++.dir/main.cpp.obj: CMakeFiles/C++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C++.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/C++.dir/main.cpp.obj -MF CMakeFiles\C++.dir\main.cpp.obj.d -o CMakeFiles\C++.dir\main.cpp.obj -c E:\Program\C++\main.cpp

CMakeFiles/C++.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/C++.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Program\C++\main.cpp > CMakeFiles\C++.dir\main.cpp.i

CMakeFiles/C++.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/C++.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Program\C++\main.cpp -o CMakeFiles\C++.dir\main.cpp.s

CMakeFiles/C++.dir/this.cpp.obj: CMakeFiles/C++.dir/flags.make
CMakeFiles/C++.dir/this.cpp.obj: E:/Program/C++/this.cpp
CMakeFiles/C++.dir/this.cpp.obj: CMakeFiles/C++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/C++.dir/this.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/C++.dir/this.cpp.obj -MF CMakeFiles\C++.dir\this.cpp.obj.d -o CMakeFiles\C++.dir\this.cpp.obj -c E:\Program\C++\this.cpp

CMakeFiles/C++.dir/this.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/C++.dir/this.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Program\C++\this.cpp > CMakeFiles\C++.dir\this.cpp.i

CMakeFiles/C++.dir/this.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/C++.dir/this.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Program\C++\this.cpp -o CMakeFiles\C++.dir\this.cpp.s

CMakeFiles/C++.dir/SmartPointer.cpp.obj: CMakeFiles/C++.dir/flags.make
CMakeFiles/C++.dir/SmartPointer.cpp.obj: E:/Program/C++/SmartPointer.cpp
CMakeFiles/C++.dir/SmartPointer.cpp.obj: CMakeFiles/C++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/C++.dir/SmartPointer.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/C++.dir/SmartPointer.cpp.obj -MF CMakeFiles\C++.dir\SmartPointer.cpp.obj.d -o CMakeFiles\C++.dir\SmartPointer.cpp.obj -c E:\Program\C++\SmartPointer.cpp

CMakeFiles/C++.dir/SmartPointer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/C++.dir/SmartPointer.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Program\C++\SmartPointer.cpp > CMakeFiles\C++.dir\SmartPointer.cpp.i

CMakeFiles/C++.dir/SmartPointer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/C++.dir/SmartPointer.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Program\C++\SmartPointer.cpp -o CMakeFiles\C++.dir\SmartPointer.cpp.s

CMakeFiles/C++.dir/tabletennis.cpp.obj: CMakeFiles/C++.dir/flags.make
CMakeFiles/C++.dir/tabletennis.cpp.obj: E:/Program/C++/tabletennis.cpp
CMakeFiles/C++.dir/tabletennis.cpp.obj: CMakeFiles/C++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/C++.dir/tabletennis.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/C++.dir/tabletennis.cpp.obj -MF CMakeFiles\C++.dir\tabletennis.cpp.obj.d -o CMakeFiles\C++.dir\tabletennis.cpp.obj -c E:\Program\C++\tabletennis.cpp

CMakeFiles/C++.dir/tabletennis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/C++.dir/tabletennis.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Program\C++\tabletennis.cpp > CMakeFiles\C++.dir\tabletennis.cpp.i

CMakeFiles/C++.dir/tabletennis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/C++.dir/tabletennis.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Program\C++\tabletennis.cpp -o CMakeFiles\C++.dir\tabletennis.cpp.s

CMakeFiles/C++.dir/test.cpp.obj: CMakeFiles/C++.dir/flags.make
CMakeFiles/C++.dir/test.cpp.obj: E:/Program/C++/test.cpp
CMakeFiles/C++.dir/test.cpp.obj: CMakeFiles/C++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/C++.dir/test.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/C++.dir/test.cpp.obj -MF CMakeFiles\C++.dir\test.cpp.obj.d -o CMakeFiles\C++.dir\test.cpp.obj -c E:\Program\C++\test.cpp

CMakeFiles/C++.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/C++.dir/test.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Program\C++\test.cpp > CMakeFiles\C++.dir\test.cpp.i

CMakeFiles/C++.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/C++.dir/test.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Program\C++\test.cpp -o CMakeFiles\C++.dir\test.cpp.s

CMakeFiles/C++.dir/test1.cpp.obj: CMakeFiles/C++.dir/flags.make
CMakeFiles/C++.dir/test1.cpp.obj: E:/Program/C++/test1.cpp
CMakeFiles/C++.dir/test1.cpp.obj: CMakeFiles/C++.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/C++.dir/test1.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/C++.dir/test1.cpp.obj -MF CMakeFiles\C++.dir\test1.cpp.obj.d -o CMakeFiles\C++.dir\test1.cpp.obj -c E:\Program\C++\test1.cpp

CMakeFiles/C++.dir/test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/C++.dir/test1.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Program\C++\test1.cpp > CMakeFiles\C++.dir\test1.cpp.i

CMakeFiles/C++.dir/test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/C++.dir/test1.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Program\C++\test1.cpp -o CMakeFiles\C++.dir\test1.cpp.s

# Object files for target C++
C_______OBJECTS = \
"CMakeFiles/C++.dir/main.cpp.obj" \
"CMakeFiles/C++.dir/this.cpp.obj" \
"CMakeFiles/C++.dir/SmartPointer.cpp.obj" \
"CMakeFiles/C++.dir/tabletennis.cpp.obj" \
"CMakeFiles/C++.dir/test.cpp.obj" \
"CMakeFiles/C++.dir/test1.cpp.obj"

# External object files for target C++
C_______EXTERNAL_OBJECTS =

C++.exe: CMakeFiles/C++.dir/main.cpp.obj
C++.exe: CMakeFiles/C++.dir/this.cpp.obj
C++.exe: CMakeFiles/C++.dir/SmartPointer.cpp.obj
C++.exe: CMakeFiles/C++.dir/tabletennis.cpp.obj
C++.exe: CMakeFiles/C++.dir/test.cpp.obj
C++.exe: CMakeFiles/C++.dir/test1.cpp.obj
C++.exe: CMakeFiles/C++.dir/build.make
C++.exe: CMakeFiles/C++.dir/linkLibs.rsp
C++.exe: CMakeFiles/C++.dir/objects1.rsp
C++.exe: CMakeFiles/C++.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Program\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable C++.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C++.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C++.dir/build: C++.exe
.PHONY : CMakeFiles/C++.dir/build

CMakeFiles/C++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C++.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C++.dir/clean

CMakeFiles/C++.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Program\C++ E:\Program\C++ E:\Program\build E:\Program\build E:\Program\build\CMakeFiles\C++.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/C++.dir/depend

