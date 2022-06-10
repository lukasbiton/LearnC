// Implementation of list in C++

#include <iostream>

class list_element {

public:
  list_element(int n = 0, list_element* ptr = nullptr):
    d(n), next(ptr){}
    int d;
    list_element* next;
};

class list {

public:
  list(): head(nullptr), cursor(nullptr){}
  void prepend(int n); // Insert value n at the front of the list
  int get_element(){return cursor -> d;}
  void advance(){cursor = cursor -> next;}
  void print();
  ~list();

private:
  list_element *head;
  list_element *cursor;
};

void list::prepend(int n) {
  if (head == nullptr) { // empty list
    cursor = head = new list_element(n, head);
    // std::cout << "nullptr case" << std::endl;
  } else { // no-empty list, add to front
    head = new list_element(n, head);
    // std::cout << "other case " << n << std::endl;
  }
}

void list::print(){
  list_element *h = head;

  while(h != nullptr) {
    std::cout << h -> d << ",";
    h = h -> next;
  }
  std::cout << "###" << std::endl;
}

list::~list() {
  for(cursor = head; cursor != nullptr;) {
    cursor = head ->next;
    delete head;
    head = cursor;
  }
}

int main() {
  list a, b;
  a.prepend(9);
  a.prepend(8);
  std::cout << "list a" << std::endl;
  a.print();

  for(int i = 0; i < 40; ++i) {
    // std::cout << i << std::endl;
    // std::cout << i*i << std::endl;
    b.prepend(i*i);
  }
  std::cout << "list b" << std::endl;
  b.print();
}
