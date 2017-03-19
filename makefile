# first, figure out which OS we are working in (Macos = Darwin)
UNAME = $(shell uname)

LIBDIR=.
INCLUDES = -I.

ifeq ($(UNAME),Linux)
endif

#Compiler information
AR = ar
CC = gcc
CXX = g++
LD = g++
ARFLAGS = qcs
LDFLAGS = -L$(LIBDIR)
SYSLDFLAGS = -rdynamic
SHLDFLAGS = -s -export-dynamic -shared

ifeq ($(UNAME),Linux)
DEFINES += -DLINUX -D_PTHREADS
LIBAS += -ldl
FLAGS += -pthread
endif

CFLAGS = -c -g $(INCLUDES)
CXXFLAGS = -c -g $(INCLUDES)

ifeq ($(UNAME),Linux)
endif

ifeq ($(UNAME),Darwin)
endif

VPATH = obj

###########################################################################
# Define build rules
###########################################################################

.SUFFIXES:

.SUFFIXES: .o .c .cpp .h

.c.o:
	$(CC) -c $(CFLAGS) -o $(VPATH)/$*.o $*.c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $(VPATH)/$*.o $*.cpp

VPATH = obj

SOURCES = \
state.cpp \
main.cpp \
agent.cpp

# all the .o files need to be listed here.  Leave backslash off last list item
APPOBJS = \
$(VPATH)/state.o \
$(VPATH)/main.o \
$(VPATH)/agent.o

APPDEP = $(APPOBJS:.o=.d)
OBJECTS = $(APPOBJS)

APP = genQueens

# MAKEDEPEND = g++ -M $(CPPFLAGS) -o $*.d $<

all: $(APP)

# $(CXX) -MD creates a .d file and a .o file in the VPATH directory
$(APPDEP):      $(VPATH)/%.d:   %.cpp
	-mkdir -p $(VPATH)
	$(CXX) -MD $(CXXFLAGS)  -o $(@:.d=.o) $<

$(OBJECTS): $(VPATH)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(APP):  $(OBJECTS) 
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(GLIBS)

clean:
	rm -rf *.o *.d $(APP) $(VPATH)

# this generates errors on the first pass, but then these .d files
# get created for the second pass.  
include $(OBJECTS:.o=.d)
