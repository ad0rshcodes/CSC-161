#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_queue.h"

/**
 * Check to see if a line of input matches a command followed by a singe string argument.
 * 
 * \param cmd The command to check against
 * \param line The line being checked
 * \returns NULL if there is no match, or a pointer to the argument if the command does match.
 */
const char* check_command(const char* cmd, const char* line) {
  // If the line doesn't begin with cmd, return an error
  if (strncmp(cmd, line, strlen(cmd)) != 0) return NULL;

  // Check for a space after the command
  if (line[strlen(cmd)] != ' ') {
    printf("Error: Missing argument.\n");
    return NULL;
  }

  // Make sure the argument isn't empty
  if (strlen(line) < strlen(cmd) + 2) {
    printf("Error: Empty argument.\n");
    return NULL;
  }

  // Return the argument
  return line + strlen(cmd) + 1;
}

void show_help() {
  printf("Commands:\n");
  printf("  help: show this message\n");
  printf("  add <str>: add a string to the back of the queue\n");
  printf("  take: take the string from the front of the queue and print it\n");
  printf("  peek: print the string at the front of the queue without removing it\n");
  printf("  exit: exit the program\n");
}

int main() {
  // Create a queue and initialize it
  string_queue_t q;
  string_queue_init(&q);

  printf("Enter a command. Type \"help\" to see available options.\n");

  // Print a command prompt line:
  printf("> ");
  fflush(stdout);

  // Use getline to read commands from the user
  char* line = NULL;
  size_t line_capacity = 0;
  ssize_t line_length;
  while ((line_length = getline(&line, &line_capacity, stdin)) != -1) {
    // Remove the trailing newline from line by overwriting it with a null terminator
    line[line_length-1] = '\0';

    // A temporary string used for some command handling
    const char* arg;

    // Check for commands
    if (strcmp(line, "help") == 0) {
      // Show a help message
      show_help();

    } else if (strcmp(line, "take") == 0) {
      // Take the oldest item from the queue
      char* str = string_queue_take(&q);
      if (str == NULL) {
        printf("Queue was empty\n");
      } else {
        printf("Took \"%s\"\n", str);
        free(str);
      }

    } else if (strcmp(line, "peek") == 0) {
      // Peek at the front element of the queue
      char* str = string_queue_peek(&q);
      if (str == NULL) {
        printf("Queue was empty\n");
      } else {
        printf("The front of the queue is \"%s\"\n", str);
      }

    } else if ((arg = check_command("add", line)) != NULL) {
      // Add a new string to the queue
      // Use strdup because the queue takes ownership of arg
      string_queue_add(&q, strdup(arg));
    
    } else if (strcmp(line, "exit") == 0) {  
      // Exit the command loop
      break;
    
    } else {
      printf("Unrecognized command.\n");
      show_help();
    }

    // Print a command prompt line:
    printf("> ");
    fflush(stdout);
  }

  // Clean up after getline
  free(line);

  // Clean up the queue
  string_queue_destroy(&q);

  return 0;
}
