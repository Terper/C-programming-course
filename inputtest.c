#include "input.h"
#include <stdio.h>

int main(void) {
  printf("Please enter a value: ");
  int input = readInt();
  printf("You entered %d\n", input);

  return 0;
}