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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/devesh/Documents/srujana/ProjectFiles/Day4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devesh/Documents/srujana/ProjectFiles/Day4/Build

# Include any dependencies generated for this target.
include CMakeFiles/videocap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/videocap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/videocap.dir/flags.make

CMakeFiles/videocap.dir/videocap.cpp.o: CMakeFiles/videocap.dir/flags.make
CMakeFiles/videocap.dir/videocap.cpp.o: ../videocap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/devesh/Documents/srujana/ProjectFiles/Day4/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/videocap.dir/videocap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/videocap.dir/videocap.cpp.o -c /home/devesh/Documents/srujana/ProjectFiles/Day4/videocap.cpp

CMakeFiles/videocap.dir/videocap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/videocap.dir/videocap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/devesh/Documents/srujana/ProjectFiles/Day4/videocap.cpp > CMakeFiles/videocap.dir/videocap.cpp.i

CMakeFiles/videocap.dir/videocap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/videocap.dir/videocap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/devesh/Documents/srujana/ProjectFiles/Day4/videocap.cpp -o CMakeFiles/videocap.dir/videocap.cpp.s

CMakeFiles/videocap.dir/videocap.cpp.o.requires:
.PHONY : CMakeFiles/videocap.dir/videocap.cpp.o.requires

CMakeFiles/videocap.dir/videocap.cpp.o.provides: CMakeFiles/videocap.dir/videocap.cpp.o.requires
	$(MAKE) -f CMakeFiles/videocap.dir/build.make CMakeFiles/videocap.dir/videocap.cpp.o.provides.build
.PHONY : CMakeFiles/videocap.dir/videocap.cpp.o.provides

CMakeFiles/videocap.dir/videocap.cpp.o.provides.build: CMakeFiles/videocap.dir/videocap.cpp.o

# Object files for target videocap
videocap_OBJECTS = \
"CMakeFiles/videocap.dir/videocap.cpp.o"

# External object files for target videocap
videocap_EXTERNAL_OBJECTS =

videocap: CMakeFiles/videocap.dir/videocap.cpp.o
videocap: CMakeFiles/videocap.dir/build.make
videocap: /usr/local/lib/libopencv_videostab.so.2.4.10
videocap: /usr/local/lib/libopencv_video.so.2.4.10
videocap: /usr/local/lib/libopencv_ts.a
videocap: /usr/local/lib/libopencv_superres.so.2.4.10
videocap: /usr/local/lib/libopencv_stitching.so.2.4.10
videocap: /usr/local/lib/libopencv_photo.so.2.4.10
videocap: /usr/local/lib/libopencv_ocl.so.2.4.10
videocap: /usr/local/lib/libopencv_objdetect.so.2.4.10
videocap: /usr/local/lib/libopencv_nonfree.so.2.4.10
videocap: /usr/local/lib/libopencv_ml.so.2.4.10
videocap: /usr/local/lib/libopencv_legacy.so.2.4.10
videocap: /usr/local/lib/libopencv_imgproc.so.2.4.10
videocap: /usr/local/lib/libopencv_highgui.so.2.4.10
videocap: /usr/local/lib/libopencv_gpu.so.2.4.10
videocap: /usr/local/lib/libopencv_flann.so.2.4.10
videocap: /usr/local/lib/libopencv_features2d.so.2.4.10
videocap: /usr/local/lib/libopencv_core.so.2.4.10
videocap: /usr/local/lib/libopencv_contrib.so.2.4.10
videocap: /usr/local/lib/libopencv_calib3d.so.2.4.10
videocap: /usr/local/lib/libopencv_nonfree.so.2.4.10
videocap: /usr/local/lib/libopencv_ocl.so.2.4.10
videocap: /usr/local/lib/libopencv_gpu.so.2.4.10
videocap: /usr/local/lib/libopencv_photo.so.2.4.10
videocap: /usr/local/lib/libopencv_objdetect.so.2.4.10
videocap: /usr/local/lib/libopencv_legacy.so.2.4.10
videocap: /usr/local/lib/libopencv_video.so.2.4.10
videocap: /usr/local/lib/libopencv_ml.so.2.4.10
videocap: /usr/local/lib/libopencv_calib3d.so.2.4.10
videocap: /usr/local/lib/libopencv_features2d.so.2.4.10
videocap: /usr/local/lib/libopencv_highgui.so.2.4.10
videocap: /usr/local/lib/libopencv_imgproc.so.2.4.10
videocap: /usr/local/lib/libopencv_flann.so.2.4.10
videocap: /usr/local/lib/libopencv_core.so.2.4.10
videocap: CMakeFiles/videocap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable videocap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/videocap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/videocap.dir/build: videocap
.PHONY : CMakeFiles/videocap.dir/build

CMakeFiles/videocap.dir/requires: CMakeFiles/videocap.dir/videocap.cpp.o.requires
.PHONY : CMakeFiles/videocap.dir/requires

CMakeFiles/videocap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/videocap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/videocap.dir/clean

CMakeFiles/videocap.dir/depend:
	cd /home/devesh/Documents/srujana/ProjectFiles/Day4/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devesh/Documents/srujana/ProjectFiles/Day4 /home/devesh/Documents/srujana/ProjectFiles/Day4 /home/devesh/Documents/srujana/ProjectFiles/Day4/Build /home/devesh/Documents/srujana/ProjectFiles/Day4/Build /home/devesh/Documents/srujana/ProjectFiles/Day4/Build/CMakeFiles/videocap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/videocap.dir/depend

