/*
Working with enums.
*/

#include <stdio.h>

// enum is a keyword
// day is a token to reference the type
enum day {sun, mon, tue, wed, thu, fri, sat}; // Declare a new type
typedef enum day day; // Associate enum day to the keyword day alone
enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

void print_day(day d) //(enum day d) can replace "enum day" with "day" thanks to typedef
{
  switch(d){
    case sun: printf("Sunday"); break;
    case mon: printf("Monday"); break;
    case tue: printf("Tuesday"); break;
    case wed: printf("Wednesday"); break;
    case thu: printf("Thursday"); break;
    case fri: printf("Friday"); break;
    case sat: printf("Saturday"); break;
    default: printf("%d is an error", d);
  }
}

enum day next_day(enum day d)
{
  return ((d + 1) % 7);
}

int main()
{
  enum day today = fri; // declare a variable of the type enum coded as day
  print_day(today);
  printf("\n\n");
  print_day(7);
  printf("\n\n");
  print_day(next_day(today));
  printf("\n\n");

  if (sun == jan)
  {
    printf("This works.\n\n");
    printf("%d and %d\n\n", sun, jan);
  }
  else
    printf("This does not work.\n\n");
  return 0;
}
