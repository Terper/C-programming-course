#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkIfContains(int numToCheck, int *arr, int arrLength)
{
  for (int i = 0; i < arrLength; i++)
  {
    if (arr[i] == numToCheck)
    {
      return 1;
    }
  }
  return 0;
}

void sortRow(int *arr, int arrLength)
{
  // insertion sort based of the wikipedia pages pseudocode
  int i = 1;
  while (i < arrLength)
  {
    int x = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > x)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = x;
    i = i + 1;
  }
}

void enterRow(int *arr, int arrLength, int max)
{
  // Prompts user for input and checks if it is unique and not higher then max
  printf("Enter your lotto row (%d values between 1-%d)\n", arrLength, max);
  for (size_t i = 0; i < arrLength; i++)
  {
    int input = -1;
    scanf(" %d", &input);
    if (checkIfContains(input, arr, arrLength))
    {
      printf("Duplicate, try again!\n");
      i--;
    }
    else if (input > max)
    {
      printf("Must be between 1-%d\n", max);
      i--;
    }
    else
    {
      arr[i] = input;
    }
  }
}

void generateRow(int *arr, int arrLength, int max)
{
  /*
    Generates random number, uses the checkIfContains function
    to check if it has already been generated.
  */
  for (int i = 0; i < arrLength; i++)
  {
    int randomNumber = (rand() % max) + 1;
    if (checkIfContains(randomNumber, arr, arrLength))
    {
      i--;
    }
    else
    {
      arr[i] = randomNumber;
    }
  }
}

void printRow(int *arr, int arrLength)
{
  for (int i = 0; i < arrLength; i++)
  {
    printf("%d ", arr[i]);
  }
}

int countMatches(int *arr1, int *arr2, int arrLength)
{
  // loops trough the first array and uses the function to check if value matches
  int matches = 0;
  for (int i = 0; i < arrLength; i++)
  {
    if (checkIfContains(arr1[i], arr2, arrLength))
    {
      matches++;
    }
  }
  return matches;
}

int main(void)
{
  // configurables
  const int rowLength = 7;
  const int max = 39;

  // init rows
  int userRow[rowLength] = {};
  int generatedRow[rowLength] = {};

  // init random
  srand(time(0));
  rand();

  // user row
  enterRow(userRow, rowLength, max);
  sortRow(userRow, rowLength);
  printf("\n\nYour row: ");
  printRow(userRow, rowLength);

  // generated row
  printf("\nPlease wait, generating the winning row...\n");
  generateRow(generatedRow, rowLength, max);
  sortRow(generatedRow, rowLength);

  // results
  printf("Winning row: ");
  printRow(generatedRow, rowLength);
  printf("\nYou got %d matching numbers.\n", countMatches(userRow, generatedRow, rowLength));
}