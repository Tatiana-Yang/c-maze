# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projet.dir/flags.make

CMakeFiles/projet.dir/main.c.obj: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projet.dir/main.c.obj"
	C:\Haskell\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projet.dir\main.c.obj   -c C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\main.c

CMakeFiles/projet.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/main.c.i"
	C:\Haskell\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\main.c > CMakeFiles\projet.dir\main.c.i

CMakeFiles/projet.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/main.c.s"
	C:\Haskell\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\main.c -o CMakeFiles\projet.dir\main.c.s

CMakeFiles/projet.dir/creation_labyrinth.c.obj: CMakeFiles/projet.dir/flags.make
CMakeFiles/projet.dir/creation_labyrinth.c.obj: ../creation_labyrinth.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projet.dir/creation_labyrinth.c.obj"
	C:\Haskell\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projet.dir\creation_labyrinth.c.obj   -c C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\creation_labyrinth.c

CMakeFiles/projet.dir/creation_labyrinth.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet.dir/creation_labyrinth.c.i"
	C:\Haskell\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\creation_labyrinth.c > CMakeFiles\projet.dir\creation_labyrinth.c.i

CMakeFiles/projet.dir/creation_labyrinth.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet.dir/creation_labyrinth.c.s"
	C:\Haskell\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\creation_labyrinth.c -o CMakeFiles\projet.dir\creation_labyrinth.c.s

# Object files for target projet
projet_OBJECTS = \
"CMakeFiles/projet.dir/main.c.obj" \
"CMakeFiles/projet.dir/creation_labyrinth.c.obj"

# External object files for target projet
projet_EXTERNAL_OBJECTS =

projet.exe: CMakeFiles/projet.dir/main.c.obj
projet.exe: CMakeFiles/projet.dir/creation_labyrinth.c.obj
projet.exe: CMakeFiles/projet.dir/build.make
projet.exe: CMakeFiles/projet.dir/linklibs.rsp
projet.exe: CMakeFiles/projet.dir/objects1.rsp
projet.exe: CMakeFiles/projet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable projet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\projet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projet.dir/build: projet.exe

.PHONY : CMakeFiles/projet.dir/build

CMakeFiles/projet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\projet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/projet.dir/clean

CMakeFiles/projet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug C:\Users\asus\Documents\COURS\ENSICAEN\1A\INTRO\projet\cmake-build-debug\CMakeFiles\projet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projet.dir/depend

