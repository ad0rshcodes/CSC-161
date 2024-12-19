#include "string_queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initialize an empty queue of strings
 * 
 * \param q A pointer to a string_queue_t that should be initialized.
 */
void string_queue_init(string_queue_t* q) {
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
}

/**
 * Destroy a queue that holds strings
 * 
 * \param q A pointer to an initialized string_queue_t that should be destroyed.
 */
void string_queue_destroy(string_queue_t* q) {
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
}

/**
 * Add a string to the back of the queue
 * 
 * \param q   A pointer to an initialized string queue. The new value is added to the back of the 
 *            queue. This function does NOT take ownership of q.
 * \param str A heap-allocated string that should be added to the queue. This function takes 
 *            ownership of str, and will free the underlying memory in string_queue_destroy.
 */
void string_queue_add(string_queue_t* q, char* str) {
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
}

/**
 * Take a string from the front of the queue and return it
 * 
 * \param q A pointer to an initialized string queue. The string at the front of the queue will be 
 *          removed and returned.
 * \returns an owning pointer to the string taken from the queue, or NULL if the queue was empty.
 */
char* string_queue_take(string_queue_t* q) {
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
  return NULL;
}

/**
 * Get the string at the front of the queue, but do not remove it
 * 
 * \param q A pointer to an initialized string queue. The string at the front of the queue will be 
 *          returned, but the queue is not modified.
 * \returns a borrowed pointer to the string at the front of the queue, or NULL if the queue is empty.
 */
char* string_queue_peek(const string_queue_t* q) {
  // TODO: implement me
  printf("NOT IMPLEMENTED\n");
  return NULL;
}
