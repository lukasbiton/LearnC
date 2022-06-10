/*
Generate salaries based on some criteria.
*/

#include <stdlib.h>
#include <stdio.h>

#define MIN_HR 40000
#define VARIABLE_HR 20000
#define MIN_SALES 50000
#define VARIABLE_SALES 100000
#define MIN_RESEARCH 60000
#define VARIABLE_RESEARCH 10000
#define MIN_SOFTWARE 80000
#define VARIABLE_SOFTWARE 20000
#define MIN_EXEC 150000
#define VARIABLE_EXEC 100000

typedef enum department {hr, sales, research, software, executive} department;
typedef struct employee {department department; int salary; unsigned int ssn;} employee;

void print_employee(employee e)
{
  switch (e.department)
  {
    case hr: printf("Employee %u works in HR for %d\n\n", e.ssn, e.salary); break;
    case sales: printf("Employee %u works in Sales for %d\n\n", e.ssn, e.salary); break;
    case research: printf("Employee %u works in Research for %d\n\n", e.ssn, e.salary); break;
    case software: printf("Employee %u works in Software for %d\n\n", e.ssn, e.salary); break;
    case executive: printf("Employee %u works in Executive for %d\n\n", e.ssn, e.salary); break;
  }
}

int make_salary(department d)
{
  switch (d)
  {
    case hr: return (MIN_HR + (rand() % VARIABLE_HR)); break;
    case sales: return (MIN_SALES + (rand() % VARIABLE_SALES)); break;
    case research: return (MIN_RESEARCH + (rand() % VARIABLE_RESEARCH)); break;
    case software: return (MIN_SOFTWARE + (rand() % VARIABLE_SOFTWARE)); break;
    case executive: return (MIN_EXEC + (rand() % VARIABLE_EXEC)); break;
  }
}

int main()
{
  // Generate ten employees
  int i;
  unsigned int ssn;
  department department;
  int how_many = 10;
  employee employee;

  for (i = 0; i < how_many; i++)
  {
    ssn = rand();
    department = ssn % 5; // because there are five departments
    employee.department = department;
    employee.salary = make_salary(department);
    employee.ssn = ssn;
    print_employee(employee);
  }
  return 0;
}
