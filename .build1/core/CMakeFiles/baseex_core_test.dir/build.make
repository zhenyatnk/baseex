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
include core/CMakeFiles/baseex_core_test.dir/depend.make

# Include the progress variables for this target.
include core/CMakeFiles/baseex_core_test.dir/progress.make

# Include the compile flags for this target's objects.
include core/CMakeFiles/baseex_core_test.dir/flags.make

core/CMakeFiles/baseex_core_test.dir/test/main.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/main.cpp.o: ../core/test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/main.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/main.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/main.cpp

core/CMakeFiles/baseex_core_test.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/main.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/main.cpp > CMakeFiles/baseex_core_test.dir/test/main.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/main.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/main.cpp -o CMakeFiles/baseex_core_test.dir/test/main.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.o: ../core/test/CFileName_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CFileName_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CFileName_test.cpp > CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CFileName_test.cpp -o CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.o: ../core/test/CIteratorBase_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CIteratorBase_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CIteratorBase_test.cpp > CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CIteratorBase_test.cpp -o CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.o: ../core/test/CPathName_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CPathName_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CPathName_test.cpp > CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CPathName_test.cpp -o CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.o: ../core/test/CIteratorStream_testEx.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CIteratorStream_testEx.cpp

core/CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CIteratorStream_testEx.cpp > CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CIteratorStream_testEx.cpp -o CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.o: ../core/test/CRAII_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CRAII_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CRAII_test.cpp > CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CRAII_test.cpp -o CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.o: ../core/test/CTimerActive_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CTimerActive_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CTimerActive_test.cpp > CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CTimerActive_test.cpp -o CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.o: ../core/test/CTimerPassive_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/CTimerPassive_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/CTimerPassive_test.cpp > CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/CTimerPassive_test.cpp -o CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.o: ../core/test/StreamFile_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/StreamFile_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/StreamFile_test.cpp > CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/StreamFile_test.cpp -o CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.o: ../core/test/StreamBuffer_testEx.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/StreamBuffer_testEx.cpp

core/CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/StreamBuffer_testEx.cpp > CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/StreamBuffer_testEx.cpp -o CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.o: ../core/test/TLocking_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/TLocking_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/TLocking_test.cpp > CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/TLocking_test.cpp -o CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.o: ../core/test/TLockingForce_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/TLockingForce_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/TLockingForce_test.cpp > CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/TLockingForce_test.cpp -o CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.o: ../core/test/TLockingShared_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/TLockingShared_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/TLockingShared_test.cpp > CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/TLockingShared_test.cpp -o CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.o: ../core/test/TNotifier_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/TNotifier_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/TNotifier_test.cpp > CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/TNotifier_test.cpp -o CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.o: ../core/test/TSingleton_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/TSingleton_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/TSingleton_test.cpp > CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/TSingleton_test.cpp -o CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.s

core/CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.o: core/CMakeFiles/baseex_core_test.dir/flags.make
core/CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.o: ../core/test/Unicode_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object core/CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.o"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.o -c /Users/evgenijtinkaluk/github/baseex/core/test/Unicode_test.cpp

core/CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.i"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijtinkaluk/github/baseex/core/test/Unicode_test.cpp > CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.i

core/CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.s"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijtinkaluk/github/baseex/core/test/Unicode_test.cpp -o CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.s

# Object files for target baseex_core_test
baseex_core_test_OBJECTS = \
"CMakeFiles/baseex_core_test.dir/test/main.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.o" \
"CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.o"

# External object files for target baseex_core_test
baseex_core_test_EXTERNAL_OBJECTS =

bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/main.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CFileName_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CIteratorBase_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CPathName_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CIteratorStream_testEx.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CRAII_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CTimerActive_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/CTimerPassive_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/StreamFile_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/StreamBuffer_testEx.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/TLocking_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/TLockingForce_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/TLockingShared_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/TNotifier_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/TSingleton_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/test/Unicode_test.cpp.o
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/build.make
bin/baseex_core_test: lib/libbaseex_core.a
bin/baseex_core_test: lib/libgmock.a
bin/baseex_core_test: lib/libgtest.a
bin/baseex_core_test: core/CMakeFiles/baseex_core_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenijtinkaluk/github/baseex/.build1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable ../bin/baseex_core_test"
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/baseex_core_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/CMakeFiles/baseex_core_test.dir/build: bin/baseex_core_test

.PHONY : core/CMakeFiles/baseex_core_test.dir/build

core/CMakeFiles/baseex_core_test.dir/clean:
	cd /Users/evgenijtinkaluk/github/baseex/.build1/core && $(CMAKE_COMMAND) -P CMakeFiles/baseex_core_test.dir/cmake_clean.cmake
.PHONY : core/CMakeFiles/baseex_core_test.dir/clean

core/CMakeFiles/baseex_core_test.dir/depend:
	cd /Users/evgenijtinkaluk/github/baseex/.build1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenijtinkaluk/github/baseex /Users/evgenijtinkaluk/github/baseex/core /Users/evgenijtinkaluk/github/baseex/.build1 /Users/evgenijtinkaluk/github/baseex/.build1/core /Users/evgenijtinkaluk/github/baseex/.build1/core/CMakeFiles/baseex_core_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/CMakeFiles/baseex_core_test.dir/depend

