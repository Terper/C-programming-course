#include <stdio.h>

int main(void)
{
  int startingInvestment = 0;
  int target = 0;
  double rate = 0;
  int years = 0;
  int totalInvestment = 0;
  printf("Starting investment? ");
  scanf("%d", &startingInvestment);
  printf("Taget? ");
  scanf("%d", &target);
  printf("Rate? ");
  scanf("%lf", &rate);
  startingInvestment = startingInvestment * 100;
  target = target * 100;
  rate = rate / 100 + 1;
  totalInvestment = startingInvestment;

  // run until totalInvestment has reached target
  do
  {
    totalInvestment = totalInvestment * rate;
    years = years + 1;
    printf("After year %d: %d.%02d\n", years, (int)totalInvestment / 100, (int)totalInvestment % 100);
  } while (totalInvestment < target);

  return 0;
}