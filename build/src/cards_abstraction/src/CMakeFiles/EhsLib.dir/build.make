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
CMAKE_BINARY_DIR = /home/lev/Git/evn_open_poker/build

# Include any dependencies generated for this target.
include src/cards_abstraction/src/CMakeFiles/EhsLib.dir/depend.make

# Include the progress variables for this target.
include src/cards_abstraction/src/CMakeFiles/EhsLib.dir/progress.make

# Include the compile flags for this target's objects.
include src/cards_abstraction/src/CMakeFiles/EhsLib.dir/flags.make

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/flags.make
src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o: ../src/cards_abstraction/src/ehs_lut_builder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o -c /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_builder.cpp

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.i"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_builder.cpp > CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.i

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.s"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_builder.cpp -o CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.s

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.requires:

.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.requires

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.provides: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.requires
	$(MAKE) -f src/cards_abstraction/src/CMakeFiles/EhsLib.dir/build.make src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.provides.build
.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.provides

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.provides.build: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o


src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/flags.make
src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o: ../src/cards_abstraction/src/ehs_lut_storage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o -c /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_storage.cpp

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.i"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_storage.cpp > CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.i

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.s"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_storage.cpp -o CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.s

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.requires:

.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.requires

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.provides: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.requires
	$(MAKE) -f src/cards_abstraction/src/CMakeFiles/EhsLib.dir/build.make src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.provides.build
.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.provides

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.provides.build: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o


src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/flags.make
src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o: ../src/cards_abstraction/src/ehs_lut_provider.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lev/Git/evn_open_poker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o -c /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_provider.cpp

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.i"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_provider.cpp > CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.i

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.s"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lev/Git/evn_open_poker/src/cards_abstraction/src/ehs_lut_provider.cpp -o CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.s

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.requires:

.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.requires

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.provides: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.requires
	$(MAKE) -f src/cards_abstraction/src/CMakeFiles/EhsLib.dir/build.make src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.provides.build
.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.provides

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.provides.build: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o


# Object files for target EhsLib
EhsLib_OBJECTS = \
"CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o" \
"CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o" \
"CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o"

# External object files for target EhsLib
EhsLib_EXTERNAL_OBJECTS =

src/cards_abstraction/src/libEhsLib.a: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o
src/cards_abstraction/src/libEhsLib.a: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o
src/cards_abstraction/src/libEhsLib.a: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o
src/cards_abstraction/src/libEhsLib.a: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/build.make
src/cards_abstraction/src/libEhsLib.a: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lev/Git/evn_open_poker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libEhsLib.a"
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && $(CMAKE_COMMAND) -P CMakeFiles/EhsLib.dir/cmake_clean_target.cmake
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EhsLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cards_abstraction/src/CMakeFiles/EhsLib.dir/build: src/cards_abstraction/src/libEhsLib.a

.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/build

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/requires: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_builder.cpp.o.requires
src/cards_abstraction/src/CMakeFiles/EhsLib.dir/requires: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_storage.cpp.o.requires
src/cards_abstraction/src/CMakeFiles/EhsLib.dir/requires: src/cards_abstraction/src/CMakeFiles/EhsLib.dir/ehs_lut_provider.cpp.o.requires

.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/requires

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/clean:
	cd /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src && $(CMAKE_COMMAND) -P CMakeFiles/EhsLib.dir/cmake_clean.cmake
.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/clean

src/cards_abstraction/src/CMakeFiles/EhsLib.dir/depend:
	cd /home/lev/Git/evn_open_poker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lev/Git/evn_open_poker /home/lev/Git/evn_open_poker/src/cards_abstraction/src /home/lev/Git/evn_open_poker/build /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src /home/lev/Git/evn_open_poker/build/src/cards_abstraction/src/CMakeFiles/EhsLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cards_abstraction/src/CMakeFiles/EhsLib.dir/depend

