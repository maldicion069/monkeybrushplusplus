# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crodriguez/Desktop/monkeybrushplusplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crodriguez/Desktop/monkeybrushplusplus/build2

# Utility rule file for cpplint_run_mbMoreCubes.

# Include the progress variables for this target.
include examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/progress.make

examples/CMakeFiles/cpplint_run_mbMoreCubes:
	cd /home/crodriguez/Desktop/monkeybrushplusplus && /home/crodriguez/Desktop/monkeybrushplusplus/CMake/common/util/cpplint.py --filter=+build,+legal,+readability,+runtime,+whitespace,-readability/streams /home/crodriguez/Desktop/monkeybrushplusplus/examples/moreCubes.cpp

cpplint_run_mbMoreCubes: examples/CMakeFiles/cpplint_run_mbMoreCubes
cpplint_run_mbMoreCubes: examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/build.make

.PHONY : cpplint_run_mbMoreCubes

# Rule to build all files generated by this target.
examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/build: cpplint_run_mbMoreCubes

.PHONY : examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/build

examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/clean:
	cd /home/crodriguez/Desktop/monkeybrushplusplus/build2/examples && $(CMAKE_COMMAND) -P CMakeFiles/cpplint_run_mbMoreCubes.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/clean

examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/depend:
	cd /home/crodriguez/Desktop/monkeybrushplusplus/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crodriguez/Desktop/monkeybrushplusplus /home/crodriguez/Desktop/monkeybrushplusplus/examples /home/crodriguez/Desktop/monkeybrushplusplus/build2 /home/crodriguez/Desktop/monkeybrushplusplus/build2/examples /home/crodriguez/Desktop/monkeybrushplusplus/build2/examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/cpplint_run_mbMoreCubes.dir/depend
