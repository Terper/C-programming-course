#include "utils.h"
#include <stdio.h>

int main()
{
  char input[100];
  char choice[2];
  printf("1. Check callsigns\n");
  printf("2. Remove chars\n");
  printf("Your choice? ");
  readString(choice, 2);
  printf("Enter string: ");
  readString(input, 100);

  if (choice[0] == '1')
  {
    printf("%s is %sa valid callsign\n", input, isValidCallsign(input) ? "" : "not ");
  }
  if (choice[0] == '2')
  {
    // able to reuse the choice variable
    printf("Enter char to delete: ");
    readString(choice, 2);
    deleteChar(input, choice[0]);
    printf("The resulting string is: %s\n", input);
  }
}