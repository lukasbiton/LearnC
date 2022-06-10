// Program converted from C.
// C program defines a sum function.
// In main it fills an array and passes
// it to the sum function.

#include <iostream>
const int N = 40;

void sum(int *p, int n, int d[])
{
  *p = 0;
  for(auto i = 0; i < n; ++i)
  {
    *p = *p + d[i];
    // std::cout << *p << '\n';
  }
}

int main(void)
{
  int accum = 0;
  int data[N];

  for(auto i = 0; i < N; ++i)
  {
    data[i] = i;
    // std::cout << i << '\n';
  }
  // std::cout << std::endl;

  sum(&accum, N, data);

  std::cout << "Sum is " << accum << std::endl;
}
