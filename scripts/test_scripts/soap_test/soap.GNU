
# So we can check on the actual makefile if this is being included
GSOAP_CONFIG_INCLUDED := yes

# Home to be used the entire file
GSOAP_ROOT := /usr/local
GSOAP_DIR := $(GSOAP_ROOT)/share/gsoap

# To get wsa.h
GSOAP_IMPORT_DIR := $(GSOAP_DIR)/import

# Get plugin path
GSOAP_PLUGIN_DIR := $(GSOAP_DIR)/plugin

# Use the shell command to find the library
LIBRARY_PATH := /home/cezario/lib/libgsoap++.a

# Extract the filename without 'lib' and '.a', may contain version number after ++
LIBRARY_NAME_W_PREFIX := $(notdir $(basename $(LIBRARY_PATH)))
LIBRARY_NAME := $(patsubst lib%,%,$(LIBRARY_NAME_W_PREFIX))

# Extract the directory from the library path
LIBRARY_FOLDER := $(dir $(LIBRARY_PATH))

# Find soapcpp2
GSOAP_SOAPCPP2 := $(HOME)/bin/soapcpp2

COMPILE_INC += -I$(GSOAP_PLUGIN_DIR) -I$(GSOAP_IMPORT_DIR)
