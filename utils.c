#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define formatBool(b) ((b) ? "true" : "false")

void deleteChar(char string[], char charToDelete)
{
  // create a buffer array that gets filled by going trough the input
  // appends chars if they are not charToDelete
  int stringLength = strlen(string);
  char *buffer = malloc(stringLength);
  int i = 0;
  int j = 0;
  while (i < stringLength)
  {
    if (string[i] != charToDelete)
    {
      buffer[j] = string[i];
      j++;
    }
    i++;
  }
  strcpy(string, buffer);
}

// copies the buffer array to the input array when finished
bool isValidCallsign(char callsign[])
{
  // check if hyphen in in the right place
  int hyphenIndex = -1;
  if (callsign[2] == '-')
  {
    hyphenIndex = 2;
  }
  if (callsign[3] == '-')
  {
    hyphenIndex = 3;
  }
  if (hyphenIndex == -1)
  {
    return false;
  }

  // checks if correct amount of numbers after hyphen
  int callsignLength = strlen(callsign);
  int numberAmount = callsignLength - hyphenIndex - 1;
  if (numberAmount < 3 || numberAmount > 6)
  {
    return false;
  }

  // checks if letters before hyphen are actual valid letters
  for (int i = 0; i < hyphenIndex; i++)
  {
    if (callsign[i] < 'A' || callsign[i] > 'Z')
    {
      return false;
    }
  }
  // checks if numbers after hyphen are actual valid numbers
  for (int i = hyphenIndex + 1; i < callsignLength; i++)
  {
    if (callsign[i] < '0' || callsign[i] > '9')
    {
      return false;
    }
  }

  return true;
}

void readString(char input[], int length)
{
  fgets(input, length, stdin);
  int inputLength = strlen(input);
  if (input[inputLength - 1] == '\n')
  {
    input[inputLength - 1] = '\0';
  }
  else
  {
    while (getchar() != '\n')
      ;
  }
}