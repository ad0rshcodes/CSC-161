CC := clang
CFLAGS :=

all: quadratic reduce

clean:
	rm -f quadratic reduce

quadratic: quadratic.c
	$(CC) $(CFLAGS) -o quadratic quadratic.c -lm

reduce: reduce.c
	$(CC) $(CFLAGS) -o reduce reduce.c

.PHONY: all clean
