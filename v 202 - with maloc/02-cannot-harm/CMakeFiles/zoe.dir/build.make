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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/richard/Documents/02-cannot-harm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/richard/Documents/02-cannot-harm

# Include any dependencies generated for this target.
include CMakeFiles/zoe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zoe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zoe.dir/flags.make

CMakeFiles/zoe.dir/interpreter.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/interpreter.c.o: interpreter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zoe.dir/interpreter.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/interpreter.c.o   -c /home/richard/Documents/02-cannot-harm/interpreter.c

CMakeFiles/zoe.dir/interpreter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/interpreter.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/interpreter.c > CMakeFiles/zoe.dir/interpreter.c.i

CMakeFiles/zoe.dir/interpreter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/interpreter.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/interpreter.c -o CMakeFiles/zoe.dir/interpreter.c.s

CMakeFiles/zoe.dir/lexer.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/lexer.c.o: lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/zoe.dir/lexer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/lexer.c.o   -c /home/richard/Documents/02-cannot-harm/lexer.c

CMakeFiles/zoe.dir/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/lexer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/lexer.c > CMakeFiles/zoe.dir/lexer.c.i

CMakeFiles/zoe.dir/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/lexer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/lexer.c -o CMakeFiles/zoe.dir/lexer.c.s

CMakeFiles/zoe.dir/main.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/zoe.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/main.c.o   -c /home/richard/Documents/02-cannot-harm/main.c

CMakeFiles/zoe.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/main.c > CMakeFiles/zoe.dir/main.c.i

CMakeFiles/zoe.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/main.c -o CMakeFiles/zoe.dir/main.c.s

CMakeFiles/zoe.dir/parser.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/parser.c.o: parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/zoe.dir/parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/parser.c.o   -c /home/richard/Documents/02-cannot-harm/parser.c

CMakeFiles/zoe.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/parser.c > CMakeFiles/zoe.dir/parser.c.i

CMakeFiles/zoe.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/parser.c -o CMakeFiles/zoe.dir/parser.c.s

CMakeFiles/zoe.dir/tokenizer.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/tokenizer.c.o: tokenizer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/zoe.dir/tokenizer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/tokenizer.c.o   -c /home/richard/Documents/02-cannot-harm/tokenizer.c

CMakeFiles/zoe.dir/tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/tokenizer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/tokenizer.c > CMakeFiles/zoe.dir/tokenizer.c.i

CMakeFiles/zoe.dir/tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/tokenizer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/tokenizer.c -o CMakeFiles/zoe.dir/tokenizer.c.s

CMakeFiles/zoe.dir/unicode.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/unicode.c.o: unicode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/zoe.dir/unicode.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/unicode.c.o   -c /home/richard/Documents/02-cannot-harm/unicode.c

CMakeFiles/zoe.dir/unicode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/unicode.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/unicode.c > CMakeFiles/zoe.dir/unicode.c.i

CMakeFiles/zoe.dir/unicode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/unicode.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/unicode.c -o CMakeFiles/zoe.dir/unicode.c.s

CMakeFiles/zoe.dir/error.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/error.c.o: error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/zoe.dir/error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/error.c.o   -c /home/richard/Documents/02-cannot-harm/error.c

CMakeFiles/zoe.dir/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/error.c > CMakeFiles/zoe.dir/error.c.i

CMakeFiles/zoe.dir/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/error.c -o CMakeFiles/zoe.dir/error.c.s

CMakeFiles/zoe.dir/binding.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/binding.c.o: binding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/zoe.dir/binding.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/binding.c.o   -c /home/richard/Documents/02-cannot-harm/binding.c

CMakeFiles/zoe.dir/binding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/binding.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/binding.c > CMakeFiles/zoe.dir/binding.c.i

CMakeFiles/zoe.dir/binding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/binding.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/binding.c -o CMakeFiles/zoe.dir/binding.c.s

CMakeFiles/zoe.dir/inet.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/inet.c.o: inet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/zoe.dir/inet.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/inet.c.o   -c /home/richard/Documents/02-cannot-harm/inet.c

CMakeFiles/zoe.dir/inet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/inet.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/inet.c > CMakeFiles/zoe.dir/inet.c.i

CMakeFiles/zoe.dir/inet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/inet.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/inet.c -o CMakeFiles/zoe.dir/inet.c.s

CMakeFiles/zoe.dir/unacceptable.c.o: CMakeFiles/zoe.dir/flags.make
CMakeFiles/zoe.dir/unacceptable.c.o: unacceptable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/zoe.dir/unacceptable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/zoe.dir/unacceptable.c.o   -c /home/richard/Documents/02-cannot-harm/unacceptable.c

CMakeFiles/zoe.dir/unacceptable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zoe.dir/unacceptable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/richard/Documents/02-cannot-harm/unacceptable.c > CMakeFiles/zoe.dir/unacceptable.c.i

CMakeFiles/zoe.dir/unacceptable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zoe.dir/unacceptable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/richard/Documents/02-cannot-harm/unacceptable.c -o CMakeFiles/zoe.dir/unacceptable.c.s

# Object files for target zoe
zoe_OBJECTS = \
"CMakeFiles/zoe.dir/interpreter.c.o" \
"CMakeFiles/zoe.dir/lexer.c.o" \
"CMakeFiles/zoe.dir/main.c.o" \
"CMakeFiles/zoe.dir/parser.c.o" \
"CMakeFiles/zoe.dir/tokenizer.c.o" \
"CMakeFiles/zoe.dir/unicode.c.o" \
"CMakeFiles/zoe.dir/error.c.o" \
"CMakeFiles/zoe.dir/binding.c.o" \
"CMakeFiles/zoe.dir/inet.c.o" \
"CMakeFiles/zoe.dir/unacceptable.c.o"

# External object files for target zoe
zoe_EXTERNAL_OBJECTS =

zoe: CMakeFiles/zoe.dir/interpreter.c.o
zoe: CMakeFiles/zoe.dir/lexer.c.o
zoe: CMakeFiles/zoe.dir/main.c.o
zoe: CMakeFiles/zoe.dir/parser.c.o
zoe: CMakeFiles/zoe.dir/tokenizer.c.o
zoe: CMakeFiles/zoe.dir/unicode.c.o
zoe: CMakeFiles/zoe.dir/error.c.o
zoe: CMakeFiles/zoe.dir/binding.c.o
zoe: CMakeFiles/zoe.dir/inet.c.o
zoe: CMakeFiles/zoe.dir/unacceptable.c.o
zoe: CMakeFiles/zoe.dir/build.make
zoe: CMakeFiles/zoe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/richard/Documents/02-cannot-harm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable zoe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zoe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zoe.dir/build: zoe

.PHONY : CMakeFiles/zoe.dir/build

CMakeFiles/zoe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zoe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zoe.dir/clean

CMakeFiles/zoe.dir/depend:
	cd /home/richard/Documents/02-cannot-harm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/richard/Documents/02-cannot-harm /home/richard/Documents/02-cannot-harm /home/richard/Documents/02-cannot-harm /home/richard/Documents/02-cannot-harm /home/richard/Documents/02-cannot-harm/CMakeFiles/zoe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zoe.dir/depend

