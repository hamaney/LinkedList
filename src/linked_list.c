//
//  linked_list.cpp
//  Linkedlist
//
//  Created by Abdulrhman Mohamed on 2016-08-19.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "include/linked_list.h"

DLinkedList *CreateDLinkedList(void) {
  DLinkedList *new_list = (DLinkedList *)malloc(sizeof(DLinkedList));

  if (!new_list) {
    printf("Error! creating a Doubly linked list!");
    return NULL;
  }
  new_list->head = NULL;
  new_list->current = NULL;
  new_list->tail = NULL;
  new_list->size = 0;

  return new_list;
}
DNode *AddDNode(DLinkedList *list) {
  // Check if input is null
  if (!list) {
    printf("Error! adding a Doubly Linked List Node!");
    return NULL;
  }
  DNode *new_DNode = CreateDNode();
  // Place link the node
  // Check whether the list has no nodes (uninitialized)
  if (!list->head) {
    list->head = new_DNode;
    list->tail = new_DNode;
  }
  // link to the end of the list
  else {
    // link to the end of the list
    list->tail->next = new_DNode;
    new_DNode->prev = list->tail;
    // update the list tail and size
    list->tail = new_DNode;
  }

  list->size++;
  return list->tail;
}

DNode *AddDNodeAtHead(DLinkedList *list) {  // Check if input is null
  if (!list) {
    printf("Error! input is a null pointer\n");
    return NULL;
  }
  DNode *new_DNode = CreateDNode();
  // Place link the node
  // Check whether the list has no nodes (uninitialized)
  if (isEmptyDLinkedList(list)) {
    return AddDNode(list);
  }
  // link to the end of the list
  else {
    new_DNode->next = list->head;
    list->head->prev = new_DNode;
    list->head = new_DNode;
    list->size++;
    return list->head;
  }
}

void PrintListValues(DLinkedList *list) {
  if (isEmptyDLinkedList(list)) {
    printf("Doubly Linked List has no nodes!\n");
  } else {
    DNode *current = list->head;

    while (current) {
      if (current == list->head) {
        printf("[%d -> ", current->data);
      } else if (current->next) {
        printf("%d -> ", current->data);
      } else {
        printf("%d]", current->data);
      }
      current = current->next;
    }
    printf("\n");
  }
}

// list will = null after this
void FreeDLinkedListNodes(DLinkedList *list) {
  if (!list) {
    printf("Error! input is a null pointer\n");

  } else {
    DNode *current_node = list->head;
    while (current_node) {
      DNode *next_node = current_node->next;
      free(current_node);
      current_node = next_node;
    }
    list->head = NULL;
    list->current = NULL;
    list->tail = NULL;
    list->size = 0;
  }

  return;
}
/** PRIVATE **/
DNode *CreateDNode(void) {
  DNode *new_DNode;
  new_DNode = (DNode *)malloc(sizeof(DNode));

  if (!new_DNode) {
    printf("Error! creating a Doubly Linked List Node!\n");
    return NULL;
  }
  new_DNode->next = NULL;
  new_DNode->prev = NULL;
  new_DNode->data = 0;
  return new_DNode;
}
// testing only
void GenerateDLinkedListForTesting(DLinkedList *list, int size) {
  // Check input
  if (!list) {
    printf("ERROR! input is not valid. list pointer is null or size < 0\n");
  }
  if (list->head) {
    printf("ERROR! the Doubly Linked List is not empty\n");
  }

  for (int count = 0; count < size; count++) {
    AddDNode(list);
    list->tail->data = count;
  }
}

bool isEmptyDLinkedList(DLinkedList *list) {
  if ((list->head == list->tail) && (!list->head) && (!list->current) &&
      (list->size == 0)) {
    return true;
  } else {
    return false;
  }
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// void DallocDLinkedListElements(DLinkedList *list) {}

/*
 DNode* CreateDList(int number_of_DNodes) {
  if (!number_of_DNodes) {
    printf("Error creating List! Please enter a positive integer\n");
    return NULL;
  } else {
    DNode* list_head = CreateaDNode();
    number_of_DNodes--;

    DNode* current = list_head;
    DNode* new_DNode = NULL;

    while (number_of_DNodes) {
      new_DNode = CreateaDNode();
      new_DNode->prev = current;
      current->next = new_DNode;
      current = current->next;
      number_of_DNodes--;
    }
    return list_head;
  }
}

void RemoveDNode(DNode* starting_node, int offset) {
  DNode* current = starting_node;
  int count = 0;

  while (count < offset) {
    current = current->next;
    count++;
  }
  // only node
  if (isOneDNode(starting_node)) {
    printf("Error! can not delete a list of one node");
  } else if (isHead(starting_node) && !offset) {
    RemoveDListHead(starting_node);
  } else {
    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;
  }


  // free(current); is this a BUG
  // current = NULL;
  //   ====================================================================AYOUB
}

void RemoveDListHead(DNode* list_head) {
  // list_head = list_head->next;
  // list_head->prev = NULL;
}

void PrintDListDebug(DNode *list_head) {
  DNode *current = list_head;

  printf("[ PREV NODE ] [ DATA ] [NEXT NODE] \n");
  while (current) {
    if (!current->prev) {
      printf("[NUL] [ %d ] [ %d ] \n", current->data, current->next->data);
    } else if (!current->next) {
      printf("[ %d ] [ %d ] [NUL] \n", current->prev->data, current->data);
    } else {
      printf("[ %d ] [ %d ] [ %d ] \n", current->prev->data, current->data,
             current->next->data);
    }
    current = current->next;
  }
}
*/

/*
bool isHead(DNode* node) {
  if (!node->prev)
    return true;
  else
    return false;
}

bool isTail(DNode* node) {
  if (!node->next)
    return true;
  else
    return false;
}

bool isOneDNode(DNode* node) {
  if (!node->prev && !node->next)
    return true;
  else
    return false;
}

int ListSize(DNode* list_head) {
  int size = 0;
  DNode* current = list_head;
  while (current) {
    current = current->next;
    size++;
  }

  return size;
}*/
