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
CMAKE_SOURCE_DIR = "E:\Program\hello algo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Program\hello algo\build"

# Include any dependencies generated for this target.
include chapter_stack_and_queue/CMakeFiles/array_queue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include chapter_stack_and_queue/CMakeFiles/array_queue.dir/compiler_depend.make

# Include the progress variables for this target.
include chapter_stack_and_queue/CMakeFiles/array_queue.dir/progress.make

# Include the compile flags for this target's objects.
include chapter_stack_and_queue/CMakeFiles/array_queue.dir/flags.make

chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj: chapter_stack_and_queue/CMakeFiles/array_queue.dir/flags.make
chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj: chapter_stack_and_queue/CMakeFiles/array_queue.dir/includes_C.rsp
chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj: E:/Program/hello\ algo/chapter_stack_and_queue/array_queue.c
chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj: chapter_stack_and_queue/CMakeFiles/array_queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="E:\Program\hello algo\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj"
	cd /d "E:\Program\hello algo\build\chapter_stack_and_queue" && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj -MF CMakeFiles\array_queue.dir\array_queue.c.obj.d -o CMakeFiles\array_queue.dir\array_queue.c.obj -c "E:\Program\hello algo\chapter_stack_and_queue\array_queue.c"

chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/array_queue.dir/array_queue.c.i"
	cd /d "E:\Program\hello algo\build\chapter_stack_and_queue" && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\Program\hello algo\chapter_stack_and_queue\array_queue.c" > CMakeFiles\array_queue.dir\array_queue.c.i

chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/array_queue.dir/array_queue.c.s"
	cd /d "E:\Program\hello algo\build\chapter_stack_and_queue" && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\Program\hello algo\chapter_stack_and_queue\array_queue.c" -o CMakeFiles\array_queue.dir\array_queue.c.s

# Object files for target array_queue
array_queue_OBJECTS = \
"CMakeFiles/array_queue.dir/array_queue.c.obj"

# External object files for target array_queue
array_queue_EXTERNAL_OBJECTS =

chapter_stack_and_queue/array_queue.exe: chapter_stack_and_queue/CMakeFiles/array_queue.dir/array_queue.c.obj
chapter_stack_and_queue/array_queue.exe: chapter_stack_and_queue/CMakeFiles/array_queue.dir/build.make
chapter_stack_and_queue/array_queue.exe: chapter_stack_and_queue/CMakeFiles/array_queue.dir/linkLibs.rsp
chapter_stack_and_queue/array_queue.exe: chapter_stack_and_queue/CMakeFiles/array_queue.dir/objects1.rsp
chapter_stack_and_queue/array_queue.exe: chapter_stack_and_queue/CMakeFiles/array_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="E:\Program\hello algo\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable array_queue.exe"
	cd /d "E:\Program\hello algo\build\chapter_stack_and_queue" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\array_queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter_stack_and_queue/CMakeFiles/array_queue.dir/build: chapter_stack_and_queue/array_queue.exe
.PHONY : chapter_stack_and_queue/CMakeFiles/array_queue.dir/build

chapter_stack_and_queue/CMakeFiles/array_queue.dir/clean:
	cd /d "E:\Program\hello algo\build\chapter_stack_and_queue" && $(CMAKE_COMMAND) -P CMakeFiles\array_queue.dir\cmake_clean.cmake
.PHONY : chapter_stack_and_queue/CMakeFiles/array_queue.dir/clean

chapter_stack_and_queue/CMakeFiles/array_queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Program\hello algo" "E:\Program\hello algo\chapter_stack_and_queue" "E:\Program\hello algo\build" "E:\Program\hello algo\build\chapter_stack_and_queue" "E:\Program\hello algo\build\chapter_stack_and_queue\CMakeFiles\array_queue.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : chapter_stack_and_queue/CMakeFiles/array_queue.dir/depend

