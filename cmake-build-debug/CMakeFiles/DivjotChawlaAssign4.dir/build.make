# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CLionProjects\DivjotChawlaAssign4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DivjotChawlaAssign4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DivjotChawlaAssign4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DivjotChawlaAssign4.dir/flags.make

CMakeFiles/DivjotChawlaAssign4.dir/main.c.obj: CMakeFiles/DivjotChawlaAssign4.dir/flags.make
CMakeFiles/DivjotChawlaAssign4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DivjotChawlaAssign4.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DivjotChawlaAssign4.dir\main.c.obj   -c C:\CLionProjects\DivjotChawlaAssign4\main.c

CMakeFiles/DivjotChawlaAssign4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DivjotChawlaAssign4.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\CLionProjects\DivjotChawlaAssign4\main.c > CMakeFiles\DivjotChawlaAssign4.dir\main.c.i

CMakeFiles/DivjotChawlaAssign4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DivjotChawlaAssign4.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\CLionProjects\DivjotChawlaAssign4\main.c -o CMakeFiles\DivjotChawlaAssign4.dir\main.c.s

CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.obj: CMakeFiles/DivjotChawlaAssign4.dir/flags.make
CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.obj: ../BinaryST.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DivjotChawlaAssign4.dir\BinaryST.c.obj   -c C:\CLionProjects\DivjotChawlaAssign4\BinaryST.c

CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\CLionProjects\DivjotChawlaAssign4\BinaryST.c > CMakeFiles\DivjotChawlaAssign4.dir\BinaryST.c.i

CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\CLionProjects\DivjotChawlaAssign4\BinaryST.c -o CMakeFiles\DivjotChawlaAssign4.dir\BinaryST.c.s

# Object files for target DivjotChawlaAssign4
DivjotChawlaAssign4_OBJECTS = \
"CMakeFiles/DivjotChawlaAssign4.dir/main.c.obj" \
"CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.obj"

# External object files for target DivjotChawlaAssign4
DivjotChawlaAssign4_EXTERNAL_OBJECTS =

DivjotChawlaAssign4.exe: CMakeFiles/DivjotChawlaAssign4.dir/main.c.obj
DivjotChawlaAssign4.exe: CMakeFiles/DivjotChawlaAssign4.dir/BinaryST.c.obj
DivjotChawlaAssign4.exe: CMakeFiles/DivjotChawlaAssign4.dir/build.make
DivjotChawlaAssign4.exe: CMakeFiles/DivjotChawlaAssign4.dir/linklibs.rsp
DivjotChawlaAssign4.exe: CMakeFiles/DivjotChawlaAssign4.dir/objects1.rsp
DivjotChawlaAssign4.exe: CMakeFiles/DivjotChawlaAssign4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable DivjotChawlaAssign4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DivjotChawlaAssign4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DivjotChawlaAssign4.dir/build: DivjotChawlaAssign4.exe

.PHONY : CMakeFiles/DivjotChawlaAssign4.dir/build

CMakeFiles/DivjotChawlaAssign4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DivjotChawlaAssign4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DivjotChawlaAssign4.dir/clean

CMakeFiles/DivjotChawlaAssign4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CLionProjects\DivjotChawlaAssign4 C:\CLionProjects\DivjotChawlaAssign4 C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug C:\CLionProjects\DivjotChawlaAssign4\cmake-build-debug\CMakeFiles\DivjotChawlaAssign4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DivjotChawlaAssign4.dir/depend

