#include <stdio.h>
#include <string.h>

const int height = 4;
const int width = 10;
char board[height][width];
char *players[] = {"Player 1", "Player 2"};
const char *invalidMoves[] = {"Illegal position!", "Already taken!"};

void initialize()
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (i == (height - 1) && j == 0)
      {

        board[i][j] = 'X';
      }
      else
      {
        board[i][j] = 'O';
      }
    }
  }
}

void printBoard()
{
  // starts for loops with -1 and compares with <= since using width and height is easier then +1 everything.
  for (int i = -1; i <= height; i++)
  {
    for (int j = -1; j <= width; j++)
    {
      if (i == -1 || i == height)
      {
        if (j == -1 || j == width)
        {
          // corner
          printf("+");
        }
        else
        {
          // top and bottom
          printf("-");
        }
      }
      else if (j == -1 || j == width)
      {
        // sides
        printf("|");
      }
      else
        printf("%c", board[i][j]);
    }
  }
  printf("\n");
}

int checkMove(int move[2])
{
  int y = move[0];
  int x = move[1];

  // is outside board
  if (x <= 0 || x > width)
  {
    return 1;
  }
  if (y <= 0 || y > height)
  {
    return 1;
  }

  // already taken position
  if (board[y - 1][x - 1] == ' ')
  {
    return 2;
  }
  return 0;
};

void getMove(char name[16], int *move)
{
  printf("%s: Your move, please! (row, col): ", name);
  scanf(" %d, %d", &move[0], &move[1]);
}

void updateBoard(int move[2])
{
  int y = move[0] - 1;
  int x = move[1] - 1;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // gets all spaces up and to the left of coordinates
      if (y >= i && x <= j)
      {
        board[i][j] = ' ';
      }
    }
  }
}

int main(void)
{
  initialize();
  printf("Welcome to Chomp!\n");
  printBoard();
  int turns = 0;
  while (1)
  {
    int move[] = {-1, -1};
    int moveResult = -1;
    char player[16] = "";
    strcpy(player, players[turns % 2]);

    getMove(player, move);
    moveResult = checkMove(move);

    if (moveResult != 0)
    {
      printf("%s\n", invalidMoves[moveResult - 1]);
    }
    else
    {
      if (move[0] == height && move[1] == 1)
      {
        printf("Game over, %s has been poisoned!\n", player);
        return 0;
      }
      else
      {
        updateBoard(move);
        printBoard();
        turns = turns + 1;
      }
    }
  }
}