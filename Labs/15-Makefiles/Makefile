# Variables
CC = clang
CFLAGS = -g -MMD -MP

# List all source files 
SRC = farm.c chicken.c cow.c sheep.c util.c

# Corresponding object files
OBJ = farm.o chicken.o cow.o sheep.o util.o

# target
all: farm

# Linking the final executable
farm: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# creating .o files from .c files (with dependency generation)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Include the generated .d files
-include $(OBJ:.o=.d)

# Phony targets
.PHONY: clean

clean:
	rm -f farm $(OBJ) *.d
