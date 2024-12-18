#include <stdio.h>

int main(void)
{
  int pyramidsAmount = 0;
  int pyramidsHeight = 0;
  printf("How many pyramids? ");
  scanf("%d", &pyramidsAmount);
  printf("Height of pyramids? ");
  scanf("%d", &pyramidsHeight);

  // start from 1 in order to get the formula 2n+1 to work for stars
  for (size_t i = 1; i <= pyramidsHeight; i++)
  {
    for (size_t j = 0; j < pyramidsAmount; j++)
    {
      // spaces before
      for (size_t k = pyramidsHeight; k >= i; k--)
      {
        printf(" ");
      }

      // stars
      for (size_t k = 0; k < 2 * i - 1; k++)
      {
        printf("*");
      }

      // spaces after
      for (size_t k = pyramidsHeight; k >= i; k--)
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}