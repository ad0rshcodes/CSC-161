CC := clang
CFLAGS := -g
CFLAGS_ASAN := $(CFLAGS) -fsanitize=address

all: arraylist-practice arraylist-practice-asan

clean:
	rm -rf arraylist-practice arraylist-practice-asan arraylist-practice.dSYM arraylist-practice-asan.dSYM

arraylist-practice: main.c string_list.h string_list.c
	$(CC) $(CFLAGS) -o arraylist-practice main.c string_list.c

arraylist-practice-asan: main.c string_list.h string_list.c
	$(CC) $(CFLAGS_ASAN) -o arraylist-practice-asan main.c string_list.c

.PHONY: all clean
