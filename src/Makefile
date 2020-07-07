#
# Makefile
# wlz
#

CC=gcc

OBJECTS= staa.o exec.o make_frame.o make_func.o other.o 

all: staa
	@echo "stack vm interpreter"

staa: $(OBJECTS)	
	$(CC) -o staa $(OBJECTS)



.PHONY : clean
clean: 
	rm staa $(OBJECTS)
