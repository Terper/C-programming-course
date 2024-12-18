#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // to add more players add more chars in players array
  // example: char players[] = {'X', 'O', 'F'};
  char players[] = {'X', 'O'};
  int height = -1;
  int width = -1;

  printf("Height of board? ");
  while ((scanf(" %d", &height)) == -1)
    ;
  printf("Width of board? ");
  while ((scanf(" %d", &width)) == -1)
    ;

  // initialize board
  char(*board)[width] = malloc(sizeof *board * width);

  // fill board with spaces
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      board[i][j] = ' ';
    }
  }

  int possibleTurns = width * height;
  int turns = 0;

  while (turns < possibleTurns)
  {
    int x;
    int y;
    int legalInput = 0;
    char currentPlayer = players[turns % sizeof players / sizeof players[0]];
    while (legalInput == 0)
    {
      x = -1;
      y = -1;
      int inputX = -1;
      int inputY = -1;
      printf("%c, make your move (row, col): ", currentPlayer);
      scanf(" %d %d", &inputX, &inputY);

      // input validation
      if (inputX > 0 && inputX <= width)
      {
        x = inputX - 1;
      }
      if (inputY > 0 && inputY <= width)
      {
        y = inputY - 1;
      }
      if (x != -1 && y != -1)
      {
        // check if space is already filled
        if (board[x][y] == ' ')
        {
          // input is valid
          legalInput = 1;
        }
      }
    }
    // add char to board
    board[x][y] = currentPlayer;

    // paint board
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        printf(" ");
        if (j != 0)
        {
          printf("| ");
        }
        printf("%c", board[i][j]);
      }
      printf("\n");
      if (i != width - 1)
        for (size_t j = 0; j < width; j++)
        {
          if (j != width - 1)
          {
            printf("-");
          }
          printf("---");
        }
      printf("\n");
    }
    turns = turns + 1;
  }

  printf("Board full, exiting!\n");
}