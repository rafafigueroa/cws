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

# Utility rule file for vicon_stream_generate_messages.

# Include the progress variables for this target.
include vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/progress.make

vicon_stream/CMakeFiles/vicon_stream_generate_messages:

vicon_stream_generate_messages: vicon_stream/CMakeFiles/vicon_stream_generate_messages
vicon_stream_generate_messages: vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/build.make
.PHONY : vicon_stream_generate_messages

# Rule to build all files generated by this target.
vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/build: vicon_stream_generate_messages
.PHONY : vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/build

vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/clean:
	cd /home/rafa/cws/build/vicon_stream && $(CMAKE_COMMAND) -P CMakeFiles/vicon_stream_generate_messages.dir/cmake_clean.cmake
.PHONY : vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/clean

vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/depend:
	cd /home/rafa/cws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafa/cws/src /home/rafa/cws/src/vicon_stream /home/rafa/cws/build /home/rafa/cws/build/vicon_stream /home/rafa/cws/build/vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vicon_stream/CMakeFiles/vicon_stream_generate_messages.dir/depend

