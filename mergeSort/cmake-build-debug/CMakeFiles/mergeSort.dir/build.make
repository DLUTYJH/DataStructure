# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/answer/CLionProjects/mergeSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/answer/CLionProjects/mergeSort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mergeSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mergeSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mergeSort.dir/flags.make

CMakeFiles/mergeSort.dir/main.cpp.o: CMakeFiles/mergeSort.dir/flags.make
CMakeFiles/mergeSort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/answer/CLionProjects/mergeSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mergeSort.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mergeSort.dir/main.cpp.o -c /home/answer/CLionProjects/mergeSort/main.cpp

CMakeFiles/mergeSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mergeSort.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/answer/CLionProjects/mergeSort/main.cpp > CMakeFiles/mergeSort.dir/main.cpp.i

CMakeFiles/mergeSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mergeSort.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/answer/CLionProjects/mergeSort/main.cpp -o CMakeFiles/mergeSort.dir/main.cpp.s

CMakeFiles/mergeSort.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/mergeSort.dir/main.cpp.o.requires

CMakeFiles/mergeSort.dir/main.cpp.o.provides: CMakeFiles/mergeSort.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/mergeSort.dir/build.make CMakeFiles/mergeSort.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/mergeSort.dir/main.cpp.o.provides

CMakeFiles/mergeSort.dir/main.cpp.o.provides.build: CMakeFiles/mergeSort.dir/main.cpp.o


# Object files for target mergeSort
mergeSort_OBJECTS = \
"CMakeFiles/mergeSort.dir/main.cpp.o"

# External object files for target mergeSort
mergeSort_EXTERNAL_OBJECTS =

mergeSort: CMakeFiles/mergeSort.dir/main.cpp.o
mergeSort: CMakeFiles/mergeSort.dir/build.make
mergeSort: CMakeFiles/mergeSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/answer/CLionProjects/mergeSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mergeSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mergeSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mergeSort.dir/build: mergeSort

.PHONY : CMakeFiles/mergeSort.dir/build

CMakeFiles/mergeSort.dir/requires: CMakeFiles/mergeSort.dir/main.cpp.o.requires

.PHONY : CMakeFiles/mergeSort.dir/requires

CMakeFiles/mergeSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mergeSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mergeSort.dir/clean

CMakeFiles/mergeSort.dir/depend:
	cd /home/answer/CLionProjects/mergeSort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/answer/CLionProjects/mergeSort /home/answer/CLionProjects/mergeSort /home/answer/CLionProjects/mergeSort/cmake-build-debug /home/answer/CLionProjects/mergeSort/cmake-build-debug /home/answer/CLionProjects/mergeSort/cmake-build-debug/CMakeFiles/mergeSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mergeSort.dir/depend

