// list/list.c
//
// Implementation for linked list.
//
// <Oluwatosin Adeyemi>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() {
  list_t* list = malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

void list_free(list_t *l) {
  while(l->head != NULL){
    node_t * temp = l->head;
    l->head = l->head->next;
    free(temp);
  }
  return;
}

void list_print(list_t *l) {
  node_t *current = l->head;
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
}

int list_length(list_t *l){
  node_t* current = l->head;
  int count = 0;
  while(current != NULL){
    count++;
    current = current->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  if (l->head){
    node_t *current = l->head;
    while (current->next){
      current = current->next;
    }
    node_t* new_node;
    new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    current->next = new_node;
    new_node->next = NULL;
  } else {
    list_add_to_front(l,value);
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t* new_node;
  new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  if(l->head){
    new_node->next = l->head;
    l->head = new_node;
  } else {
    new_node->next = NULL;
    l->head = new_node;
  }
}
void list_add_at_index(list_t *l, elem value, int index) {
  if (index == 0 || l->head == NULL){
    list_add_to_front(l,value);
  }
  int count = 0;
  node_t *current = l->head;
  while (current){
    if (count == index-1){
      node_t* new_node;
      new_node = (node_t*)malloc(sizeof(node_t));
      new_node->value = value;
      new_node->next = current->next;
      current->next = new_node;
    }
    count += 1;
    current = current->next;
  }
}

elem list_remove_from_back(list_t *l) {
  int removedVal;
  node_t *current = l->head;
  if (current == NULL){
    return -1;
  }
  while (current->next->next != NULL) {
      current = current->next;
  }
  removedVal = current->next->value;
  free(current->next);
  current->next = NULL;
  return removedVal;
}
elem list_remove_from_front(list_t *l) { 
  elem removedVal = -1;
  node_t *current = l->head;
  if (current == NULL){
    return removedVal;
  }
  l->head = current->next;
  removedVal = current->value;
  free(current);
  return removedVal;
}
elem list_remove_at_index(list_t *l, int index) {
  int removedVal = -1;
  node_t *temp =NULL;
  if (index==0){
    list_remove_from_front(l);
  }
  int count = 0;
  node_t *current = l->head;
  while (current){
    if (count == index-1){
      removedVal = current->next->value;
      free(current->next);
      current->next = current->next->next;
      return removedVal;
    }
    count += 1;
    current = current->next;
  };
}


bool list_is_in(list_t *l, elem value) { 
  node_t* current = l->head;
  
  while(l->head != NULL){
    if (l->head->value != value){
      l->head = l->head->next;
    }
    else{
      l->head = current;
      return true;
    }
  }
  l->head = current;
  return false; 
}


elem list_get_elem_at(list_t *l, int index) { 
  node_t* current = l->head;
  while(l->head != NULL){
    if(index != 0){
      l->head = l->head->next;
    }
    else {
      int temp = l->head->value;
      l->head = current;
      return temp;
    }
    index -= 1;
  }
  l->head = current;
  return -1; 
}

int list_get_index_of(list_t *l, elem value) { 
  node_t* current = l->head;
  
  while (l->head != NULL){
    if (l->head->value != value){
      l->head = l->head->next;
    }
    else{
      l->head = current;
      return true;
    }
  }
  l->head = current;
  return -1; }

