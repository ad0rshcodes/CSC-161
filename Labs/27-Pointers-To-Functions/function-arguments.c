#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char* cmd_name;
	void (*cmd_pointer)();
} command_t;

void printSmiles(void){
  printf(":):):)");
}

void printCompliment(void){
  printf("You are smart!");
}

void printxs(void) {
  printf("xxxx");
}

void printInts(void){
  printf("1 2 3 4 5 6 7 8 9");
}

void printNames(void) {
  printf("Ngoc, Adarsh");
}

command_t print_cmds[] = {
	{"smile", printSmiles},
	{"compliment", printCompliment},
	{"x", printxs},
        {"integers", printInts},
        {"names", printNames}
};

void execute_command(const char* cmd){
  int size = sizeof(print_cmds) / sizeof(command_t);
  bool found = false;
  
  for (int i = 0; i < size; i++){
    
    if (strcmp(cmd, print_cmds[i].cmd_name) == 0) {
      print_cmds[i].cmd_pointer();
      printf("\n");
      found = true;
    }
    
  }

  if (found == false){
    printf("Not found\n");
  }
}

int main(void){
  execute_command("integers");
  execute_command("sads");


  return 0;
}
