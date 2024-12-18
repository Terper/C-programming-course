#include <stdio.h>
#include "../input.h"

// https://docs.microsoft.com/en-us/cpp/c-language/sizeof-operator-c?view=msvc-170
// sizeof(array) / sizeof(array[0]) gets the length of an array

int main (void) {
  double numbers[5];
  double sum;
  int i;
  printf("Enter 5 numbers\n");
  for (i = 0; i < 5; i++) {
    printf("number %d > ", i+1);
    numbers[i] = readDouble();
  }
  for (i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++){
    sum += numbers[i];
  }
  printf("average is %.3f\n", sum / (sizeof(numbers)/sizeof(numbers[0])));
}