#include <stdio.h>
#include <math.h>
#include "../input.h"

// https://docs.google.com/document/d/1ulhn-GwYo3Z-BNgoa_ttA7snqRyOaG5pNOhPiIKQ-q0/edit#

// https://sv.wikipedia.org/wiki/Dolbears_lag
// https://en.wikipedia.org/wiki/Dolbear%27s_law


// Doelbear's law in Fahrenheit
int calculateTemperatureF (int chirps) {
  return 50 + ((chirps - 40) / 4);
}

// tc = 10 + ((N60 - 40) / 7)
// Doelbear's law in Celsius
int calculateTemperatureC (int chirps) {
  float result = 10 + ((chirps - 40)/ 7);
  return floor(result);
}

// the english wikipedia page for Dolbear´s law uses a different formula
int calculateTemperatureCEngWiki (int chirps) {
  return (chirps + 30) / 7;
}

int main (void) {
  printf("How many chirps in 60 seconds? ");
  int chirps = readInt();
  printf("The estimated temperature is %d\n", calculateTemperatureC(chirps));
  return 0;
}