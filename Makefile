#
# PAXCC Makefile
#

# select the C++ compiler to go 
CC=g++

# compile, warn on all errors, and add debug symbols
CFLAGS=-c -Wall -g3
# compile, warn on all errors, and optimize by level 3
#CFLAGS=-c -Wall -O3

# if needed, add some linker flags
LDFLAGS=

# the src dir to start from
SRCDIR=.

# the output dir for the documentation generation
DOC=./doc

# search for all files ending with .cpp
SOURCES= $(shell find $(SRCDIR)/ | grep ".cpp" | grep -v "^./doc/")

# exchange the ending to .o for all found files
OBJECTS=$(SOURCES:.cpp=.o)

# set the name of the executable
EXECUTABLE=paxcc_example

all: $(SOURCES) $(EXECUTABLE)	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(DOC)/*
	rm -f $(SRCDIR)/$(EXECUTABLE) 
	rm -f $(SRCDIR)/$(OBJECTS)
	
refresh:
	make clean
	date
	make all
	date

docu:
	doxygen .doxyfile.conf


