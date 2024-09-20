CC := clang
CFLAGS :=

all: quadratic array-params globals

clean:
	rm -f quadratic array-params globals

quadratic: quadratic.c
	$(CC) $(CFLAGS) -o quadratic quadratic.c -lm

array-params: array-params.c
	$(CC) $(CFLAGS) -o array-params array-params.c

globals: globals.c
	$(CC) $(CFLAGS) -o globals globals.c

.PHONY: all clean
