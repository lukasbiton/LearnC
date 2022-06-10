/*
Returns the sine for a given value between 0 and 1 non-inclusive.
Author: Lukas Biton
Date: 19/11/2021
*/

#include <stdio.h>

int main(void){
  // Initialize the value to sine
  double x; // read any number between 0 and 1, need a double
  double sin_x; // sine will return value between 0 and 1, need a double
  printf("Enter the value to sine: ");
  scanf("%lf", &x);

  // Let's use the Taylor series approximation up to the seventh degree
  // Make sure to use some floats in there
  sin_x = x - (x * x * x) / (3 * 2) + (x * x * x * x * x) /
        (5 * 4 * 3 * 2) - (x * x * x * x * x * x * x) / (7 * 6 * 5 * 4 * 3 * 2);
  printf("The sine of %lf is %lf.", x, sin_x);
  return 0;
}
