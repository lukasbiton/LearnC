/*
First attempt at doing file io in C.
*/


#include <stdio.h>

#define MAX_HW 20

void read_data(FILE *ptr, int d[], int *size)
{ // Pass in the address of sz so you can update it as you go.
  *size = 0;
  // &d[*size] get the value at the size pointer, specify the format as a list of that size, so you programmatically increase the size you read until it doesn't work anymore
  while(fscanf(ptr, "%d", &d[*size]) == 1) // produces the number of values read, so you can automatically detect the file size.
    (*size)++;
}

void print_data(int d[], int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    printf("%d\t", d[i]);
    if ((i + 1) % 10 == 0) printf("\n");
  }
}

double average(int d[], int size)
{
  int i;
  double avg = 0.0;

  for (i = 0; i < size; i++)
  {
    avg += d[i];
  }
  return (avg/size);
}


int main()
{
  int i, sz = MAX_HW;
  FILE *ifp;
  int data[MAX_HW] = {100, 0};

  ifp = fopen("myhw", "r");
  read_data(ifp, data, &sz);
  printf("My %d homework scores are:\n", sz);
  print_data(data, sz);
  printf("\nAverage score was %10f", average(data, sz));
  printf("\n\n");
  fclose(ifp);

  return 0;
}
