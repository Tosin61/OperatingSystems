#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  list_t* linkedList = list_alloc();
  list_print(linkedList);
  
  list_add_to_back(linkedList, 16);
  list_add_to_back(linkedList, 17);
  list_add_to_back(linkedList, 18);
  list_add_to_back(linkedList, 19);

  
  list_add_to_front(linkedList, 1);
  list_add_to_front(linkedList, 2);
  list_add_to_front(linkedList, 3);
  list_add_to_front(linkedList, 4);
  
  
  list_add_at_index(linkedList, 30, 2);
  list_add_at_index(linkedList, 29, 2);
  list_add_at_index(linkedList, 28, 2);
  list_add_at_index(linkedList, 27, 2);
  
  
  list_print(linkedList);
  
  printf("\n");
  printf("\n");
  
  printf("Index - 3: Element is %d\n", list_get_elem_at(linkedList, 3));
  printf("Index - 8: Element is %d\n", list_get_elem_at(linkedList, 8));
  printf("Index - 11: Element is %d\n", list_get_elem_at(linkedList, 11));
  
  printf("Is 4 in the list? : %d\n", list_get_index_of(linkedList, 4));
  printf("Is 50 in the list? : %d\n", list_get_index_of(linkedList, 50));
  printf("Is 7 in the list? : %d\n", list_get_index_of(linkedList, 7));
  
  list_remove_from_front(linkedList);
  list_remove_from_front(linkedList);
  list_print(linkedList);
  
  printf("\n");
  
  list_remove_from_back(linkedList);
  list_remove_from_back(linkedList);
  list_print(linkedList);
  
  printf("\n");
  printf("\n");
  
  list_remove_at_index(linkedList, 4);
  list_remove_at_index(linkedList, 1);
  list_print(linkedList);
  
  
    
  return 0;
}