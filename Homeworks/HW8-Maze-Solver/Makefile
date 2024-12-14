CC := clang


mazeSolver: main.o maze.o print_util.o stack.o
	$(CC) -o mazeSolver main.o maze.o print_util.o stack.o

main.o: main.c
	$(CC) -c main.c

maze.o: maze.c maze.h
	$(CC) -c maze.c

print_util.o: print_util.c print_util.h
	$(CC) -c print_util.c

stack.o: stack.c stack.h
	$(CC) -c stack.c

clean:
	rm -rf mazeSolver main.o maze.o print_util.o stack.o

.PHONY: clean