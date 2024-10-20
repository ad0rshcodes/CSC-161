#include <stdio.h>
#include "chicken.h"
#include "util.h"

// Make a chicken sound a specified number of times
void chicken_sound(int count) {
  make_sound("cluck", count);
}


// farm.c used the chicken_sound defined in chicken.c
