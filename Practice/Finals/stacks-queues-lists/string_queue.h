#pragma once

#include <stdbool.h>
#include <stdlib.h>

/// A string stack
typedef struct string_queue {
  // TODO: implement me
} string_queue_t;

/// Initialize an empty queue of strings
void string_queue_init(string_queue_t* q);

/// Destroy a stack that holds strings
void string_queue_destroy(string_queue_t* q);

/// Add a string to the back of the queue
void string_queue_add(string_queue_t* q, char* str);

/// Take a string from the front of the queue and return it
char* string_queue_take(string_queue_t* q);

/// Get the string at the front of the queue, but do not remove it
char* string_queue_peek(const string_queue_t* q);
