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
CMAKE_SOURCE_DIR = /home/devesh/Documents/srujana/Day1/Morpho

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devesh/Documents/srujana/Day1/Morpho

# Include any dependencies generated for this target.
include CMakeFiles/morph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/morph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/morph.dir/flags.make

CMakeFiles/morph.dir/morph.cpp.o: CMakeFiles/morph.dir/flags.make
CMakeFiles/morph.dir/morph.cpp.o: morph.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/devesh/Documents/srujana/Day1/Morpho/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/morph.dir/morph.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/morph.dir/morph.cpp.o -c /home/devesh/Documents/srujana/Day1/Morpho/morph.cpp

CMakeFiles/morph.dir/morph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/morph.dir/morph.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/devesh/Documents/srujana/Day1/Morpho/morph.cpp > CMakeFiles/morph.dir/morph.cpp.i

CMakeFiles/morph.dir/morph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/morph.dir/morph.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/devesh/Documents/srujana/Day1/Morpho/morph.cpp -o CMakeFiles/morph.dir/morph.cpp.s

CMakeFiles/morph.dir/morph.cpp.o.requires:
.PHONY : CMakeFiles/morph.dir/morph.cpp.o.requires

CMakeFiles/morph.dir/morph.cpp.o.provides: CMakeFiles/morph.dir/morph.cpp.o.requires
	$(MAKE) -f CMakeFiles/morph.dir/build.make CMakeFiles/morph.dir/morph.cpp.o.provides.build
.PHONY : CMakeFiles/morph.dir/morph.cpp.o.provides

CMakeFiles/morph.dir/morph.cpp.o.provides.build: CMakeFiles/morph.dir/morph.cpp.o

# Object files for target morph
morph_OBJECTS = \
"CMakeFiles/morph.dir/morph.cpp.o"

# External object files for target morph
morph_EXTERNAL_OBJECTS =

morph: CMakeFiles/morph.dir/morph.cpp.o
morph: CMakeFiles/morph.dir/build.make
morph: /usr/local/lib/libopencv_videostab.so.3.0.0
morph: /usr/local/lib/libopencv_videoio.so.3.0.0
morph: /usr/local/lib/libopencv_video.so.3.0.0
morph: /usr/local/lib/libopencv_ts.a
morph: /usr/local/lib/libopencv_superres.so.3.0.0
morph: /usr/local/lib/libopencv_stitching.so.3.0.0
morph: /usr/local/lib/libopencv_shape.so.3.0.0
morph: /usr/local/lib/libopencv_photo.so.3.0.0
morph: /usr/local/lib/libopencv_objdetect.so.3.0.0
morph: /usr/local/lib/libopencv_ml.so.3.0.0
morph: /usr/local/lib/libopencv_imgproc.so.3.0.0
morph: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
morph: /usr/local/lib/libopencv_highgui.so.3.0.0
morph: /usr/local/lib/libopencv_flann.so.3.0.0
morph: /usr/local/lib/libopencv_features2d.so.3.0.0
morph: /usr/local/lib/libopencv_core.so.3.0.0
morph: /usr/local/lib/libopencv_calib3d.so.3.0.0
morph: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
morph: /usr/local/lib/libopencv_features2d.so.3.0.0
morph: /usr/local/lib/libopencv_ml.so.3.0.0
morph: /usr/local/lib/libopencv_highgui.so.3.0.0
morph: /usr/local/lib/libopencv_videoio.so.3.0.0
morph: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
morph: /usr/local/lib/libopencv_flann.so.3.0.0
morph: /usr/local/lib/libopencv_video.so.3.0.0
morph: /usr/local/lib/libopencv_imgproc.so.3.0.0
morph: /usr/local/lib/libopencv_core.so.3.0.0
morph: CMakeFiles/morph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable morph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/morph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/morph.dir/build: morph
.PHONY : CMakeFiles/morph.dir/build

CMakeFiles/morph.dir/requires: CMakeFiles/morph.dir/morph.cpp.o.requires
.PHONY : CMakeFiles/morph.dir/requires

CMakeFiles/morph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/morph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/morph.dir/clean

CMakeFiles/morph.dir/depend:
	cd /home/devesh/Documents/srujana/Day1/Morpho && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devesh/Documents/srujana/Day1/Morpho /home/devesh/Documents/srujana/Day1/Morpho /home/devesh/Documents/srujana/Day1/Morpho /home/devesh/Documents/srujana/Day1/Morpho /home/devesh/Documents/srujana/Day1/Morpho/CMakeFiles/morph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/morph.dir/depend

