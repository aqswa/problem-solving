# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\LG\CLionProjects\algorithm\DP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\LG\CLionProjects\algorithm\DP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DP.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/DP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DP.dir/flags.make

CMakeFiles/DP.dir/1446.cpp.obj: CMakeFiles/DP.dir/flags.make
CMakeFiles/DP.dir/1446.cpp.obj: ../1446.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LG\CLionProjects\algorithm\DP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DP.dir/1446.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DP.dir\1446.cpp.obj -c C:\Users\LG\CLionProjects\algorithm\DP\1446.cpp

CMakeFiles/DP.dir/1446.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DP.dir/1446.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LG\CLionProjects\algorithm\DP\1446.cpp > CMakeFiles\DP.dir\1446.cpp.i

CMakeFiles/DP.dir/1446.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DP.dir/1446.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\LG\CLionProjects\algorithm\DP\1446.cpp -o CMakeFiles\DP.dir\1446.cpp.s

# Object files for target DP
DP_OBJECTS = \
"CMakeFiles/DP.dir/1446.cpp.obj"

# External object files for target DP
DP_EXTERNAL_OBJECTS =

DP.exe: CMakeFiles/DP.dir/1446.cpp.obj
DP.exe: CMakeFiles/DP.dir/build.make
DP.exe: CMakeFiles/DP.dir/linklibs.rsp
DP.exe: CMakeFiles/DP.dir/objects1.rsp
DP.exe: CMakeFiles/DP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\LG\CLionProjects\algorithm\DP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DP.dir/build: DP.exe
.PHONY : CMakeFiles/DP.dir/build

CMakeFiles/DP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DP.dir/clean

CMakeFiles/DP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\LG\CLionProjects\algorithm\DP C:\Users\LG\CLionProjects\algorithm\DP C:\Users\LG\CLionProjects\algorithm\DP\cmake-build-debug C:\Users\LG\CLionProjects\algorithm\DP\cmake-build-debug C:\Users\LG\CLionProjects\algorithm\DP\cmake-build-debug\CMakeFiles\DP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DP.dir/depend

