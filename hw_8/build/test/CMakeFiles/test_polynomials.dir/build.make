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
include test/CMakeFiles/test_polynomials.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_polynomials.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_polynomials.dir/flags.make

test/CMakeFiles/test_polynomials.dir/test_polynomials.cpp.o: test/CMakeFiles/test_polynomials.dir/flags.make
test/CMakeFiles/test_polynomials.dir/test_polynomials.cpp.o: ../test/test_polynomials.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nic/CS100_hw/hw_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_polynomials.dir/test_polynomials.cpp.o"
	cd /home/nic/CS100_hw/hw_8/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_polynomials.dir/test_polynomials.cpp.o -c /home/nic/CS100_hw/hw_8/test/test_polynomials.cpp

test/CMakeFiles/test_polynomials.dir/test_polynomials.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_polynomials.dir/test_polynomials.cpp.i"
	cd /home/nic/CS100_hw/hw_8/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nic/CS100_hw/hw_8/test/test_polynomials.cpp > CMakeFiles/test_polynomials.dir/test_polynomials.cpp.i

test/CMakeFiles/test_polynomials.dir/test_polynomials.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_polynomials.dir/test_polynomials.cpp.s"
	cd /home/nic/CS100_hw/hw_8/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nic/CS100_hw/hw_8/test/test_polynomials.cpp -o CMakeFiles/test_polynomials.dir/test_polynomials.cpp.s

# Object files for target test_polynomials
test_polynomials_OBJECTS = \
"CMakeFiles/test_polynomials.dir/test_polynomials.cpp.o"

# External object files for target test_polynomials
test_polynomials_EXTERNAL_OBJECTS =

test/test_polynomials: test/CMakeFiles/test_polynomials.dir/test_polynomials.cpp.o
test/test_polynomials: test/CMakeFiles/test_polynomials.dir/build.make
test/test_polynomials: test/CMakeFiles/test_polynomials.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nic/CS100_hw/hw_8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_polynomials"
	cd /home/nic/CS100_hw/hw_8/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_polynomials.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_polynomials.dir/build: test/test_polynomials

.PHONY : test/CMakeFiles/test_polynomials.dir/build

test/CMakeFiles/test_polynomials.dir/clean:
	cd /home/nic/CS100_hw/hw_8/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_polynomials.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_polynomials.dir/clean

test/CMakeFiles/test_polynomials.dir/depend:
	cd /home/nic/CS100_hw/hw_8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nic/CS100_hw/hw_8 /home/nic/CS100_hw/hw_8/test /home/nic/CS100_hw/hw_8/build /home/nic/CS100_hw/hw_8/build/test /home/nic/CS100_hw/hw_8/build/test/CMakeFiles/test_polynomials.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_polynomials.dir/depend
