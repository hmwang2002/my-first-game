# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\gameswhm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\gameswhm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/computer_choice.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/computer_choice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/computer_choice.dir/flags.make

CMakeFiles/computer_choice.dir/computer_choice.c.obj: CMakeFiles/computer_choice.dir/flags.make
CMakeFiles/computer_choice.dir/computer_choice.c.obj: ../computer_choice.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\gameswhm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/computer_choice.dir/computer_choice.c.obj"
	C:\winlibs-x86_64-posix-seh-gcc-11.2.0-llvm-12.0.1-mingw-w64-9.0.0-r1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\computer_choice.dir\computer_choice.c.obj -c D:\gameswhm\computer_choice.c

CMakeFiles/computer_choice.dir/computer_choice.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/computer_choice.dir/computer_choice.c.i"
	C:\winlibs-x86_64-posix-seh-gcc-11.2.0-llvm-12.0.1-mingw-w64-9.0.0-r1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\gameswhm\computer_choice.c > CMakeFiles\computer_choice.dir\computer_choice.c.i

CMakeFiles/computer_choice.dir/computer_choice.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/computer_choice.dir/computer_choice.c.s"
	C:\winlibs-x86_64-posix-seh-gcc-11.2.0-llvm-12.0.1-mingw-w64-9.0.0-r1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\gameswhm\computer_choice.c -o CMakeFiles\computer_choice.dir\computer_choice.c.s

# Object files for target computer_choice
computer_choice_OBJECTS = \
"CMakeFiles/computer_choice.dir/computer_choice.c.obj"

# External object files for target computer_choice
computer_choice_EXTERNAL_OBJECTS =

computer_choice.exe: CMakeFiles/computer_choice.dir/computer_choice.c.obj
computer_choice.exe: CMakeFiles/computer_choice.dir/build.make
computer_choice.exe: CMakeFiles/computer_choice.dir/linklibs.rsp
computer_choice.exe: CMakeFiles/computer_choice.dir/objects1.rsp
computer_choice.exe: CMakeFiles/computer_choice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\gameswhm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable computer_choice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\computer_choice.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/computer_choice.dir/build: computer_choice.exe
.PHONY : CMakeFiles/computer_choice.dir/build

CMakeFiles/computer_choice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\computer_choice.dir\cmake_clean.cmake
.PHONY : CMakeFiles/computer_choice.dir/clean

CMakeFiles/computer_choice.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\gameswhm D:\gameswhm D:\gameswhm\cmake-build-debug D:\gameswhm\cmake-build-debug D:\gameswhm\cmake-build-debug\CMakeFiles\computer_choice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/computer_choice.dir/depend

