#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calculateFrequencies(const char *string, int *frequencies)
{
  // - 1 in order to skip the line feed character
  for (int i = 0; i < strlen(string) - 1; i++)
  {
    // adds 1 to index of the chars integer value
    int index = (int)string[i];
    frequencies[index] = frequencies[index] + 1;
  }
}

void printfFrequencies(int *frequencies)
{
  for (int i = 0; i < 256; i++)
  {
    // skips empty characetrs
    if (frequencies[i] != 0)
    {
      printf("%c (ASCII %d): Found %d\n", i, i, frequencies[i]);
    }
  }
  free(frequencies);
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