//
//  linked_list.hpp
//  Linkedlist
//
//  Created by Abdulrhman Mohamed on 2016-08-19.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode DNode;
typedef struct DLinkedList DLinkedList;

struct DNode {
  DNode* prev;
  int data;
  DNode* next;
};

struct DLinkedList {
  DNode* head;
  DNode* current;
  DNode* tail;

  unsigned size;
};

DLinkedList* CreateDLinkedList(void);
DNode* CreateDNode(void);
/*DNodePtr CreateDList(int);

void RemoveDNode(DNodePtr, int);
void RemoveDListHead(DNodePtr);

void PrintDListDebug(DNodePtr);
void PrintListValues(DNodePtr);

bool isHead(DNodePtr);
bool isTail(DNodePtr);
bool isOneDNode(DNodePtr);

int ListSize(DNodePtr);*/
#endif /* linked_list_hpp */
