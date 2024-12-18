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

// Doelbear's law in Celsius
int calculateTemperatureC (int chirps) {
  double a = chirps-40;
  double b = a / 7;
  double c = 10 + b;
  return round(c);
}

// the english wikipedia page for Dolbear´s law uses a different formula
int calculateTemperatureCEngWiki (int chirps) {
  double a = chirps + 30;
  double b = a / 7;
  return round(b);
}

int main (void) {
  printf("How many chirps in 60 seconds? ");
  int chirps = readInt();
  printf("The estimated temperature is %d\n",  calculateTemperatureC(chirps));
  return 0;
}