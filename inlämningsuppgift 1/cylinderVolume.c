#include <stdio.h>
#include "../input.h"
#include <math.h>

// https://docs.google.com/document/d/1ulhn-GwYo3Z-BNgoa_ttA7snqRyOaG5pNOhPiIKQ-q0/edit#
// https://cplusplus.com/reference/cstdio/printf/ formatting for precision


int main (void) {
  printf("Height (mm)? ");
  int height = readInt();
  printf("Radius (mm)? ");
  int radius = readInt();
  printf("Side thickness (mm)? ");
  int sideThickness = readInt();
  printf("Top thickness (mm)? ");
  int topThickness = readInt();
  printf("Bottom thickness (mm)? ");
  int bottomThickness = readInt();

  // formula to get cubic mililiters
  int innerVolume = M_PI * pow(radius - sideThickness, 2) * (height - topThickness - bottomThickness);
  // converts cuvic mililiters to liters
  double innerVolumeLiter = innerVolume * 0.000001;

  // ".3" specifies the number of digits to be printed after the decimal point 
  printf("Inner volume: %.3f liters\n", innerVolumeLiter);
  return 0;
}