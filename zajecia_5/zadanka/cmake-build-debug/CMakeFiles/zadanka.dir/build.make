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
CMAKE_SOURCE_DIR = "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/zadanka.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zadanka.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zadanka.dir/flags.make

CMakeFiles/zadanka.dir/paint.c.obj: CMakeFiles/zadanka.dir/flags.make
CMakeFiles/zadanka.dir/paint.c.obj: ../paint.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zadanka.dir/paint.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zadanka.dir\paint.c.obj   -c "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\paint.c"

CMakeFiles/zadanka.dir/paint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zadanka.dir/paint.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\paint.c" > CMakeFiles\zadanka.dir\paint.c.i

CMakeFiles/zadanka.dir/paint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zadanka.dir/paint.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\paint.c" -o CMakeFiles\zadanka.dir\paint.c.s

# Object files for target zadanka
zadanka_OBJECTS = \
"CMakeFiles/zadanka.dir/paint.c.obj"

# External object files for target zadanka
zadanka_EXTERNAL_OBJECTS =

zadanka.exe: CMakeFiles/zadanka.dir/paint.c.obj
zadanka.exe: CMakeFiles/zadanka.dir/build.make
zadanka.exe: CMakeFiles/zadanka.dir/linklibs.rsp
zadanka.exe: CMakeFiles/zadanka.dir/objects1.rsp
zadanka.exe: CMakeFiles/zadanka.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zadanka.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zadanka.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zadanka.dir/build: zadanka.exe

.PHONY : CMakeFiles/zadanka.dir/build

CMakeFiles/zadanka.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zadanka.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zadanka.dir/clean

CMakeFiles/zadanka.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka" "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka" "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\cmake-build-debug" "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\cmake-build-debug" "C:\Users\admin\Documents\Studia\Semestr II\PI\zajecia_5\zadanka\cmake-build-debug\CMakeFiles\zadanka.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zadanka.dir/depend

