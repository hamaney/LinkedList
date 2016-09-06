
#include <stdio.h>
#include <unistd.h>
#include "include/linked_list.h"

int main() {
  // the loop is to check whether there is a mem leak
  unsigned x = 1;  // change to big number if testing the mem leak
  while (x) {
    DLinkedList* list = CreateDLinkedList();
    GenerateDLinkedListForTesting(list, 7);
    PrintListValues(list);
    FreeDLinkedListNodes(list);
    PrintListValues(list);
    free(list);
    list = NULL;
    x--;
  }

  DLinkedList* list = CreateDLinkedList();
  GenerateDLinkedListForTesting(list, 7);
  PrintListValues(list);
  AddDNodeAtHead(list);
  PrintListValues(list);

  return 0;
}
