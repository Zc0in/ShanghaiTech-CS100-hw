# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/nic/CS100_hw/hw_8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nic/CS100_hw/hw_8/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_newton.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_newton.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_newton.dir/flags.make

test/CMakeFiles/test_newton.dir/test_newton.cpp.o: test/CMakeFiles/test_newton.dir/flags.make
test/CMakeFiles/test_newton.dir/test_newton.cpp.o: ../test/test_newton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nic/CS100_hw/hw_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_newton.dir/test_newton.cpp.o"
	cd /home/nic/CS100_hw/hw_8/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_newton.dir/test_newton.cpp.o -c /home/nic/CS100_hw/hw_8/test/test_newton.cpp

test/CMakeFiles/test_newton.dir/test_newton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_newton.dir/test_newton.cpp.i"
	cd /home/nic/CS100_hw/hw_8/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nic/CS100_hw/hw_8/test/test_newton.cpp > CMakeFiles/test_newton.dir/test_newton.cpp.i

test/CMakeFiles/test_newton.dir/test_newton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_newton.dir/test_newton.cpp.s"
	cd /home/nic/CS100_hw/hw_8/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nic/CS100_hw/hw_8/test/test_newton.cpp -o CMakeFiles/test_newton.dir/test_newton.cpp.s

# Object files for target test_newton
test_newton_OBJECTS = \
"CMakeFiles/test_newton.dir/test_newton.cpp.o"

# External object files for target test_newton
test_newton_EXTERNAL_OBJECTS =

test/test_newton: test/CMakeFiles/test_newton.dir/test_newton.cpp.o
test/test_newton: test/CMakeFiles/test_newton.dir/build.make
test/test_newton: test/CMakeFiles/test_newton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nic/CS100_hw/hw_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_newton"
	cd /home/nic/CS100_hw/hw_8/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_newton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_newton.dir/build: test/test_newton

.PHONY : test/CMakeFiles/test_newton.dir/build

test/CMakeFiles/test_newton.dir/clean:
	cd /home/nic/CS100_hw/hw_8/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_newton.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_newton.dir/clean

test/CMakeFiles/test_newton.dir/depend:
	cd /home/nic/CS100_hw/hw_8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nic/CS100_hw/hw_8 /home/nic/CS100_hw/hw_8/test /home/nic/CS100_hw/hw_8/build /home/nic/CS100_hw/hw_8/build/test /home/nic/CS100_hw/hw_8/build/test/CMakeFiles/test_newton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_newton.dir/depend

