#BASEDIR = .
INC = -I./include
#SRC = $(BASEDIR)/src

CC = g++
CFLAGS  = -Wall -g

SRCS = $(shell find . -name "*.cpp")
#SRCS = main.cpp PE_Signature/peheader.cpp dosheader.cpp datadirectory.cpp fileheader.cpp ntheader.cpp optionalheader.cpp importtable.cpp sectionheader.cpp peloader.cpp pefile.cpp peprinter.cpp 
OBJS = $(SRCS:.cpp=.o)

MAIN = pe

default: all

all: $(MAIN) clean_object

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(MAIN) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean_object:
	rm $(OBJS)

clean:
	rm $(OBJS) pe

print_src:
	echo $(SRCS)