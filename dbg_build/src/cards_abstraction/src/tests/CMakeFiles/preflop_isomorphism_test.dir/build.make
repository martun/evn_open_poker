# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lev/Git/evn_open_poker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lev/Git/evn_open_poker/dbg_build

# Include any dependencies generated for this target.
include src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/depend.make

# Include the progress variables for this target.
include src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/flags.make

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/flags.make
src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o: ../src/cards_abstraction/src/tests/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/dbg_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o -c /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests/test_main.cpp

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.i"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests/test_main.cpp > CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.i

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.s"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests/test_main.cpp -o CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.s

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.requires:

.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.requires

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.provides: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.requires
	$(MAKE) -f src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/build.make src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.provides.build
.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.provides

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.provides.build: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o


src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/flags.make
src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o: ../src/cards_abstraction/src/tests/preflop_isomorphism_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/dbg_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o -c /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests/preflop_isomorphism_test.cpp

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.i"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests/preflop_isomorphism_test.cpp > CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.i

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.s"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests/preflop_isomorphism_test.cpp -o CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.s

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.requires:

.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.requires

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.provides: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.requires
	$(MAKE) -f src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/build.make src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.provides.build
.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.provides

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.provides.build: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o


# Object files for target preflop_isomorphism_test
preflop_isomorphism_test_OBJECTS = \
"CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o" \
"CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o"

# External object files for target preflop_isomorphism_test
preflop_isomorphism_test_EXTERNAL_OBJECTS =

src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o
src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o
src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/build.make
src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/libBucketingLib.a
src/cards_abstraction/src/tests/preflop_isomorphism_test: third_party/googletest/googletest/libgtestd.a
src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/libEhsLib.a
src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/libIsomorphismLib.a
src/cards_abstraction/src/tests/preflop_isomorphism_test: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lev/Git/evn_open_poker/dbg_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable preflop_isomorphism_test"
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/preflop_isomorphism_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/build: src/cards_abstraction/src/tests/preflop_isomorphism_test

.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/build

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/requires: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/test_main.cpp.o.requires
src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/requires: src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/preflop_isomorphism_test.cpp.o.requires

.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/requires

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/clean:
	cd /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/preflop_isomorphism_test.dir/cmake_clean.cmake
.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/clean

src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/depend:
	cd /home/lev/Git/evn_open_poker/dbg_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lev/Git/evn_open_poker /home/lev/Git/evn_open_poker/src/cards_abstraction/src/tests /home/lev/Git/evn_open_poker/dbg_build /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests /home/lev/Git/evn_open_poker/dbg_build/src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cards_abstraction/src/tests/CMakeFiles/preflop_isomorphism_test.dir/depend

