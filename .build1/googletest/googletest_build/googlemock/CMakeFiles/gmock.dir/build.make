# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/evgenijtinkaluk/github/baseex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evgenijtinkaluk/github/baseex/.build1

# Include any dependencies generated for this target.
include googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/flags.make

googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/flags.make
googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest/googletest_src/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_src/googlemock/src/gmock-all.cc

googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_src/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_src/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmock.a: googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgmock.a"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a

.PHONY : googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/build

googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/clean:
	cd /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/clean

googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/depend:
	cd /Users/evgenijtinkaluk/github/baseex/.build1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenijtinkaluk/github/baseex /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_src/googlemock /Users/evgenijtinkaluk/github/baseex/.build1 /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock /Users/evgenijtinkaluk/github/baseex/.build1/googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/googletest_build/googlemock/CMakeFiles/gmock.dir/depend

