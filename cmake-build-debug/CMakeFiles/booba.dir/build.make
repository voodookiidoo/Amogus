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
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sage/CLionProjects/booba

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sage/CLionProjects/booba/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/booba.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/booba.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/booba.dir/flags.make

CMakeFiles/booba.dir/main.cpp.o: CMakeFiles/booba.dir/flags.make
CMakeFiles/booba.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sage/CLionProjects/booba/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/booba.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/booba.dir/main.cpp.o -c /home/sage/CLionProjects/booba/main.cpp

CMakeFiles/booba.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/booba.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sage/CLionProjects/booba/main.cpp > CMakeFiles/booba.dir/main.cpp.i

CMakeFiles/booba.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/booba.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sage/CLionProjects/booba/main.cpp -o CMakeFiles/booba.dir/main.cpp.s

# Object files for target booba
booba_OBJECTS = \
"CMakeFiles/booba.dir/main.cpp.o"

# External object files for target booba
booba_EXTERNAL_OBJECTS =

booba: CMakeFiles/booba.dir/main.cpp.o
booba: CMakeFiles/booba.dir/build.make
booba: CMakeFiles/booba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sage/CLionProjects/booba/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable booba"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/booba.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/booba.dir/build: booba
.PHONY : CMakeFiles/booba.dir/build

CMakeFiles/booba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/booba.dir/cmake_clean.cmake
.PHONY : CMakeFiles/booba.dir/clean

CMakeFiles/booba.dir/depend:
	cd /home/sage/CLionProjects/booba/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sage/CLionProjects/booba /home/sage/CLionProjects/booba /home/sage/CLionProjects/booba/cmake-build-debug /home/sage/CLionProjects/booba/cmake-build-debug /home/sage/CLionProjects/booba/cmake-build-debug/CMakeFiles/booba.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/booba.dir/depend

