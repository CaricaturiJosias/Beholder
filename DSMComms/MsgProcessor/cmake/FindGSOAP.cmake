#
#   Made by nherbaut
#
# This module detects if gsoap is installed and determines where the
# include files and libraries are.
#
# This code sets the following variables:
#
# GSOAP_IMPORT_DIR      = full path to the gsoap import directory
# GSOAP_LIBRARIES       = full path to the gsoap libraries
# GSOAP_SSL_LIBRARIES   = full path to the gsoap ssl libraries
# GSOAP_INCLUDE_DIR     = include dir to be used when using the gsoap library
# GSOAP_WSDL2H          = wsdl2h binary
# GSOAP_SOAPCPP2        = soapcpp2 binary
# GSOAP_FOUND           = set to true if gsoap was found successfully
#

set (GSOAP_ROOT $ENV{HOME})
#   setting this enables search for gsoap libraries / headers in this location

# -----------------------------------------------------
# GSOAP Import Directories
# -----------------------------------------------------
find_path(GSOAP_IMPORT_DIR
  NAMES wsa.h
  PATHS ${GSOAP_ROOT}/import ${GSOAP_ROOT}/share/gsoap/import
)

# -----------------------------------------------------
# GSOAP Libraries
# -----------------------------------------------------
find_library(GSOAP_CXX_LIBRARIES
	NAMES gsoap++
	HINTS ${GSOAP_ROOT}/lib ${GSOAP_ROOT}/lib64
		  ${GSOAP_ROOT}/lib32
	DOC "The main gsoap library"
)

find_library(GSOAP_SSL_CXX_LIBRARIES
	NAMES gsoapssl++
	HINTS ${GSOAP_ROOT}/lib ${GSOAP_ROOT}/lib64
		  ${GSOAP_ROOT}/lib32
	DOC "The ssl gsoap library"
)

find_library(GSOAP_C_LIBRARIES
	NAMES gsoap
	HINTS ${GSOAP_ROOT}/lib ${GSOAP_ROOT}/lib64
		  ${GSOAP_ROOT}/lib32
	DOC "The main gsoap library"
)

find_library(GSOAP_SSL_C_LIBRARIES
	NAMES gsoapssl
	HINTS ${GSOAP_ROOT}/lib ${GSOAP_ROOT}/lib64
		  ${GSOAP_ROOT}/lib32
	DOC "The ssl gsoap library"
)

# -----------------------------------------------------
# GSOAP Include Directories
# -----------------------------------------------------
find_path(GSOAP_INCLUDE_DIR
	NAMES stdsoap2.h
	HINTS ${GSOAP_ROOT} ${GSOAP_ROOT}/include ${GSOAP_ROOT}/include/*
	DOC "The gsoap include directory"
)

# -----------------------------------------------------
# GSOAP Binaries
# ----------------------------------------------------
if(NOT GSOAP_TOOL_DIR)
	set(GSOAP_TOOL_DIR GSOAP_ROOT)
endif()

find_program(GSOAP_WSDL2H
	NAMES wsdl2h
	HINTS ${GSOAP_TOOL_DIR}/bin
	DOC "The gsoap bin directory"
)
find_program(GSOAP_SOAPCPP2
	NAMES soapcpp2
	HINTS ${GSOAP_TOOL_DIR}/bin
	DOC "The gsoap bin directory"
)