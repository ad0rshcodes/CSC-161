CC := clang
CFLAGS := -g
CFLAGS_ASAN := $(CFLAGS) -fsanitize=address

all: stack stack-asan queue queue-asan

clean:
	rm -rf stack stack-asan queue queue-asan stack.dSYM stack-asan.dSYM queue.dSYM queue-asan.dSYM

stack: stack-driver.c string_stack.h string_stack.c
	$(CC) $(CFLAGS) -o stack stack-driver.c string_stack.c

stack-asan: stack-driver.c string_stack.h string_stack.c
	$(CC) $(CFLAGS_ASAN) -o stack-asan stack-driver.c string_stack.c

queue: queue-driver.c string_queue.h string_queue.c
	$(CC) $(CFLAGS) -o queue queue-driver.c string_queue.c

queue-asan: queue-driver.c string_queue.h string_queue.c
	$(CC) $(CFLAGS_ASAN) -o queue-asan queue-driver.c string_queue.c

.PHONY: all clean
