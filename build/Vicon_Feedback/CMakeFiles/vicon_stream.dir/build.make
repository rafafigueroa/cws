# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rafa/cws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafa/cws/build

# Include any dependencies generated for this target.
include Vicon_Feedback/CMakeFiles/vicon_stream.dir/depend.make

# Include the progress variables for this target.
include Vicon_Feedback/CMakeFiles/vicon_stream.dir/progress.make

# Include the compile flags for this target's objects.
include Vicon_Feedback/CMakeFiles/vicon_stream.dir/flags.make

Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o: Vicon_Feedback/CMakeFiles/vicon_stream.dir/flags.make
Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o: /home/rafa/cws/src/Vicon_Feedback/src/vicon_stream.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rafa/cws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o"
	cd /home/rafa/cws/build/Vicon_Feedback && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o -c /home/rafa/cws/src/Vicon_Feedback/src/vicon_stream.cpp

Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.i"
	cd /home/rafa/cws/build/Vicon_Feedback && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rafa/cws/src/Vicon_Feedback/src/vicon_stream.cpp > CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.i

Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.s"
	cd /home/rafa/cws/build/Vicon_Feedback && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rafa/cws/src/Vicon_Feedback/src/vicon_stream.cpp -o CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.s

Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.requires:
.PHONY : Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.requires

Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.provides: Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.requires
	$(MAKE) -f Vicon_Feedback/CMakeFiles/vicon_stream.dir/build.make Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.provides.build
.PHONY : Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.provides

Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.provides.build: Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o

# Object files for target vicon_stream
vicon_stream_OBJECTS = \
"CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o"

# External object files for target vicon_stream
vicon_stream_EXTERNAL_OBJECTS =

/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/libroscpp.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/libboost_signals-mt.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/libboost_filesystem-mt.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/librosconsole.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/librosconsole_log4cxx.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/librosconsole_backend_interface.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/liblog4cxx.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/libboost_regex-mt.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/libxmlrpcpp.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/libroscpp_serialization.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/librostime.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/libboost_date_time-mt.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/libboost_system-mt.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/libboost_thread-mt.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/libcpp_common.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /opt/ros/hydro/lib/libconsole_bridge.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /home/rafa/cws/devel/lib/libvicon_pos.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: /home/rafa/cws/devel/lib/libshared_memory_feedback.so
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: Vicon_Feedback/CMakeFiles/vicon_stream.dir/build.make
/home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream: Vicon_Feedback/CMakeFiles/vicon_stream.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream"
	cd /home/rafa/cws/build/Vicon_Feedback && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vicon_stream.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Vicon_Feedback/CMakeFiles/vicon_stream.dir/build: /home/rafa/cws/devel/lib/Vicon_Feedback/vicon_stream
.PHONY : Vicon_Feedback/CMakeFiles/vicon_stream.dir/build

Vicon_Feedback/CMakeFiles/vicon_stream.dir/requires: Vicon_Feedback/CMakeFiles/vicon_stream.dir/src/vicon_stream.cpp.o.requires
.PHONY : Vicon_Feedback/CMakeFiles/vicon_stream.dir/requires

Vicon_Feedback/CMakeFiles/vicon_stream.dir/clean:
	cd /home/rafa/cws/build/Vicon_Feedback && $(CMAKE_COMMAND) -P CMakeFiles/vicon_stream.dir/cmake_clean.cmake
.PHONY : Vicon_Feedback/CMakeFiles/vicon_stream.dir/clean

Vicon_Feedback/CMakeFiles/vicon_stream.dir/depend:
	cd /home/rafa/cws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafa/cws/src /home/rafa/cws/src/Vicon_Feedback /home/rafa/cws/build /home/rafa/cws/build/Vicon_Feedback /home/rafa/cws/build/Vicon_Feedback/CMakeFiles/vicon_stream.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Vicon_Feedback/CMakeFiles/vicon_stream.dir/depend

