/*
Calculate average from passed data.
*/


# include <stdio.h>

int main()
{
  FILE* f = fopen("weights.txt", "r");
  int number = 0;
  double counter = 0.0;
  double sum = 0.0;

  // stream inputs from data with number followed by two spaces until there is
  // nothing of this format anymore
  while (fscanf(f, "%d  ", &number) > 0)
  {
    sum += number;
    counter += 1.0;
  }

  printf("The total weight is %lf and the total number of animals is %lf.\n", sum, counter);
  printf("The average weight is: %lf\n", sum/counter);
}
