# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\GeneralCPP.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\GeneralCPP.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\GeneralCPP.dir\flags.make

CMakeFiles\GeneralCPP.dir\main.cpp.obj: CMakeFiles\GeneralCPP.dir\flags.make
CMakeFiles\GeneralCPP.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GeneralCPP.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GeneralCPP.dir\main.cpp.obj /FdCMakeFiles\GeneralCPP.dir\ /FS -c C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\main.cpp
<<

CMakeFiles\GeneralCPP.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeneralCPP.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\GeneralCPP.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\main.cpp
<<

CMakeFiles\GeneralCPP.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeneralCPP.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GeneralCPP.dir\main.cpp.s /c C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\main.cpp
<<

# Object files for target GeneralCPP
GeneralCPP_OBJECTS = \
"CMakeFiles\GeneralCPP.dir\main.cpp.obj"

# External object files for target GeneralCPP
GeneralCPP_EXTERNAL_OBJECTS =

GeneralCPP.exe: CMakeFiles\GeneralCPP.dir\main.cpp.obj
GeneralCPP.exe: CMakeFiles\GeneralCPP.dir\build.make
GeneralCPP.exe: SOLID.lib
GeneralCPP.exe: DesignPatterns.lib
GeneralCPP.exe: CMakeFiles\GeneralCPP.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GeneralCPP.exe"
	"C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\GeneralCPP.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\GeneralCPP.dir\objects1.rsp @<<
 /out:GeneralCPP.exe /implib:GeneralCPP.lib /pdb:C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug\GeneralCPP.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  SOLID.lib DesignPatterns.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\GeneralCPP.dir\build: GeneralCPP.exe
.PHONY : CMakeFiles\GeneralCPP.dir\build

CMakeFiles\GeneralCPP.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GeneralCPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles\GeneralCPP.dir\clean

CMakeFiles\GeneralCPP.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug C:\Users\mark.barbaric\Documents\Mirriad\Developer\CPP\GeneralCPP\cmake-build-debug\CMakeFiles\GeneralCPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\GeneralCPP.dir\depend

