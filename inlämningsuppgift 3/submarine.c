#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char letters[] = "ABCDEFGHIJ";

// https://stackoverflow.com/questions/3217629/how-do-i-find-the-index-of-a-character-within-a-string-in-c#:~:text=Just%20subtract%20the%20string%20address,example%20it%20will%20be%202.
int getIndexOfLetter(char letter)
{
  char *c;
  c = strchr(letters, letter);
  return (int)(c - letters);
}

int main(void)
{
  int tries = 0;
  srand(time(NULL));
  rand();
  int subX = rand() % 10;
  int subY = rand() % 10;

  printf("The submarine is hiding at the ocean floor.\nYou have five depth charges. Try to sink the submarine!\n");

  // debug help
  // printf("sub localisation %c %d\n", letters[subX], subY + 1);

  while (tries < 5)
  {
    int x;
    int y;
    int isLegal = 0;
    // keep looping until input is legal
    while (isLegal == 0)
    {
      char inputX;
      int inputY;
      printf("Where to try next (col, row)? ");
      scanf(" %c %d", &inputX, &inputY);
      // check if input is legal
      // y inbetween 1 and 10
      // strchr return null if the char is not found
      if (inputY >= 1 && inputY <= 10 && strchr(letters, inputX) != NULL)
      {
        isLegal = 1;
        y = inputY - 1;
        x = getIndexOfLetter(inputX);
      }
      if (isLegal == 0)
      {
        printf("Sorry, illegal input.\n");
      }
    }

    // checks if submarine is hit
    if (x == subX && y == subY)
    {
      printf("Well done, you sank the submarine in %d tries!\n", tries + 1);
      return 0;
    }

    // checks in what direction submarine is located compared to the missile
    char direction[10] = "";
    if (y > subY)
    {
      strcat(direction, "north");
    }
    else if (y < subY)
    {
      strcat(direction, "south");
    }
    if (x < subX)
    {
      strcat(direction, "east");
    }
    else if (x > subX)
    {
      strcat(direction, "west");
    }

    printf("Miss. Sonar indicates that the submarine is located %s of your current position.\n", direction);
    tries++;
  }
  printf("You are out of depth charges. The submarine escaped!\n");
  return 0;
}