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
include chapter_tree/CMakeFiles/avl_tree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include chapter_tree/CMakeFiles/avl_tree.dir/compiler_depend.make

# Include the progress variables for this target.
include chapter_tree/CMakeFiles/avl_tree.dir/progress.make

# Include the compile flags for this target's objects.
include chapter_tree/CMakeFiles/avl_tree.dir/flags.make

chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj: chapter_tree/CMakeFiles/avl_tree.dir/flags.make
chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj: chapter_tree/CMakeFiles/avl_tree.dir/includes_C.rsp
chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj: E:/Program/hello\ algo/chapter_tree/avl_tree.c
chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj: chapter_tree/CMakeFiles/avl_tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="E:\Program\hello algo\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj"
	cd /d "E:\Program\hello algo\build\chapter_tree" && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj -MF CMakeFiles\avl_tree.dir\avl_tree.c.obj.d -o CMakeFiles\avl_tree.dir\avl_tree.c.obj -c "E:\Program\hello algo\chapter_tree\avl_tree.c"

chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/avl_tree.dir/avl_tree.c.i"
	cd /d "E:\Program\hello algo\build\chapter_tree" && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\Program\hello algo\chapter_tree\avl_tree.c" > CMakeFiles\avl_tree.dir\avl_tree.c.i

chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/avl_tree.dir/avl_tree.c.s"
	cd /d "E:\Program\hello algo\build\chapter_tree" && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\Program\hello algo\chapter_tree\avl_tree.c" -o CMakeFiles\avl_tree.dir\avl_tree.c.s

# Object files for target avl_tree
avl_tree_OBJECTS = \
"CMakeFiles/avl_tree.dir/avl_tree.c.obj"

# External object files for target avl_tree
avl_tree_EXTERNAL_OBJECTS =

chapter_tree/avl_tree.exe: chapter_tree/CMakeFiles/avl_tree.dir/avl_tree.c.obj
chapter_tree/avl_tree.exe: chapter_tree/CMakeFiles/avl_tree.dir/build.make
chapter_tree/avl_tree.exe: chapter_tree/CMakeFiles/avl_tree.dir/linkLibs.rsp
chapter_tree/avl_tree.exe: chapter_tree/CMakeFiles/avl_tree.dir/objects1.rsp
chapter_tree/avl_tree.exe: chapter_tree/CMakeFiles/avl_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="E:\Program\hello algo\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable avl_tree.exe"
	cd /d "E:\Program\hello algo\build\chapter_tree" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\avl_tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter_tree/CMakeFiles/avl_tree.dir/build: chapter_tree/avl_tree.exe
.PHONY : chapter_tree/CMakeFiles/avl_tree.dir/build

chapter_tree/CMakeFiles/avl_tree.dir/clean:
	cd /d "E:\Program\hello algo\build\chapter_tree" && $(CMAKE_COMMAND) -P CMakeFiles\avl_tree.dir\cmake_clean.cmake
.PHONY : chapter_tree/CMakeFiles/avl_tree.dir/clean

chapter_tree/CMakeFiles/avl_tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Program\hello algo" "E:\Program\hello algo\chapter_tree" "E:\Program\hello algo\build" "E:\Program\hello algo\build\chapter_tree" "E:\Program\hello algo\build\chapter_tree\CMakeFiles\avl_tree.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : chapter_tree/CMakeFiles/avl_tree.dir/depend

