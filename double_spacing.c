/*
More uses of file i/o
*/

#include <stdio.h>
#include <stdlib.h> // exit()


void print_file(FILE * fptr)
{
  int c;
  rewind(fptr); // make sure you are at the beginning of the file
  while((c = getc(fptr)) != EOF) //get character = getc
    putc(c, stdout); // standard output meaning print to terminal; putc = where do you put the character
}

void double_space(FILE *ifp, FILE *ofp)
{
  int c;
  rewind(ifp);
  while((c = getc(ifp)) != EOF)
  {
    putc(c, ofp);
    //putchar(c);
    if (c == '\n')
    {
      putc('\n', ofp);
    }
  }
}

int main(int argc, char *argv[])
{
  FILE *ifp, *ofp;

  if (argc != 3)
  {
    printf("Need executable inputfile outputfile\n");
    exit(1);
  }

  ifp = fopen(argv[1], "r+");
  ofp = fopen(argv[2], "w+");
  printf("My %s file as read is\n\n", argv[1]);
  print_file(ifp);
  printf("\n\n");
  double_space(ifp, ofp);
  printf("my %s file double spaced is\n\n", argv[2]);
  print_file(ofp);
  printf("\n\n");
  fclose(ifp);
  fclose(ofp);

  return 0;
}
