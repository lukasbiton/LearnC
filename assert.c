/*
Learning how to use assert.
*/

// #define NDEBUG // Do this before the assert and turns them off
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int old_main()
{
  assert(0);
  printf("My program runs.\n\n");
  return 0;
}
 int main()
 {
   double x, y;
   while(1)
   {
     printf("Read in 2 floats:\n");
     scanf("%lf %lf", &x, &y);
     assert(y != 0);
     printf("When divided, x/y = %lf\n", x/y);
   }
   return 0;
 }
