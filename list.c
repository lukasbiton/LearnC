/*
Making a list
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {int data; struct list *next;} list;


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
  return head;
}

list* add_to_front(int d, list* h)
{
  list* head = create_list(d);
  head -> next = h;
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
  while (h != NULL)
  {
    printf("%d : ", h -> data);
    h = h -> next;
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

  list* head = NULL;
  int size = 100;
  int i = 0;

  for(i = 0; i < size; i++)
  {
    head = add_to_front(rand() % 50, head);
  }

  print_list(head, "unordered list");
  printf("\n\n");
  bubble(head, size);
  print_list(head, "ordered list");
  printf("\n\n");
  return 0;
}
