/*
More if else logic.
*/

#include <stdio.h>

int main(void)
{
  int blanks = 0, digits = 0, letters = 0, others = 0;
  int c; // use for int value of character
  while((c = getchar()) != EOF) // end of file, not end of line, use CTRL-D
  {
    if (c == ' ')
      ++blanks;
    else if (c >= '0' && c <= '9')
      ++digits;
    else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z')
      ++letters;
    else
      ++others;
  };
  printf("blanks = %d, digits = %d, letters = %d,", blanks, digits, letters);
  printf(" others = %d\n\n", others);
  return 0;
}
