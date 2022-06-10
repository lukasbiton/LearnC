/*
How to use pointers.
*/

#include <stdio.h>

int main(void)
{
  const int SIZE = 5;

  int grades[SIZE] = {78, 67, 92, 83, 88};
  double sum = 0.0;
  double *ptr_to_sum = &sum; // &sum means address of sum, the * tells us this is an address
  int i;

  printf("\nMy grades are:\n");

  for (i = 0; i < SIZE; i++)
  {
    printf("%d\t", grades[i]);
    sum += grades[i];
  }
  printf("\n\n");
  printf("My average is %.2f\n\n", sum/SIZE);
  printf("\n\n");

  printf("Sum is at %p, or %lu, and is %lf\n", // %p is the format for a pointer address
          ptr_to_sum, // address of the sum
          ptr_to_sum, // %lu is long unsigned, so positive integer
          *ptr_to_sum);

  printf("Grades are at %lu to %lu\n", grades, grades + 5);
  return 0;
}
