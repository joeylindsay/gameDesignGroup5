# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hylan\CLionProjects\gameDesignGroup5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hylan\CLionProjects\gameDesignGroup5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/bin/game.cpp.obj: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/bin/game.cpp.obj: CMakeFiles/game.dir/includes_CXX.rsp
CMakeFiles/game.dir/bin/game.cpp.obj: ../bin/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hylan\CLionProjects\gameDesignGroup5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/bin/game.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\game.dir\bin\game.cpp.obj -c C:\Users\hylan\CLionProjects\gameDesignGroup5\bin\game.cpp

CMakeFiles/game.dir/bin/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/bin/game.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hylan\CLionProjects\gameDesignGroup5\bin\game.cpp > CMakeFiles\game.dir\bin\game.cpp.i

CMakeFiles/game.dir/bin/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/bin/game.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hylan\CLionProjects\gameDesignGroup5\bin\game.cpp -o CMakeFiles\game.dir\bin\game.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/bin/game.cpp.obj"

# External object files for target game
game_EXTERNAL_OBJECTS =

game.exe: CMakeFiles/game.dir/bin/game.cpp.obj
game.exe: CMakeFiles/game.dir/build.make
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-graphics-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-window-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-system-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-audio-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-network-d.a
game.exe: libgameDesignGroup5_core.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-graphics-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-window-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-system-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-audio-d.a
game.exe: C:/Users/hylan/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-network-d.a
game.exe: CMakeFiles/game.dir/linklibs.rsp
game.exe: CMakeFiles/game.dir/objects1.rsp
game.exe: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hylan\CLionProjects\gameDesignGroup5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game.exe

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hylan\CLionProjects\gameDesignGroup5 C:\Users\hylan\CLionProjects\gameDesignGroup5 C:\Users\hylan\CLionProjects\gameDesignGroup5\cmake-build-debug C:\Users\hylan\CLionProjects\gameDesignGroup5\cmake-build-debug C:\Users\hylan\CLionProjects\gameDesignGroup5\cmake-build-debug\CMakeFiles\game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

