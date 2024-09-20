#include <stdio.h>

int glob = 4;

void g() {
  // Point (B)---first call to g()
  for (int i = 0; i < glob; i++) {
    printf("%d ", i);
  }
  printf("\n");
  glob += 1;
  // Point (C)---final call to g()
}

int f() {
  for (int i = 0; i < glob; i += 2) {
    // Point (A)---first iteration of the for-loop
    g();
    printf("===\n");
  }
  return glob;
}

int main() {
  int ret = f();
  // Point (D)

  return 0;
}