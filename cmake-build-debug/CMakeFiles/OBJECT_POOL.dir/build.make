# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/moeed/CLionProjects/github_prjects/objectPool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OBJECT_POOL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OBJECT_POOL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OBJECT_POOL.dir/flags.make

CMakeFiles/OBJECT_POOL.dir/main.cpp.o: CMakeFiles/OBJECT_POOL.dir/flags.make
CMakeFiles/OBJECT_POOL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OBJECT_POOL.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OBJECT_POOL.dir/main.cpp.o -c /home/moeed/CLionProjects/github_prjects/objectPool/main.cpp

CMakeFiles/OBJECT_POOL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OBJECT_POOL.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moeed/CLionProjects/github_prjects/objectPool/main.cpp > CMakeFiles/OBJECT_POOL.dir/main.cpp.i

CMakeFiles/OBJECT_POOL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OBJECT_POOL.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moeed/CLionProjects/github_prjects/objectPool/main.cpp -o CMakeFiles/OBJECT_POOL.dir/main.cpp.s

# Object files for target OBJECT_POOL
OBJECT_POOL_OBJECTS = \
"CMakeFiles/OBJECT_POOL.dir/main.cpp.o"

# External object files for target OBJECT_POOL
OBJECT_POOL_EXTERNAL_OBJECTS =

OBJECT_POOL: CMakeFiles/OBJECT_POOL.dir/main.cpp.o
OBJECT_POOL: CMakeFiles/OBJECT_POOL.dir/build.make
OBJECT_POOL: CMakeFiles/OBJECT_POOL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OBJECT_POOL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OBJECT_POOL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OBJECT_POOL.dir/build: OBJECT_POOL

.PHONY : CMakeFiles/OBJECT_POOL.dir/build

CMakeFiles/OBJECT_POOL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OBJECT_POOL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OBJECT_POOL.dir/clean

CMakeFiles/OBJECT_POOL.dir/depend:
	cd /home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moeed/CLionProjects/github_prjects/objectPool /home/moeed/CLionProjects/github_prjects/objectPool /home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug /home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug /home/moeed/CLionProjects/github_prjects/objectPool/cmake-build-debug/CMakeFiles/OBJECT_POOL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OBJECT_POOL.dir/depend

