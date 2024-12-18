#include <stdio.h>
#include "../input.h"

// this assignment would be much prettier using arrays and loops
// but since the variables have to be seperate that is not an option

int main (void) {
  printf("Enter 5 single-digit integers separated by commas: ");
  int numC0 = readInt(); 
  int numC1 = readIntAfter(',');
  int numC2 = readIntAfter(',');
  int numC3 = readIntAfter(',');
  int numC4 = readIntAfter(',');
  int combined = numC0* 10000 + numC1*1000 + numC2*100 + numC3*10 + numC4;
  printf("The combined 5-digit value is: %d\n", combined);

  printf("Now enter one 5-digit integer: ");
  int multiple = readInt();
  int numM0 = (int) multiple / 10000;
  int numM1 = (int) multiple / 1000 - numM0*10;
  int numM2 = (int) multiple / 100 - numM0*100 - numM1*10;
  int numM3 = (int) multiple / 10 - numM0*1000 - numM1*100 - numM2*10;
  int numM4 = (int) multiple / 1 - numM0*10000 - numM1*1000 - numM2*100 - numM3*10;
  printf("The single-digit values are %d, %d, %d, %d, %d\n", numM0, numM1, numM2, numM3, numM4);
} 