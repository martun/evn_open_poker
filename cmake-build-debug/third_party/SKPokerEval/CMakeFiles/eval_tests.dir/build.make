# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/lev/Downloads/clion-2017.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lev/Downloads/clion-2017.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lev/Git/evn_open_poker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lev/Git/evn_open_poker/cmake-build-debug

# Include any dependencies generated for this target.
include third_party/SKPokerEval/CMakeFiles/eval_tests.dir/depend.make

# Include the progress variables for this target.
include third_party/SKPokerEval/CMakeFiles/eval_tests.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/SKPokerEval/CMakeFiles/eval_tests.dir/flags.make

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/flags.make
third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o: ../third_party/SKPokerEval/tests/five_eval_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o -c /home/lev/Git/evn_open_poker/third_party/SKPokerEval/tests/five_eval_tests.cpp

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.i"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/third_party/SKPokerEval/tests/five_eval_tests.cpp > CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.i

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.s"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/third_party/SKPokerEval/tests/five_eval_tests.cpp -o CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.s

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.requires:

.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.requires

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.provides: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.requires
	$(MAKE) -f third_party/SKPokerEval/CMakeFiles/eval_tests.dir/build.make third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.provides.build
.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.provides

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.provides.build: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o


third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/flags.make
third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o: ../third_party/SKPokerEval/tests/seven_eval_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o -c /home/lev/Git/evn_open_poker/third_party/SKPokerEval/tests/seven_eval_tests.cpp

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.i"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/third_party/SKPokerEval/tests/seven_eval_tests.cpp > CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.i

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.s"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/third_party/SKPokerEval/tests/seven_eval_tests.cpp -o CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.s

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.requires:

.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.requires

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.provides: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.requires
	$(MAKE) -f third_party/SKPokerEval/CMakeFiles/eval_tests.dir/build.make third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.provides.build
.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.provides

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.provides.build: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o


# Object files for target eval_tests
eval_tests_OBJECTS = \
"CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o" \
"CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o"

# External object files for target eval_tests
eval_tests_EXTERNAL_OBJECTS =

build/eval_tests: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o
build/eval_tests: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o
build/eval_tests: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/build.make
build/eval_tests: third_party/googletest/googletest/libgtest_maind.a
build/eval_tests: build/libskpokereval.a
build/eval_tests: third_party/googletest/googletest/libgtestd.a
build/eval_tests: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lev/Git/evn_open_poker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../build/eval_tests"
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eval_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/SKPokerEval/CMakeFiles/eval_tests.dir/build: build/eval_tests

.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/build

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/requires: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/five_eval_tests.cpp.o.requires
third_party/SKPokerEval/CMakeFiles/eval_tests.dir/requires: third_party/SKPokerEval/CMakeFiles/eval_tests.dir/tests/seven_eval_tests.cpp.o.requires

.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/requires

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/clean:
	cd /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval && $(CMAKE_COMMAND) -P CMakeFiles/eval_tests.dir/cmake_clean.cmake
.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/clean

third_party/SKPokerEval/CMakeFiles/eval_tests.dir/depend:
	cd /home/lev/Git/evn_open_poker/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lev/Git/evn_open_poker /home/lev/Git/evn_open_poker/third_party/SKPokerEval /home/lev/Git/evn_open_poker/cmake-build-debug /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval /home/lev/Git/evn_open_poker/cmake-build-debug/third_party/SKPokerEval/CMakeFiles/eval_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/SKPokerEval/CMakeFiles/eval_tests.dir/depend

