# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Mayank Sharma\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Mayank Sharma\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mayank Sharma\CLionProjects\Linkedlist"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Linkedlist.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Linkedlist.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Linkedlist.dir\flags.make

CMakeFiles\Linkedlist.dir\main.cpp.obj: CMakeFiles\Linkedlist.dir\flags.make
CMakeFiles\Linkedlist.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Linkedlist.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Linkedlist.dir\main.cpp.obj /FdCMakeFiles\Linkedlist.dir\ /FS -c "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\main.cpp"
<<

CMakeFiles\Linkedlist.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Linkedlist.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\Linkedlist.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\main.cpp"
<<

CMakeFiles\Linkedlist.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Linkedlist.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Linkedlist.dir\main.cpp.s /c "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\main.cpp"
<<

# Object files for target Linkedlist
Linkedlist_OBJECTS = \
"CMakeFiles\Linkedlist.dir\main.cpp.obj"

# External object files for target Linkedlist
Linkedlist_EXTERNAL_OBJECTS =

Linkedlist.exe: CMakeFiles\Linkedlist.dir\main.cpp.obj
Linkedlist.exe: CMakeFiles\Linkedlist.dir\build.make
Linkedlist.exe: CMakeFiles\Linkedlist.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Linkedlist.exe"
	"C:\Users\Mayank Sharma\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6494.38\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Linkedlist.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Linkedlist.dir\objects1.rsp @<<
 /out:Linkedlist.exe /implib:Linkedlist.lib /pdb:"C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug\Linkedlist.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Linkedlist.dir\build: Linkedlist.exe

.PHONY : CMakeFiles\Linkedlist.dir\build

CMakeFiles\Linkedlist.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Linkedlist.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Linkedlist.dir\clean

CMakeFiles\Linkedlist.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Mayank Sharma\CLionProjects\Linkedlist" "C:\Users\Mayank Sharma\CLionProjects\Linkedlist" "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug" "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug" "C:\Users\Mayank Sharma\CLionProjects\Linkedlist\cmake-build-debug\CMakeFiles\Linkedlist.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Linkedlist.dir\depend

