/*
Play around with calculating stuff.
*/

#include <stdio.h>

int foobar(int *n){
  *n = *n +1;
  return *n;
}

int mystery(int p, int q){

    int r;
    if ((r = p % q) == 0)
        return q;
    else return mystery(q, r);
}

int main(void)
{
  int k = 10;
  int n = &k;
  printf("%d", n);
  printf(" k = %d\n", k);
  printf("foobar(k) = %d,", *&k + 1 );
  printf(" k = %d\n", k);
  printf("%d\n", mystery(7, 95));
}
