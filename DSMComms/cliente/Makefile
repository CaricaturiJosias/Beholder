# Makefile - ACE/TAO-CORBA
# ASDPC - Escola Politécnica - PUCPR
# Prof. Luiz Lima Jr.

# Modified by Gabriel Vitor Cezario

ACE_ROOT = /home/cezario/Dev/ACE_wrappers
include ./soap.GNU
include $(ACE_ROOT)/include/makeinclude/platform_macros.GNU

#
# Parâmetros:
#

PROJECT = cliente.cgi
SERVER = false

PROJECT_DIR = /home/cezario/Dev/Beholder
CORBA_DIR = ${PROJECT_DIR}/DSMComms

MSG_PROCESSOR_DIR := ${CORBA_DIR}/cliente
WS_INTERFACE_BUILD_TARGET := MsgProcessor.h 


IDL.idl = Beholder.idl
SOURCES.cpp = \
	cliente.cpp \

GSOAP_GENERATION_OUTPUT := \
    ${MSG_PROCESSOR_DIR}/Generated/soapServer.cpp \
    ${MSG_PROCESSOR_DIR}/Generated/soapC.cpp \
	/home/cezario/soap/gsoap-2.8/gsoap/stdsoap2.cpp


BINDIR = ${CORBA_DIR}/bin
IDLDIR = ${CORBA_DIR}/idl

INCLUDEDIR = /usr/include/Beholder

INCLUDES  = $(IDLDIR) \
			$(ACE_ROOT) \
			$(TAO_ROOT) \
			$(TAO_ROOT)/orbsvcs \
			/usr/local/share/ \


LIBRARIES = ACE TAO TAO_CosNaming TAO_AnyTypeCode TAO_IORTable Beholder
LIB_DIRS  = $(ACE_ROOT)/lib $(HOME)/lib

ifeq ($(wildcard $(GSOAP_SOAPCPP2)),)
    $(error GSOAP_SOAPCPP2 is not found. Please specify the correct path.)
endif

PROGRAM = $(addprefix $(BINDIR)/,$(PROJECT))
IDL = $(addprefix $(IDLDIR)/,$(IDL.idl))
STUBS = $(IDL:%.idl=%C.cpp)
SKELETONS = $(IDL:%.idl=%S.cpp)
SOURCES_CLNT = $(STUBS) $(SOURCES.cpp)
SOURCES = $(SOURCES_CLNT)
ifeq ($(SERVER),true)
	SOURCES += $(SKELETONS)
endif
OBJECTS = $(SOURCES:%.cpp=%.cgi)
GENERATED = $(STUBS) $(STUBS:%.cpp=%.h) $(STUBS:%.cpp=%.inl) $(OBJECTS) $(PROGRAM)
ifeq ($(SERVER),true)
	GENERATED += $(SKELETONS) $(SKELETONS:%.cpp=%.h) $(SKELETONS:%.cpp=%.inl)
	LIBRARIES += TAO_PortableServer
endif

INCS = $(foreach d, $(INCLUDES), -I$d)
LIBS = $(foreach l, $(LIBRARIES), -l$l)
LIBDIRS = $(foreach d, $(LIB_DIRS), -L$d)

# C++ Adtional Compliler and Linker Flags
# -Wno-tautological-undefined-compare

CXXFLAGS += -Wall -fpermissive -std=c++20 -DWITH_NO_C_LOCALE -I$(INCLUDEDIR)
LDFLAGS +=

.SUFFIXES: .cpp .cgi
COMPILE.cpp = $(CXX) $(CXXFLAGS) $(COMPILE_INC) $(INCS)
LINK.cpp = $(CXX) $(LDFLAGS)
.cpp.cgi:
	@echo $(COMPILE_INC)
	@echo -e "Compilando $(notdir $<)"
	@$(COMPILE.cpp) -c -o $@ $<

# Rules for stubs/skeletons

%C.cpp:%.idl
	@echo -e "Gerando stubs/skeletons para $(notdir $<)"
	@tao_idl -Gstl -w -I$(IDLDIR) -o $(IDLDIR) $< 2> /dev/null

# Standard targets.

# Define the list of target .cgi files
CGI_FILES := $(patsubst %.cpp,%.cgi,$(SOURCE_FILES))

.KEEP_STATE:

all: $(PROGRAM)
objects: $(SOURCES) $(OBJECTS)
sources: $(SOURCES)
teste:
	@echo -e $(SOURCES)
$(PROGRAM): $(SOURCES.cpp) $(OBJECTS)
	@echo "OBJECTS = " ${OBJECTS}
	@echo -e $(LINK.cpp) -o $@ $(OBJECTS) $(SOURCES.cpp) $(GSOAP_GENERATION_OUTPUT) $(COMPILE_INC) $(LIBS) $(LIBDIRS)
	@$(LINK.cpp) -o $@ $(OBJECTS) $(GSOAP_GENERATION_OUTPUT) $(COMPILE_INC) $(LIBS) $(LIBDIRS)
clean:
	@echo -e "\nLimpando: $(notdir $(OBJECTS) $(PROGRAM))\n"
	@rm -f  $(OBJECTS) core $(PROGRAM)
cleanall:
	@echo -e "\nLimpando tudo : $(notdir $(GENERATED))\n"
	@rm -f core $(GENERATED)
install: ${GSOAP_GENERATION_OUTPUT}
	@echo "Installed"
${GSOAP_GENERATION_OUTPUT}: ${MSG_PROCESSOR_DIR}/${WS_INTERFACE_BUILD_TARGET}
		${GSOAP_SOAPCPP2} -d ${MSG_PROCESSOR_DIR}/Generated ${MSG_PROCESSOR_DIR}/${WS_INTERFACE_BUILD_TARGET}

	


