// Copy routine where you typecast from one template to another.

#include <iostream>
using namespace :: std;
const int size = 50;

template<class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    destination[i] = static_cast<T2>(source[i]); // static_cast is safe casting
  }
}

// int main(void)
// {
//   int source[size];
//   int destination[size];
// }
