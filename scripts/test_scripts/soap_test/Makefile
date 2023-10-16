# Makefile - ACE/TAO-CORBA
# ASDPC - Escola Politécnica - PUCPR
# Prof. Luiz Lima Jr.

# Modified by Gabriel Vitor Cezario

ACE_ROOT = /home/cezario/Dev/ACE_wrappers
include ./soap.GNU

PROGRAM = soapteste

PROJECT_DIR = /home/cezario/Dev/Beholder

MSG_PROCESSOR_DIR := ${PROJECT_DIR}/soap_test
WS_INTERFACE_BUILD_TARGET := hello.h 

IDL.idl = Beholder.idl
SOURCES.cpp = \
	hello.cpp \

GSOAP_GENERATION_OUTPUT := \
    ./Generated/soapServer.cpp \
    ./Generated/soapC.cpp \
	/home/cezario/soap/gsoap-2.8/gsoap/stdsoap2.cpp

SOURCES = $(SOURCES.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

LIBS = $(foreach l, $(LIBRARIES), -l$l)
LIBDIRS = $(foreach d, $(LIB_DIRS), -L$d)

# C++ Adtional Compliler and Linker Flags
CXXFLAGS += -Wall -std=c++20 -DWITH_NO_C_LOCALE
LDFLAGS +=

.SUFFIXES: .cpp .o
COMPILE.cpp = $(CXX) $(CXXFLAGS) $(COMPILE_INC)
LINK.cpp = $(CXX) $(LDFLAGS)
.cpp.o:
	@echo $(COMPILE_INC)
	@echo -e "Compilando $(notdir $<)"
	@$(COMPILE.cpp) -c -o $@ $<

# Standard targets.

.KEEP_STATE:

all: $(PROGRAM)
objects: $(SOURCES) $(OBJECTS)
sources: $(SOURCES)
teste:
	@echo -e "something: " $(OBJECTS)

$(PROGRAM): $(SOURCES.cpp) $(OBJECTS)
	@echo -e "\nLinkando $(notdir $@)\n"
	@echo -e $(LINK.cpp) -o $(OBJECTS) $(COMPILE_INC)
	@$(LINK.cpp) -o $(PROGRAM).cgi $(OBJECTS) $(GSOAP_GENERATION_OUTPUT) $(COMPILE_INC)
clean:
	@echo -e "\nLimpando: $(notdir $(OBJECTS) $(PROGRAM))\n"
	@rm -f  $(OBJECTS) core $(PROGRAM)
install: ${GSOAP_GENERATION_OUTPUT} $(GSOAP_GENERATION_OUTPUT)
	@echo "Installing the soapcpp2 files in ./Generated with "$(GSOAP_SOAPCPP2)

${GSOAP_GENERATION_OUTPUT}: ${MSG_PROCESSOR_DIR}/${WS_INTERFACE_BUILD_TARGET}
		${GSOAP_SOAPCPP2} -d ${MSG_PROCESSOR_DIR}/Generated ${MSG_PROCESSOR_DIR}/${WS_INTERFACE_BUILD_TARGET}
