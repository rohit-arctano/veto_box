# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rohit/Test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohit/Test/build

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/TestApplication.cxx.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/TestApplication.cxx.o: /home/rohit/Test/TestApplication.cxx
CMakeFiles/Test.dir/TestApplication.cxx.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rohit/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/TestApplication.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/TestApplication.cxx.o -MF CMakeFiles/Test.dir/TestApplication.cxx.o.d -o CMakeFiles/Test.dir/TestApplication.cxx.o -c /home/rohit/Test/TestApplication.cxx

CMakeFiles/Test.dir/TestApplication.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/TestApplication.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohit/Test/TestApplication.cxx > CMakeFiles/Test.dir/TestApplication.cxx.i

CMakeFiles/Test.dir/TestApplication.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/TestApplication.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohit/Test/TestApplication.cxx -o CMakeFiles/Test.dir/TestApplication.cxx.s

CMakeFiles/Test.dir/TestPublisherApp.cxx.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/TestPublisherApp.cxx.o: /home/rohit/Test/TestPublisherApp.cxx
CMakeFiles/Test.dir/TestPublisherApp.cxx.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rohit/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test.dir/TestPublisherApp.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/TestPublisherApp.cxx.o -MF CMakeFiles/Test.dir/TestPublisherApp.cxx.o.d -o CMakeFiles/Test.dir/TestPublisherApp.cxx.o -c /home/rohit/Test/TestPublisherApp.cxx

CMakeFiles/Test.dir/TestPublisherApp.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/TestPublisherApp.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohit/Test/TestPublisherApp.cxx > CMakeFiles/Test.dir/TestPublisherApp.cxx.i

CMakeFiles/Test.dir/TestPublisherApp.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/TestPublisherApp.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohit/Test/TestPublisherApp.cxx -o CMakeFiles/Test.dir/TestPublisherApp.cxx.s

CMakeFiles/Test.dir/TestSubscriberApp.cxx.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/TestSubscriberApp.cxx.o: /home/rohit/Test/TestSubscriberApp.cxx
CMakeFiles/Test.dir/TestSubscriberApp.cxx.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rohit/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Test.dir/TestSubscriberApp.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/TestSubscriberApp.cxx.o -MF CMakeFiles/Test.dir/TestSubscriberApp.cxx.o.d -o CMakeFiles/Test.dir/TestSubscriberApp.cxx.o -c /home/rohit/Test/TestSubscriberApp.cxx

CMakeFiles/Test.dir/TestSubscriberApp.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/TestSubscriberApp.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohit/Test/TestSubscriberApp.cxx > CMakeFiles/Test.dir/TestSubscriberApp.cxx.i

CMakeFiles/Test.dir/TestSubscriberApp.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/TestSubscriberApp.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohit/Test/TestSubscriberApp.cxx -o CMakeFiles/Test.dir/TestSubscriberApp.cxx.s

CMakeFiles/Test.dir/Testmain.cxx.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/Testmain.cxx.o: /home/rohit/Test/Testmain.cxx
CMakeFiles/Test.dir/Testmain.cxx.o: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rohit/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Test.dir/Testmain.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/Testmain.cxx.o -MF CMakeFiles/Test.dir/Testmain.cxx.o.d -o CMakeFiles/Test.dir/Testmain.cxx.o -c /home/rohit/Test/Testmain.cxx

CMakeFiles/Test.dir/Testmain.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/Testmain.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohit/Test/Testmain.cxx > CMakeFiles/Test.dir/Testmain.cxx.i

CMakeFiles/Test.dir/Testmain.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/Testmain.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohit/Test/Testmain.cxx -o CMakeFiles/Test.dir/Testmain.cxx.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/TestApplication.cxx.o" \
"CMakeFiles/Test.dir/TestPublisherApp.cxx.o" \
"CMakeFiles/Test.dir/TestSubscriberApp.cxx.o" \
"CMakeFiles/Test.dir/Testmain.cxx.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/TestApplication.cxx.o
Test: CMakeFiles/Test.dir/TestPublisherApp.cxx.o
Test: CMakeFiles/Test.dir/TestSubscriberApp.cxx.o
Test: CMakeFiles/Test.dir/Testmain.cxx.o
Test: CMakeFiles/Test.dir/build.make
Test: libTest_lib.a
Test: /usr/local/lib/libfastdds.so.3.2.0
Test: /usr/local/lib/libfastcdr.so.2.3.0
Test: /usr/local/lib/libfoonathan_memory-0.7.3.a
Test: /usr/lib/x86_64-linux-gnu/libssl.so
Test: /usr/lib/x86_64-linux-gnu/libcrypto.so
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rohit/Test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test
.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /home/rohit/Test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohit/Test /home/rohit/Test /home/rohit/Test/build /home/rohit/Test/build /home/rohit/Test/build/CMakeFiles/Test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Test.dir/depend

