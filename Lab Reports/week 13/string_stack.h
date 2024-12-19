#pragma once

#include <stdbool.h>
#include <stdlib.h>

/// A string stack
typedef struct string_stack {
  char** arr;
  int length;
  int capacity; 
} string_stack_t;


/// Initialize an empty stack of strings
void string_stack_init(string_stack_t* s);

/// Destroy a stack that holds strings
void string_stack_destroy(string_stack_t* s);

/// Push a string to the top of the stack
void string_stack_push(string_stack_t* s, char* str);

/// Pop a string from the top of the stack and return it
char* string_stack_pop(string_stack_t* s);

/// Get the string on the top of the stack, but do not remove it from the stack
char* string_stack_peek(const string_stack_t* s);
