/*
Read an in file which contain an argument (number of elements) to build the out file.
*/

#include <stdio.h>
#include <stdlib.h> // exit()

int main(int argc, char *argv[])
{

  FILE *ifp, *ofp;
  int size;
  int i;
  double sum = 0.0;
  double average = 0.0;
  double max = -1000000.0;

  // if (argc != 3)
  // {
  //   printf("Need executable inputfile outputfile\n");
  //   exit(1);
  // }

  ifp = fopen(argv[1], "r");
  ofp = fopen(argv[2], "w");

  fscanf(ifp, "%d", &size);

  printf("The size is %d.\n", size);

  // Once you know the size, initialize the array
  int data[size];
  // rewind(ifp); // Don't rewind and you start after the first index

  for (i = 0; i < size; i++)
  {
    fscanf(ifp, "%d", &data[i]);
    printf("The %d th number is %d.\b\n", i, data[i]);
    sum += data[i];
    if (max < data[i])
    {
      max = data[i];
    }
  }

  average = sum/size;

  // fprintf allows to write human readable strings to a file.
  // First arg is a file pointer, second is the string, next arguments fill in
  // the string

  printf("The average is %lf ", average);
  fprintf(ofp, "The average is %lf\n", average);
  putc('\n', ofp);

  printf("The max is %lf ", max);
  fprintf(ofp, "The max is %lf", max);
  putc('\n', ofp);



  fclose(ifp);
  fclose(ofp);
  return 0;
}
