# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/lisa_/ClionProjects/Pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pong.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pong.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pong.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pong.dir/flags.make

CMakeFiles/pong.dir/main.c.o: CMakeFiles/pong.dir/flags.make
CMakeFiles/pong.dir/main.c.o: ../main.c
CMakeFiles/pong.dir/main.c.o: CMakeFiles/pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pong.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pong.dir/main.c.o -MF CMakeFiles/pong.dir/main.c.o.d -o CMakeFiles/pong.dir/main.c.o -c /mnt/c/Users/lisa_/ClionProjects/Pong/main.c

CMakeFiles/pong.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pong.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/lisa_/ClionProjects/Pong/main.c > CMakeFiles/pong.dir/main.c.i

CMakeFiles/pong.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pong.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/lisa_/ClionProjects/Pong/main.c -o CMakeFiles/pong.dir/main.c.s

CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o: CMakeFiles/pong.dir/flags.make
CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o: ../cli-lib/src/keyboard.c
CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o: CMakeFiles/pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o -MF CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o.d -o CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o -c /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/keyboard.c

CMakeFiles/pong.dir/cli-lib/src/keyboard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pong.dir/cli-lib/src/keyboard.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/keyboard.c > CMakeFiles/pong.dir/cli-lib/src/keyboard.c.i

CMakeFiles/pong.dir/cli-lib/src/keyboard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pong.dir/cli-lib/src/keyboard.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/keyboard.c -o CMakeFiles/pong.dir/cli-lib/src/keyboard.c.s

CMakeFiles/pong.dir/cli-lib/src/screen.c.o: CMakeFiles/pong.dir/flags.make
CMakeFiles/pong.dir/cli-lib/src/screen.c.o: ../cli-lib/src/screen.c
CMakeFiles/pong.dir/cli-lib/src/screen.c.o: CMakeFiles/pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/pong.dir/cli-lib/src/screen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pong.dir/cli-lib/src/screen.c.o -MF CMakeFiles/pong.dir/cli-lib/src/screen.c.o.d -o CMakeFiles/pong.dir/cli-lib/src/screen.c.o -c /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/screen.c

CMakeFiles/pong.dir/cli-lib/src/screen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pong.dir/cli-lib/src/screen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/screen.c > CMakeFiles/pong.dir/cli-lib/src/screen.c.i

CMakeFiles/pong.dir/cli-lib/src/screen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pong.dir/cli-lib/src/screen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/screen.c -o CMakeFiles/pong.dir/cli-lib/src/screen.c.s

CMakeFiles/pong.dir/cli-lib/src/timer.c.o: CMakeFiles/pong.dir/flags.make
CMakeFiles/pong.dir/cli-lib/src/timer.c.o: ../cli-lib/src/timer.c
CMakeFiles/pong.dir/cli-lib/src/timer.c.o: CMakeFiles/pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pong.dir/cli-lib/src/timer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pong.dir/cli-lib/src/timer.c.o -MF CMakeFiles/pong.dir/cli-lib/src/timer.c.o.d -o CMakeFiles/pong.dir/cli-lib/src/timer.c.o -c /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/timer.c

CMakeFiles/pong.dir/cli-lib/src/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pong.dir/cli-lib/src/timer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/timer.c > CMakeFiles/pong.dir/cli-lib/src/timer.c.i

CMakeFiles/pong.dir/cli-lib/src/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pong.dir/cli-lib/src/timer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/lisa_/ClionProjects/Pong/cli-lib/src/timer.c -o CMakeFiles/pong.dir/cli-lib/src/timer.c.s

# Object files for target pong
pong_OBJECTS = \
"CMakeFiles/pong.dir/main.c.o" \
"CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o" \
"CMakeFiles/pong.dir/cli-lib/src/screen.c.o" \
"CMakeFiles/pong.dir/cli-lib/src/timer.c.o"

# External object files for target pong
pong_EXTERNAL_OBJECTS =

pong: CMakeFiles/pong.dir/main.c.o
pong: CMakeFiles/pong.dir/cli-lib/src/keyboard.c.o
pong: CMakeFiles/pong.dir/cli-lib/src/screen.c.o
pong: CMakeFiles/pong.dir/cli-lib/src/timer.c.o
pong: CMakeFiles/pong.dir/build.make
pong: CMakeFiles/pong.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable pong"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pong.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pong.dir/build: pong
.PHONY : CMakeFiles/pong.dir/build

CMakeFiles/pong.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pong.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pong.dir/clean

CMakeFiles/pong.dir/depend:
	cd /mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/lisa_/ClionProjects/Pong /mnt/c/Users/lisa_/ClionProjects/Pong /mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug /mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug /mnt/c/Users/lisa_/ClionProjects/Pong/cmake-build-debug/CMakeFiles/pong.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pong.dir/depend

