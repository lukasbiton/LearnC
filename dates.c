/*
First assignment of the new C coursera class.
Write a struct that supports dates.
Write a function that goes to the next day.
*/

#include <stdio.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date {month m; int d;} date;

void print_date(date da)
{
  switch (da.m){
    case jan: printf("The month is January and the day is %d.\n", da.d); break;
    case feb: printf("The month is February and the day is %d.\n", da.d); break;
    case mar: printf("The month is March and the day is %d.\n", da.d); break;
    case apr: printf("The month is April and the day is %d.\n", da.d); break;
    case may: printf("The month is May and the day is %d.\n", da.d); break;
    case jun: printf("The month is June and the day is %d.\n", da.d); break;
    case jul: printf("The month is July and the day is %d.\n", da.d); break;
    case aug: printf("The month is August and the day is %d.\n", da.d); break;
    case sep: printf("The month is September and the day is %d.\n", da.d); break;
    case oct: printf("The month is October and the day is %d.\n", da.d); break;
    case nov: printf("The month is November and the day is %d.\n", da.d); break;
    case dec: printf("The month is December and the day is %d.\n", da.d); break;
  }
}

date next_date(date da)
{
  int date_lim;

  switch (da.m){ // Set the max date by month
    case jan:
    case mar:
    case may:
    case jul:
    case aug:
    case oct:
    case dec:
      date_lim = 31; break;
    case feb:
      date_lim = 28; break;
    case apr:
    case jun:
    case sep:
    case nov:
      date_lim = 30; break;
  }

  if (da.d == date_lim) // If the max date for the month is reached, move to
  {
    da.m = (da.m + 1) % 12; // the next month
    da.d = 1; // on the first day of that new month
  }
  else
  {
    da.d++; // otherwise just increment the date
  }

  return da;
}

int main()
{
  // Print out January 1, February 28, March 14, October 31, December 31,
  // and the following day for all of these.
  int i;
  const int size = 5;
  date dates[size] = {{0, 1}, {1, 28}, {2, 14}, {9, 31}, {11, 31}};

  for (i = 0; i < size; i++)
  {
    print_date(dates[i]);
    print_date(next_date(dates[i]));
  }

  return 0;
}
