# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/cezario/Dev/Beholder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cezario/Dev/Beholder

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cezario/Dev/Beholder/CMakeFiles /home/cezario/Dev/Beholder//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cezario/Dev/Beholder/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Beholder

# Build rule for target.
Beholder: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Beholder
.PHONY : Beholder

# fast build rule for target.
Beholder/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/CMakeFiles/Beholder.dir/build.make Beholder/CMakeFiles/Beholder.dir/build
.PHONY : Beholder/fast

#=============================================================================
# Target rules for targets named DataModels

# Build rule for target.
DataModels: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 DataModels
.PHONY : DataModels

# fast build rule for target.
DataModels/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/DataModels/CMakeFiles/DataModels.dir/build.make Beholder/DataModels/CMakeFiles/DataModels.dir/build
.PHONY : DataModels/fast

#=============================================================================
# Target rules for targets named DataModelsMakefile

# Build rule for target.
DataModelsMakefile: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 DataModelsMakefile
.PHONY : DataModelsMakefile

# fast build rule for target.
DataModelsMakefile/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/DataModels/CMakeFiles/DataModelsMakefile.dir/build.make Beholder/DataModels/CMakeFiles/DataModelsMakefile.dir/build
.PHONY : DataModelsMakefile/fast

#=============================================================================
# Target rules for targets named Entities

# Build rule for target.
Entities: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Entities
.PHONY : Entities

# fast build rule for target.
Entities/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/Entities/CMakeFiles/Entities.dir/build.make Beholder/Entities/CMakeFiles/Entities.dir/build
.PHONY : Entities/fast

#=============================================================================
# Target rules for targets named EntitiesMakefile

# Build rule for target.
EntitiesMakefile: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 EntitiesMakefile
.PHONY : EntitiesMakefile

# fast build rule for target.
EntitiesMakefile/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/Entities/CMakeFiles/EntitiesMakefile.dir/build.make Beholder/Entities/CMakeFiles/EntitiesMakefile.dir/build
.PHONY : EntitiesMakefile/fast

#=============================================================================
# Target rules for targets named 3PP

# Build rule for target.
3PP: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 3PP
.PHONY : 3PP

# fast build rule for target.
3PP/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/3PP/CMakeFiles/3PP.dir/build.make Beholder/3PP/CMakeFiles/3PP.dir/build
.PHONY : 3PP/fast

#=============================================================================
# Target rules for targets named 3PPMakefile

# Build rule for target.
3PPMakefile: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 3PPMakefile
.PHONY : 3PPMakefile

# fast build rule for target.
3PPMakefile/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/3PP/CMakeFiles/3PPMakefile.dir/build.make Beholder/3PP/CMakeFiles/3PPMakefile.dir/build
.PHONY : 3PPMakefile/fast

#=============================================================================
# Target rules for targets named MessageProcessing

# Build rule for target.
MessageProcessing: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MessageProcessing
.PHONY : MessageProcessing

# fast build rule for target.
MessageProcessing/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/MessageProcessing/CMakeFiles/MessageProcessing.dir/build.make Beholder/MessageProcessing/CMakeFiles/MessageProcessing.dir/build
.PHONY : MessageProcessing/fast

#=============================================================================
# Target rules for targets named LocalHelpers

# Build rule for target.
LocalHelpers: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 LocalHelpers
.PHONY : LocalHelpers

# fast build rule for target.
LocalHelpers/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/LocalHelpers/CMakeFiles/LocalHelpers.dir/build.make Beholder/LocalHelpers/CMakeFiles/LocalHelpers.dir/build
.PHONY : LocalHelpers/fast

#=============================================================================
# Target rules for targets named LocalHelpersMakefile

# Build rule for target.
LocalHelpersMakefile: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 LocalHelpersMakefile
.PHONY : LocalHelpersMakefile

# fast build rule for target.
LocalHelpersMakefile/fast:
	$(MAKE) $(MAKESILENT) -f Beholder/LocalHelpers/CMakeFiles/LocalHelpersMakefile.dir/build.make Beholder/LocalHelpers/CMakeFiles/LocalHelpersMakefile.dir/build
.PHONY : LocalHelpersMakefile/fast

#=============================================================================
# Target rules for targets named generate_stubs_skeletons

# Build rule for target.
generate_stubs_skeletons: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 generate_stubs_skeletons
.PHONY : generate_stubs_skeletons

# fast build rule for target.
generate_stubs_skeletons/fast:
	$(MAKE) $(MAKESILENT) -f DSMComms/CMakeFiles/generate_stubs_skeletons.dir/build.make DSMComms/CMakeFiles/generate_stubs_skeletons.dir/build
.PHONY : generate_stubs_skeletons/fast

#=============================================================================
# Target rules for targets named BuildBeholder

# Build rule for target.
BuildBeholder: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 BuildBeholder
.PHONY : BuildBeholder

# fast build rule for target.
BuildBeholder/fast:
	$(MAKE) $(MAKESILENT) -f DSMComms/CMakeFiles/BuildBeholder.dir/build.make DSMComms/CMakeFiles/BuildBeholder.dir/build
.PHONY : BuildBeholder/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... 3PPMakefile"
	@echo "... BuildBeholder"
	@echo "... DataModelsMakefile"
	@echo "... EntitiesMakefile"
	@echo "... LocalHelpersMakefile"
	@echo "... generate_stubs_skeletons"
	@echo "... 3PP"
	@echo "... Beholder"
	@echo "... DataModels"
	@echo "... Entities"
	@echo "... LocalHelpers"
	@echo "... MessageProcessing"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
