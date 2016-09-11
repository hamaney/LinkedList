//
//  linked_list.cpp
//  Linkedlist
//
//  Created by Abdulrhman Mohamed on 2016-08-19.
//  Copyright © 2016 Abdulrhman Mohamed. All rights reserved.
//

#include "include/linked_list.h"

/** PUBLIC ------------------------------------------------------------------**/

DLinkedList *CreateDLinkedList(void) {
  DLinkedList *new_list = (DLinkedList *)malloc(sizeof(DLinkedList));

  if (!new_list) {
    PrintErrorMallocRetunsNullForList();
  } else {
    new_list->head = NULL;
    new_list->current = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
  }
  return new_list;
}

DNode *AddDNodeAtHead(DLinkedList *list) {
  DNode *new_DNode = NULL;
  if (!list) {
    PrintErrorNullList();
  } else {
    new_DNode = CreateDNode();
    if (new_DNode) {
      if (isEmptyDLinkedList(list)) {
        list->head = new_DNode;
        list->tail = new_DNode;

      } else {
        new_DNode->next = list->head;
        list->head->prev = new_DNode;
        list->head = new_DNode;
      }
      list->size++;
    }
  }

  return new_DNode;
}

DNode *InsertNewDNodeAt(DLinkedList *list, size_t index) {
  // Original          [A Dnode]-[B   DNode]
  // New structure     [A Dnode]-[New DNode]-[B DNode]

  DNode *new_node = NULL;

  if (!list) {
    PrintErrorNullList();
  } else if (isEmptyDLinkedList(list)) {
    new_node = AddDNodeAtHead(list);
  } else {
    if (!isIndexInRange(list->size, index)) {
      PrintErrorIndexNotInRangeOfList();
    } else {
      if (!index) {
        new_node = AddDNodeAtHead(list);

      } else {
        DNode *new_node = CreateDNode();
        DNode *B_node = getDnodeAtIndex(list, index);
        DNode *A_node = B_node->prev;
        new_node->prev = A_node;
        new_node->next = B_node;
        B_node->prev = new_node;
        A_node->next = new_node;
        list->size++;
      }
    }
  }
  return new_node;
}

DNode *AddDNodeAtTail(DLinkedList *list) {
  DNode *new_DNode = NULL;
  if (!list) {
    PrintErrorNullList();
  } else {
    new_DNode = CreateDNode();
    if (new_DNode) {
      if (isEmptyDLinkedList(list)) {
        list->head = new_DNode;
        list->tail = new_DNode;

      } else {
        (list->tail)->next = new_DNode;
        new_DNode->prev = list->tail;
        list->tail = new_DNode;
      }
      list->size++;
    }
  }
  return new_DNode;
}

DNode *getDnodeAtIndex(DLinkedList *list, size_t index) {
  DNode *current = NULL;

  if (!list) {
    PrintErrorNullList();
  } else if (isEmptyDLinkedList(list)) {
    PrintErrorListHasNoNodes();
  } else {
    if (!isIndexInRange(list->size, index)) {
      PrintErrorIndexNotInRangeOfList();
    } else {
      current = list->head;
      while (index) {
        current = current->next;
        index--;
      }
    }
  }
  return current;
}

void PrintListValues(DLinkedList *list) {
  if (isEmptyDLinkedList(list)) {
    PrintErrorListHasNoNodes();
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

void FreeDLinkedListNodes(DLinkedList *list) {
  if (!list) {
    PrintErrorNullList();

  } else if (isEmptyDLinkedList(list)) {
    PrintErrorListHasNoNodes();

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

/** PRIVATE -----------------------------------------------------------------**/

// NODES -----------------------------------------------------------------------
DNode *CreateDNode(void) {
  DNode *new_DNode;
  new_DNode = (DNode *)malloc(sizeof(DNode));

  if (!new_DNode) {
    PrintErrorMallocRetunsNullForNode();
  } else {
    new_DNode->next = NULL;
    new_DNode->prev = NULL;
    new_DNode->data = 0;
  }
  return new_DNode;
}

// LISTS -----------------------------------------------------------------------
void GenerateDLinkedListForTesting(DLinkedList *list, size_t size) {
  // Check input
  if (!list) {
    PrintErrorNullList();

  } else if (list->head && list->size) {
    PrintErrorListHasNodes();
  } else {
    for (int count = 0; count < size; count++) {
      AddDNodeAtTail(list);
      list->tail->data = count;
    }
  }
  return;
}

bool isEmptyDLinkedList(DLinkedList *list) {
  if (!list) {
    PrintErrorNullList();
    return false;
  }
  if ((list->head == list->tail) && (!list->head) && (!list->current) &&
      (list->size == 0)) {
    return true;
  } else {
    return false;
  }
}

bool isIndexInRange(size_t list_size, size_t index) {
  if (index >= list_size) {
    return false;
  } else {
    return true;
  }
}

// Error MASGS -----------------------------------------------------------------
void PrintErrorNullList(void) {
  if (debug_prints) {
    printf("ERROR! List pointer is null\n");
  }
}

void PrintErrorNullNode(void) {
  if (debug_prints) {
    printf("ERROR! Node pointer is null\n");
  }
}

void PrintErrorMallocRetunsNullForList(void) {
  if (debug_prints) {
    printf("ERROR! Can not allocate memory to create a list\n");
  }
}

void PrintErrorMallocRetunsNullForNode(void) {
  if (debug_prints) {
    printf("ERROR! Can not allocate memory to create a node\n");
  }
}

void PrintErrorListHasNoNodes(void) {
  if (debug_prints) {
    printf("ERROR! List has no nodes\n");
  }
}

void PrintErrorListHasNodes(void) {
  if (debug_prints) {
    printf("ERROR! List has nodes\n");
  }
}

void PrintErrorIndexNotInRangeOfList(void) {
  if (debug_prints) {
    printf("ERROR! The index is out of the list range \n");
  }
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
