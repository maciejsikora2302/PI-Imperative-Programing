# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/zajecia_8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zajecia_8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zajecia_8.dir/flags.make

CMakeFiles/zajecia_8.dir/lin.cpp.obj: CMakeFiles/zajecia_8.dir/flags.make
CMakeFiles/zajecia_8.dir/lin.cpp.obj: ../lin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zajecia_8.dir/lin.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zajecia_8.dir\lin.cpp.obj -c "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\lin.cpp"

CMakeFiles/zajecia_8.dir/lin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zajecia_8.dir/lin.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\lin.cpp" > CMakeFiles\zajecia_8.dir\lin.cpp.i

CMakeFiles/zajecia_8.dir/lin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zajecia_8.dir/lin.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\lin.cpp" -o CMakeFiles\zajecia_8.dir\lin.cpp.s

# Object files for target zajecia_8
zajecia_8_OBJECTS = \
"CMakeFiles/zajecia_8.dir/lin.cpp.obj"

# External object files for target zajecia_8
zajecia_8_EXTERNAL_OBJECTS =

zajecia_8.exe: CMakeFiles/zajecia_8.dir/lin.cpp.obj
zajecia_8.exe: CMakeFiles/zajecia_8.dir/build.make
zajecia_8.exe: CMakeFiles/zajecia_8.dir/linklibs.rsp
zajecia_8.exe: CMakeFiles/zajecia_8.dir/objects1.rsp
zajecia_8.exe: CMakeFiles/zajecia_8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zajecia_8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zajecia_8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zajecia_8.dir/build: zajecia_8.exe

.PHONY : CMakeFiles/zajecia_8.dir/build

CMakeFiles/zajecia_8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zajecia_8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zajecia_8.dir/clean

CMakeFiles/zajecia_8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8" "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8" "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\cmake-build-debug" "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\cmake-build-debug" "C:\Users\admin\Documents\Studia\Semestr II\Git\PI-Imperative-Programing-\zajecia_8\cmake-build-debug\CMakeFiles\zajecia_8.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zajecia_8.dir/depend

