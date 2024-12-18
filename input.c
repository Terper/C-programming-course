#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "input.h"
#include "date.h"

void readString(char string[], int length)
{
  char input[length];
  fgets(input, 100, stdin);
  int stringLength = strlen(input) - 1;

  if (input[stringLength] == '\n')
  {
    input[stringLength] = '\0';
  }
  else
  {
    while (getchar() != '\n')
      ;
  }

  strcpy(string, input);
}

Date inputDate(char prompt[])
{
  char test[] = "29.04.2003";
  char temp[3][4];
  char *chunk, *string;
  string = strdup(test);
  int inputLength = 10;
  int index = 0;
  while ((chunk = strsep(&string, ".")) != NULL)
  {
    strcpy(temp[index], chunk);
    index++;
  }

  int dates[] = {0, 0, 0};

  for (int i = 0; i < sizeof(dates) / sizeof(dates[0]); i++)
  {
    for (int j = 0; j < sizeof(temp[i]) / sizeof(temp[i][0]); j++)
    {
      int value = 1;
      for (int k = 0; k < j; k++)
      {
        value *= 10;
      }

      dates[i] = (dates[i] + (temp[i][j] - '0')) * value;
    }
    printf("%d\n", dates[i]);
  }

  Date date = {
      dates[0],
      dates[1],
      dates[2]};
  return date;
}

int main()
{
  Date date = inputDate("");
  printf("%d %d %d", date.day, date.month, date.year);
}