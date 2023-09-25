# Makefile - ACE/TAO-CORBA
# ASDPC - Escola Politécnica - PUCPR
# Prof. Luiz Lima Jr.

# Modified by Gabriel Vitor Cezario

ACE_ROOT = /home/cezario/Dev/ACE_wrappers
include $(ACE_ROOT)/include/makeinclude/platform_macros.GNU

#
# Parâmetros:
#

PROJECT = cliente
SERVER = false

PROJECT_DIR = /home/cezario/Dev/Beholder
CORBA_DIR = ${PROJECT_DIR}/CORBA

IDL.idl = Beholder.idl
COMMON.cpp =
SOURCES.cpp = \
	cliente.cpp \

BINDIR = ${CORBA_DIR}/bin
IDLDIR = ${CORBA_DIR}/idl

COMMONDIR = ${CORBA_DIR}/common

INCLUDES  = $(IDLDIR) $(ACE_ROOT) $(TAO_ROOT) $(TAO_ROOT)/orbsvcs $(COMMONDIR)/include
LIBRARIES = ACE TAO TAO_CosNaming TAO_AnyTypeCode TAO_IORTable
LIB_DIRS  = $(ACE_ROOT)/lib  $(TAO_ROOT)/lib $(COMMONDIR)/lib

# Derived variables

PROGRAM = $(addprefix $(BINDIR)/,$(PROJECT))
IDL = $(addprefix $(IDLDIR)/,$(IDL.idl))
STUBS = $(IDL:%.idl=%C.cpp)
SKELETONS = $(IDL:%.idl=%S.cpp)
COMMON = $(addprefix $(COMMONDIR)/,$(COMMON.cpp))
SOURCES_CLNT = $(STUBS) $(COMMON) $(SOURCES.cpp)
SOURCES = $(SOURCES_CLNT)
ifeq ($(SERVER),true)
	SOURCES += $(SKELETONS)
endif
OBJECTS = $(SOURCES:%.cpp=%.o)
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

CPPFLAGS += -I$(COMMONDIR)/include
LDFLAGS += -L$(COMMONDIR)/lib -lbeholder

# Rules for C++.

.SUFFIXES: .cpp .o
COMPILE.cpp = $(CXX) $(CPPFLAGS) $(INCS) $(CCFLAGS)
LINK.cpp = $(CXX) $(LDFLAGS)
.cpp.o:
	@echo -e "Compilando $(notdir $<)"
	@$(COMPILE.cpp) -c -o $(<:%.cpp=%.o) $<

# Rules for stubs/skeletons

%C.cpp:%.idl
	@echo -e "Gerando stubs/skeletons para $(notdir $<)"
	@tao_idl -Gstl -w -I$(IDLDIR) -o $(IDLDIR) $< 2> /dev/null

# Standard targets.

.KEEP_STATE:

all: $(PROGRAM)
objects: $(SOURCES) $(OBJECTS)
sources: $(SOURCES)
install:
	# Copy the libraries to the desired location
	@cp -r /usr/local/lib/beholder/* ../common/lib/

	# Copy the headers to the desired location
	@cp -r /usr/local/include/beholder/* ../common/include/
teste:
	@echo -e $(SOURCES)
$(PROGRAM): $(SOURCES.cpp) $(OBJECTS)
	@echo -e "\nLinkando $(notdir $@)\n"
	@$(LINK.cpp) -o $@ $(OBJECTS) $(LIBDIRS) $(LIBS)
clean:
	@echo -e "\nLimpando: $(notdir $(OBJECTS) $(PROGRAM))\n"
	@rm -f  $(OBJECTS) core $(PROGRAM)
cleanall:
	@echo -e "\nLimpando tudo : $(notdir $(GENERATED))\n"
	@rm -f core $(GENERATED)

