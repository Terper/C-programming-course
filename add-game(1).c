#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generates a random integer between and including min and max
// https://www.geeksforgeeks.org/generating-random-number-range-c/
int generateRandomIntegerBetween(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}

// fills an array with [r1], [r2], [r1+r2]
void generateRandomAdditionQuestion(int *buffer, int min, int max)
{
  buffer[0] = generateRandomIntegerBetween(min, max);
  buffer[1] = generateRandomIntegerBetween(min, max);
  buffer[2] = buf[0] + buf[1];
}

int promptMinTerm()
{
  int minTerm = 0;
  printf("Minimum term? ");
  scanf("%d", &minTerm);
  // if user has given a unwanted answer continuesly prompt after the correct one
  while (minTerm == 0)
  {
    printf("Minimum term must be larger then zero! ");
    scanf("%d", &minTerm);
  }
  return minTerm;
}

int promptMaxTerm(int minTerm)
{
  int maxTerm = 0;
  printf("Maximum term? ");
  scanf("%d", &maxTerm);
  // if user has given a unwanted answer continuesly prompt after the correct one
  while (minTerm > maxTerm)
  {
    printf("Maximum term must be larger or equal to the minimum term that is %d! ", minTerm);
    scanf("%d", &maxTerm);
  }
  return maxTerm;
}

int main(void)
{
  int score = 0;
  int lost = 0;
  int minTerm = promptMinTerm();
  int maxTerm = promptMaxTerm(minTerm);

  // initalizes rand function
  srand(time(0));
  rand();

  // stops the loop when the user has lost
  while (lost == 0)
  {
    int question[3];
    int answer;
    // generates the question
    generateRandomAdditionQuestion(question, minTerm, maxTerm);
    printf("%d + %d = ? ", question[0], question[1]);
    scanf("%d", &answer);

    if (answer == question[2])
    {
      // user has answered correctly
      printf("Well done!\n");
      score += 1;
    }
    else
    {
      // user has answered incorrectly
      printf("Oops, that's not correct: %d + %d = %d\n", question[0], question[1], question[2]);
      lost = 1;
    }
  }
  printf("Your score: %d\n", score);
  return 0;
}