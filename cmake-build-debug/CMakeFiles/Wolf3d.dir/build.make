# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wstygg/CLionProjects/Wolf3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wstygg/CLionProjects/Wolf3d/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Wolf3d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wolf3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wolf3d.dir/flags.make

CMakeFiles/Wolf3d.dir/Sources/main.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/main.c.o: ../Sources/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Wolf3d.dir/Sources/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/main.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/main.c

CMakeFiles/Wolf3d.dir/Sources/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/main.c > CMakeFiles/Wolf3d.dir/Sources/main.c.i

CMakeFiles/Wolf3d.dir/Sources/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/main.c -o CMakeFiles/Wolf3d.dir/Sources/main.c.s

CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.o: ../Sources/Utils/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/list.c

CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/list.c > CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.i

CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/list.c -o CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.s

CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.o: ../Sources/Utils/list_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/list_2.c

CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/list_2.c > CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.i

CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/list_2.c -o CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.s

CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.o: ../Sources/Utils/ft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/ft.c

CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/ft.c > CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.i

CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/ft.c -o CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.s

CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.o: ../Sources/sdl_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/sdl_init.c

CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/sdl_init.c > CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.i

CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/sdl_init.c -o CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.s

CMakeFiles/Wolf3d.dir/Sources/sdl.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/sdl.c.o: ../Sources/sdl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Wolf3d.dir/Sources/sdl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/sdl.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/sdl.c

CMakeFiles/Wolf3d.dir/Sources/sdl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/sdl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/sdl.c > CMakeFiles/Wolf3d.dir/Sources/sdl.c.i

CMakeFiles/Wolf3d.dir/Sources/sdl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/sdl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/sdl.c -o CMakeFiles/Wolf3d.dir/Sources/sdl.c.s

CMakeFiles/Wolf3d.dir/Sources/keys.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/keys.c.o: ../Sources/keys.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Wolf3d.dir/Sources/keys.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/keys.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/keys.c

CMakeFiles/Wolf3d.dir/Sources/keys.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/keys.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/keys.c > CMakeFiles/Wolf3d.dir/Sources/keys.c.i

CMakeFiles/Wolf3d.dir/Sources/keys.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/keys.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/keys.c -o CMakeFiles/Wolf3d.dir/Sources/keys.c.s

CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.o: ../Sources/Utils/get_nl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/get_nl.c

CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/get_nl.c > CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.i

CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/get_nl.c -o CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.s

CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.o: ../Sources/Map/read_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Map/read_map.c

CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Map/read_map.c > CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.i

CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Map/read_map.c -o CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.s

CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.o: ../Sources/Map/check_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Map/check_file.c

CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Map/check_file.c > CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.i

CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Map/check_file.c -o CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.s

CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.o: ../Sources/wolf_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/wolf_init.c

CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/wolf_init.c > CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.i

CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/wolf_init.c -o CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.s

CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.o: ../Sources/Map/add_to_text.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Map/add_to_text.c

CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Map/add_to_text.c > CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.i

CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Map/add_to_text.c -o CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.s

CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.o: CMakeFiles/Wolf3d.dir/flags.make
CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.o: ../Sources/Utils/ft_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.o   -c /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/ft_2.c

CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/ft_2.c > CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.i

CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wstygg/CLionProjects/Wolf3d/Sources/Utils/ft_2.c -o CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.s

# Object files for target Wolf3d
Wolf3d_OBJECTS = \
"CMakeFiles/Wolf3d.dir/Sources/main.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/sdl.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/keys.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.o" \
"CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.o"

# External object files for target Wolf3d
Wolf3d_EXTERNAL_OBJECTS =

Wolf3d: CMakeFiles/Wolf3d.dir/Sources/main.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Utils/list.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Utils/list_2.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Utils/ft.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/sdl_init.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/sdl.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/keys.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Utils/get_nl.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Map/read_map.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Map/check_file.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/wolf_init.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Map/add_to_text.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/Sources/Utils/ft_2.c.o
Wolf3d: CMakeFiles/Wolf3d.dir/build.make
Wolf3d: CMakeFiles/Wolf3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable Wolf3d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wolf3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wolf3d.dir/build: Wolf3d

.PHONY : CMakeFiles/Wolf3d.dir/build

CMakeFiles/Wolf3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wolf3d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wolf3d.dir/clean

CMakeFiles/Wolf3d.dir/depend:
	cd /home/wstygg/CLionProjects/Wolf3d/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wstygg/CLionProjects/Wolf3d /home/wstygg/CLionProjects/Wolf3d /home/wstygg/CLionProjects/Wolf3d/cmake-build-debug /home/wstygg/CLionProjects/Wolf3d/cmake-build-debug /home/wstygg/CLionProjects/Wolf3d/cmake-build-debug/CMakeFiles/Wolf3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wolf3d.dir/depend

