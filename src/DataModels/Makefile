# Makefile - Beholder source

#
# Parâmetros:
#

PROJECT = Beholder

SOURCES.cxx = \
	BeholderI.cxx \
	servidor.cxx \

# C++ Adtional Compliler and Linker Flags
# -Wno-tautological-undefined-compare

CPPFLAGS +=
LDFLAGS +=

# Rules for C++.

.SUFFIXES: .cxx .o
COMPILE.cxx = $(CXX) $(CPPFLAGS) $(INCS) $(CCFLAGS)
LINK.cxx = $(CXX) $(LDFLAGS)
.cxx.o:
	@echo -e "Compilando $(notdir $<)"
	@$(COMPILE.cxx) -c -o $(<:%.cxx=%.o) $<

# Detect built
OBJECTS = $(SOURCES:%.cxx=%.o)

.KEEP_STATE:

all: $(PROGRAM)
objects: $(SOURCES) $(OBJECTS)
sources: $(SOURCES)
teste:
	@echo -e $(SOURCES)
$(PROGRAM): $(SOURCES.cxx) $(OBJECTS)
	@echo -e "\nLinkando $(notdir $@)\n"
	@$(LINK.cxx) -o $@ $(OBJECTS)
clean:
	@echo -e "\nLimpando: $(notdir $(OBJECTS))\n"
	@rm -f  $(OBJECTS)

