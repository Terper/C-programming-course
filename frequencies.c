#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calculateFrequencies(const char *string, int *frequencies)
{
  int *frequenciesStart = frequencies;
  while (*string != '\n')
  {
    // sets the pointer to the ascii value of current string
    frequencies = frequencies + *string;
    // adds 1 to the value
    *frequencies = *frequencies + 1;
    // next value
    string++;
    // sets the pointer to start
    frequencies = frequenciesStart;
  }
}

void printfFrequencies(int *frequencies)
{
  // have to run 256 times to get all ascii characters
  for (int i = 0; i < 256; i++)
  {
    // check if pointer has a value over 0
    if (*frequencies > 0)
    {
      printf("%c (ASCII %d): Found %d\n", i, i, *frequencies);
    }
    // next value
    frequencies++;
  }
}

int main()
{
  const int max = 1024;
  char *input = malloc(sizeof(char) * max);
  int *frequencies = malloc(sizeof(int) * 256);
  printf("Input a string: ");
  fgets(input, max, stdin);
  calculateFrequencies(input, frequencies);
  free(input);
  printfFrequencies(frequencies);
}