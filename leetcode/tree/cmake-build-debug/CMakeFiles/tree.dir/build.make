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
CMAKE_COMMAND = "D:\JetBrains\Clion 2020\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\Clion 2020\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Clion_Progects\tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Clion_Progects\tree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/main.cpp.obj: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Clion_Progects\tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree.dir/main.cpp.obj"
	D:\PROGRA~2\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tree.dir\main.cpp.obj -c F:\Clion_Progects\tree\main.cpp

CMakeFiles/tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/main.cpp.i"
	D:\PROGRA~2\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Clion_Progects\tree\main.cpp > CMakeFiles\tree.dir\main.cpp.i

CMakeFiles/tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/main.cpp.s"
	D:\PROGRA~2\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Clion_Progects\tree\main.cpp -o CMakeFiles\tree.dir\main.cpp.s

CMakeFiles/tree.dir/BFS.cpp.obj: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/BFS.cpp.obj: ../BFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Clion_Progects\tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tree.dir/BFS.cpp.obj"
	D:\PROGRA~2\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tree.dir\BFS.cpp.obj -c F:\Clion_Progects\tree\BFS.cpp

CMakeFiles/tree.dir/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/BFS.cpp.i"
	D:\PROGRA~2\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Clion_Progects\tree\BFS.cpp > CMakeFiles\tree.dir\BFS.cpp.i

CMakeFiles/tree.dir/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/BFS.cpp.s"
	D:\PROGRA~2\MINGW-~1\X86_64~1.0-R\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Clion_Progects\tree\BFS.cpp -o CMakeFiles\tree.dir\BFS.cpp.s

# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/main.cpp.obj" \
"CMakeFiles/tree.dir/BFS.cpp.obj"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

tree.exe: CMakeFiles/tree.dir/main.cpp.obj
tree.exe: CMakeFiles/tree.dir/BFS.cpp.obj
tree.exe: CMakeFiles/tree.dir/build.make
tree.exe: CMakeFiles/tree.dir/linklibs.rsp
tree.exe: CMakeFiles/tree.dir/objects1.rsp
tree.exe: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Clion_Progects\tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: tree.exe

.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Clion_Progects\tree F:\Clion_Progects\tree F:\Clion_Progects\tree\cmake-build-debug F:\Clion_Progects\tree\cmake-build-debug F:\Clion_Progects\tree\cmake-build-debug\CMakeFiles\tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend

