#include <stdio.h>

int main(void)
{
  int input = 0;
  int childBenefitAmount = 0;
  int childBenefitList[] = {110, 143, 185, 214, 259};
  char singleProvider;

  printf("How many children? ");
  scanf("%d", &input);

  // loops the amount of times as there are children
  // if there are more children then 5 give them the same value as the fifth child
  for (size_t i = 0; i < input; i++)
  {
    int index = i;
    if (index > 4)
    {
      index = 4;
    }
    childBenefitAmount += childBenefitList[index];
  }

  printf("Single provider (y/n)? ");
  scanf(" %c", &singleProvider);

  if (singleProvider == 'y')
  {
    childBenefitAmount += 60 * input;
  }

  printf("You get %d\n", childBenefitAmount);
  return 0;
}