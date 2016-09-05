
#include <stdio.h>
#include <unistd.h>
#include "include/linked_list.h"

int main() {
  DLinkedList* list = CreateDLinkedList();
  GenerateDLinkedListForTesting(list, 10);
  PrintListValues(list);
  return 0;
}
