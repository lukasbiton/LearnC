/*
recursive Fibonacci sequence
*/

#include <stdio.h>

long fibonacci(int n)
{
  long f2 = 0, f1 = 1, f_old;
  int i;

  for (i = 0; i < n; i++)
  {
    f_old = f2;
    f2 = f2 + f1;
    f1 = f_old;
  };
  return f2;
}

long recursive_fibonacci(int n)
{
  if (n <= 1)
    return n;
  else
    return(recursive_fibonacci(n-1) + recursive_fibonacci(n-2));
}

int main(void)
{
  int how_many = 0, i;
  printf("I want a table of the fibonacci sequence up to n: ");
  scanf("%d", &how_many);
  printf("\nfibonacci\n");
  for (i = 0; i < how_many; i ++)
    printf("\n%d\t %ld %ld\n", i, fibonacci(i), recursive_fibonacci(i));
  return 0;
}
