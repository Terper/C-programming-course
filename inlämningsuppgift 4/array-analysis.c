#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n = -1;
  int m = -1;
  printf("Size of array? ");
  while ((scanf(" %d", &n)) == -1)
    ;
  printf("Max value in array? ");
  while ((scanf(" %d", &m)) == -1)
    ;

  // https://stackoverflow.com/questions/17937623/initializing-c-dynamic-arrays
  // initalize array for numbers
  int *values = malloc(sizeof(int) * n);

  printf("Please eneter %d values between 1 and %d:\n", n, m);

  for (size_t i = 0; i < n; i++)
  {
    scanf(" %d", &values[i]);
  }

  // generate required values
  int *requiredValues = malloc(sizeof(int) * m);
  for (size_t i = 0; i < m; i++)
  {
    requiredValues[i] = i + 1;
  }

  printf("Missing values: ");

  // go through all the required values and check if they are in the array
  // print the required value if it is missing in the values array
  int noneMissing = 1;
  for (size_t i = 0; i < m; i++)
  {
    int isInArray = 0;
    for (size_t j = 0; j < n; j++)
    {
      if (values[j] == requiredValues[i])
      {
        isInArray = 1;
      }
    }
    if (isInArray == 0)
    {
      printf("%d ", requiredValues[i]);
      noneMissing = 0;
    }
  }
  if (noneMissing == 1)
  {
    printf("None!");
  }
  printf("\n");
  return 0;
}