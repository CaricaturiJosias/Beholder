
# So we can check on the actual makefile if this is being included
GSOAP_CONFIG_INCLUDED := yes

# Home to be used the entire file
GSOAP_ROOT := /home/cezario

# Define the GSOAP_INCLUDE_DIR
GSOAP_INCLUDE_DIR := $(shell find $(GSOAP_ROOT) -type d -name include)

# To get wsa.h
GSOAP_IMPORT_DIR := $(shell find $(GSOAP_ROOT)/share/gsoap/import -name 'wsa.h' 2>/dev/null)
WSA_HEADER_DIR_AND_HEADER := $(dir $(firstword $(GSOAP_IMPORT_DIR)))
WSA_HEADER_DIR := $(patsubst %/wsa.h,%,$(WSA_HEADER_DIR_AND_HEADER))

GSOAP_INCLUDE_DIR := $(shell find $(GSOAP_ROOT)/include -name 'stdsoap2.h' 2>/dev/null)
STD_SOAP2_HEADER_DIR := $(dir $(firstword $(GSOAP_INCLUDE_DIR)))

# Get plugin path
GSOAP_PLUGIN_DIR := /home/cezario/soap/gsoap-2.8/gsoap/plugin/
GSOAP_INCLUDE_PATHS := $(addprefix $(GSOAP_ROOT), $(addsuffix /include, $(if $(wildcard $(GSOAP_ROOT)), ,/*)))

GSOAP_INCLUDE_DIR := $(shell find $(GSOAP_INCLUDE_PATHS) -type d -name stdsoap2.h)
GSOAP_PLUGIN_INCLUDE_DIR := $(shell find $(GSOAP_PLUGIN_DIR) -type d -name threads.h)

#Libraries 
GSOAP_CXX_LIBRARIES := $(shell find $(GSOAP_ROOT)/lib $(GSOAP_ROOT)/lib64 $(GSOAP_ROOT)/lib32 -name 'libgsoap++.so' -o -name 'libgsoap++.a' 2>/dev/null)
MAIN_GSOAP_LIBRARY_TEMP := $(firstword $(GSOAP_CXX_LIBRARIES))
MAIN_GSOAP_LIBRARY := $(shell dirname $(MAIN_GSOAP_LIBRARY_TEMP))

GSOAP_SSL_CXX_LIBRARIES := $(shell find $(GSOAP_ROOT)/lib $(GSOAP_ROOT)/lib64 $(GSOAP_ROOT)/lib32 -name 'libgsoapssl++.so' -o -name 'libgsoapssl++.a' 2>/dev/null)
SSL_GSOAP_LIBRARY_TEMP := $(firstword $(GSOAP_SSL_CXX_LIBRARIES))
SSL_GSOAP_LIBRARY := $(shell dirname $(SSL_GSOAP_LIBRARY_TEMP))

# For the soapccp2 and wsdl2h
ifndef GSOAP_TOOL_DIR
    GSOAP_TOOL_DIR := $(GSOAP_ROOT)
endif

# Define the GSOAP_BIN_PATH variable for searching the bin directory
GSOAP_BIN_PATH := $(GSOAP_TOOL_DIR)/bin

# Use find_program to locate wsdl2h and soapcpp2
GSOAP_WSDL2H := $(shell which wsdl2h)
GSOAP_SOAPCPP2 := $(shell which soapcpp2)

ifeq ($(GSOAP_WSDL2H),)
    GSOAP_WSDL2H := $(GSOAP_BIN_PATH)/wsdl2h
endif

ifeq ($(GSOAP_SOAPCPP2),)
    GSOAP_SOAPCPP2 := $(GSOAP_BIN_PATH)/soapcpp2
endif

LDFLAGS += $(foreach lib,$(MAIN_GSOAP_LIBRARY) $(SSL_GSOAP_LIBRARY) $(GSOAP_C_LIBS) $(GSOAP_SSL_C_LIBS),-l$(notdir $(basename $(lib))))
CXXFLAGS += -I$(GSOAP_INCLUDE_DIR) -I$(GSOAP_PLUGIN_INCLUDE_DIR)