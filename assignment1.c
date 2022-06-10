/*
First assignment
*/

#include<stdio.h>
#define PI 3.14159

int main(void)
{
  int radius;
  int a = 2;
  radius = 3.6 + a * a;
  printf("%d", radius);
  printf("Enter radius:");
  scanf("%d", &radius);
  printf("volume is: %lf\n\n", 4 * radius * radius * radius / 3.);
  return 0;
}
