# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wsy/ospp/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsy/ospp/test

# Include any dependencies generated for this target.
include CMakeFiles/pb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pb.dir/flags.make

CMakeFiles/pb.dir/pb.c.o: CMakeFiles/pb.dir/flags.make
CMakeFiles/pb.dir/pb.c.o: pb.c
CMakeFiles/pb.dir/pb.c.o: CMakeFiles/pb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsy/ospp/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pb.dir/pb.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pb.dir/pb.c.o -MF CMakeFiles/pb.dir/pb.c.o.d -o CMakeFiles/pb.dir/pb.c.o -c /home/wsy/ospp/test/pb.c

CMakeFiles/pb.dir/pb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pb.dir/pb.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wsy/ospp/test/pb.c > CMakeFiles/pb.dir/pb.c.i

CMakeFiles/pb.dir/pb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pb.dir/pb.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wsy/ospp/test/pb.c -o CMakeFiles/pb.dir/pb.c.s

# Object files for target pb
pb_OBJECTS = \
"CMakeFiles/pb.dir/pb.c.o"

# External object files for target pb
pb_EXTERNAL_OBJECTS =

pb: CMakeFiles/pb.dir/pb.c.o
pb: CMakeFiles/pb.dir/build.make
pb: CMakeFiles/pb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsy/ospp/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pb.dir/build: pb
.PHONY : CMakeFiles/pb.dir/build

CMakeFiles/pb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pb.dir/clean

CMakeFiles/pb.dir/depend:
	cd /home/wsy/ospp/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsy/ospp/test /home/wsy/ospp/test /home/wsy/ospp/test /home/wsy/ospp/test /home/wsy/ospp/test/CMakeFiles/pb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pb.dir/depend
