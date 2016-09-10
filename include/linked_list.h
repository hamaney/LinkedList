//
//  linked_list.hpp
//  Linkedlist
//
//  Created by Abdulrhman Mohamed on 2016-08-19.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//
/*
TODO:
- GenerateDLinkedListForTesting -> GenerateDNoesForList()
- AddDNode() -> AddDNodeAtTail()

*/

#ifndef linked_list_h
#define linked_list_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define debug_prints false

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

  size_t size;
};

DLinkedList* CreateDLinkedList(void);
void PrintListValues(DLinkedList* list);
void FreeDLinkedListNodes(DLinkedList* list);
DNode* InsertNewDNodeAt(DLinkedList* list, size_t index);
DNode* getDnodeAtIndex(DLinkedList* list, size_t index);
/** PRIVATE **/
DNode* CreateDNode(void);
DNode* AddDNode(DLinkedList* list);
DNode* AddDNodeAtHead(DLinkedList* list);
void GenerateDLinkedListForTesting(DLinkedList* list, size_t size);
bool isEmptyDLinkedList(DLinkedList* list);
bool isIndexInRange(size_t list_size, size_t index);

// Error MASGS
void PrintErrorNullList(void);
void PrintErrorNullNode(void);
void PrintErrorMallocRetunsNullForList(void);
void PrintErrorMallocRetunsNullForNode(void);
void PrintErrorListHasNoNodes(void);
void PrintErrorListHasNodes(void);
void PrintErrorIndexNotInRangeOfList(void);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// DNodePtr CreateDList(int);
// void RemoveDNode(DNodePtr, int);
// void RemoveDListHead(DNodePtr);
// void PrintDListDebug(DNodePtr);
// bool isHead(DNodePtr);
// bool isTail(DNodePtr);
// bool isOneDNode(DNodePtr);
// int ListSize(DNodePtr);
#endif /* linked_list_hpp */
