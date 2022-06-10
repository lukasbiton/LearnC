// Simple sum
// Note template class has to be declared before each function that uses it

#include <iostream>
const int size = 50;

template <class T> // T is generic type
T sum(const T summable[], int size, T s = 0)
{
  for(int i = 0; i < size; ++i)
  {
    s += summable[i]; // += must work for T
  }
  return s;
}

template <class T> // T is generic type
void write_array(const T summable[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    std::cout << "Element " << i << " is " << summable[i] << std::endl;
  }
}

template<class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    destination[i] = static_cast<T2>(source[i]); // static_cast is safe casting
  }
}

int main(void)
{
  long double fibo[size];
  long int fibo_int[size];
  long double s;

  std::cout << "1st elem" << std::endl;
  std::cin >> fibo[0];
  std::cout << "2nd elem" << std::endl;
  std::cin >> fibo[1];

  for(int i = 2; i < size; ++i)
  {
    fibo[i] = fibo[i-1] + fibo[i-2];
    std::cout << "-2 " << fibo[i-2] << " -1 " << fibo[i-1] << " 0 " << fibo[i] << std::endl;
  }

  std::cout << "Sequence address is " << fibo << std::endl;

  write_array(fibo, size);

  s = sum(fibo, size);

  std::cout << "Sum of sequence is " << s << std::endl;

  copy(fibo, fibo_int, size);

  write_array(fibo_int, size);
}
