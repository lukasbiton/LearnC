/*
Making a list
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {int data; struct list *next; struct list *previous;} list;


void bubble(list *head, int how_many)
{
  int i, j, swapped, temp;
  list *h;

  for (i = 0; i < how_many; i++)
  {

    h = head;
    swapped = 0;

    for (j = how_many - 1; j > i; j--)
    {
      if (h -> data > h -> next -> data)
      { // If current if greater than next, swap
        temp = h -> next -> data; // store next
        h -> next -> data = h -> data; // exchange data
        h -> data = temp;
        swapped = 1; // we did a swap
      }
      h = h -> next; // Move on to next element as current
    }
    if (swapped == 0) {break;} // if no swap, end algorithm
  }

}

int is_empty(const list *l)
{
  return (l == NULL);
}

list* create_list(int d)
{
  list* head = malloc(sizeof(list));
  head -> data = d;
  head -> next = NULL;
  head -> previous = NULL;
  return head;
}

list* add_to_front(int d, list* h)
{
  list* head = create_list(d);
  head -> next = h;
  h -> previous = head;
  return head;
}

list* array_to_list(int d[], int size)
{
  list* head = create_list(d[0]);
  int i;

  for (i = 1; i < size; i++)
  {
    head = add_to_front(d[i], head);
  }
  return head;
}

void print_list(list *h, char *title)
{

  printf("%s\n: ", title);

  while (h != NULL)// && h -> previous != NULL && h -> next != NULL)
  {

    // printf("Previous is %d : ", h -> previous -> data);
    printf("%d : ", h -> data);
    // printf("Next is %d : ", h -> next -> data);

    h = h -> next;
  }
}

void remove_duplicates_sorted(list *h, int size)
{ // pass in an ordered list
  int i;

  while (h != NULL && h -> next != NULL)
  {
    // if current and next are the same, change pointer to next next
    // else move on to the next node in the list
    if (h -> data == h -> next -> data)
    {
      h -> next = h -> next -> next;
      h -> next -> next -> previous = h -> next -> previous;
    }
    else
    {
      h = h -> next;
    }
  }
}

int main()
{
  // list* head = NULL;
  // int data[6] = {2,3,5,7,8,9};
  //
  // head = array_to_list(data, 6);
  // print_list(head, "several element list");
  // printf("\n\n");
  //
  // return 0;

  list *head1 = NULL, *head2 = NULL;
  int size = 100;
  int data[size];
  int i = 0;

  for (i = 0; i < size; i++)
  {
    data[i] = rand() % 50;
  }

  head1 = array_to_list(data, size);
  head2 = array_to_list(data, size);

  print_list(head1, "unordered list");
  printf("\n\n");
  bubble(head1, size);
  print_list(head1, "ordered list");
  printf("\n\n");
  remove_duplicates_sorted(head1, size);
  print_list(head1, "ordered list, no duplicates from sorted");
  printf("\n\n");
  print_list(head2, "unorder list, no duplicates from unsorted");
  return 0;
}
