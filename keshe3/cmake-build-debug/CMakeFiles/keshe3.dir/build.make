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
CMAKE_COMMAND = "E:\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\github_repository\525\525Repository\keshe3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\github_repository\525\525Repository\keshe3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/keshe3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/keshe3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/keshe3.dir/flags.make

CMakeFiles/keshe3.dir/main.c.obj: CMakeFiles/keshe3.dir/flags.make
CMakeFiles/keshe3.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\github_repository\525\525Repository\keshe3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/keshe3.dir/main.c.obj"
	E:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\keshe3.dir\main.c.obj   -c E:\github_repository\525\525Repository\keshe3\main.c

CMakeFiles/keshe3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/keshe3.dir/main.c.i"
	E:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\github_repository\525\525Repository\keshe3\main.c > CMakeFiles\keshe3.dir\main.c.i

CMakeFiles/keshe3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/keshe3.dir/main.c.s"
	E:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\github_repository\525\525Repository\keshe3\main.c -o CMakeFiles\keshe3.dir\main.c.s

# Object files for target keshe3
keshe3_OBJECTS = \
"CMakeFiles/keshe3.dir/main.c.obj"

# External object files for target keshe3
keshe3_EXTERNAL_OBJECTS =

keshe3.exe: CMakeFiles/keshe3.dir/main.c.obj
keshe3.exe: CMakeFiles/keshe3.dir/build.make
keshe3.exe: CMakeFiles/keshe3.dir/linklibs.rsp
keshe3.exe: CMakeFiles/keshe3.dir/objects1.rsp
keshe3.exe: CMakeFiles/keshe3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\github_repository\525\525Repository\keshe3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable keshe3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\keshe3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/keshe3.dir/build: keshe3.exe

.PHONY : CMakeFiles/keshe3.dir/build

CMakeFiles/keshe3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\keshe3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/keshe3.dir/clean

CMakeFiles/keshe3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\github_repository\525\525Repository\keshe3 E:\github_repository\525\525Repository\keshe3 E:\github_repository\525\525Repository\keshe3\cmake-build-debug E:\github_repository\525\525Repository\keshe3\cmake-build-debug E:\github_repository\525\525Repository\keshe3\cmake-build-debug\CMakeFiles\keshe3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/keshe3.dir/depend

