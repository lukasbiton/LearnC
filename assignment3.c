/*
Print a table of values for sine and cosine between 0 and 1.
*/

#include <stdio.h>
#include <math.h>

int main()
{
  double i, step;
  printf("Enter a step size for the table of sine and cosine: ");
  scanf("%lf", &step);
  printf("------------------------\n");
  for (i = 0.0; i <= 1.0; i += step)
  {
    printf("sin(%lf) = %lf, cos(%lf) = %lf\n", i, sin(i), i, cos(i));
  };
  printf("------------------------");
  return 0;
}
