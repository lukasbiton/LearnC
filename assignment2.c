/*
Return the absolute value of the sine over an interval.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  double interval;
  int i;
  for (i = 0; i < 30; i++)
  {
    interval = i/10.0;
    printf("sin(%lf) = %lf\n", interval, fabs(sin(interval))); // use fabs for abs on floats, and abs for abs on ints
  }

  printf("++++++++++++++++++++++++\n");
  return 0;
}
