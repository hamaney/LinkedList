#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
#include "src/linked_list.c"
}
//
// class LinkedList : public ::testing::Test {
// public:
//  virtual void SetUp() {
//    GenerateDLinkedListForTesting(list_filled, list_filled_size);
//  }
//  virtual void TearDown() {
//    FreeDLinkedListNodes(list_uninitialized);
//    FreeDLinkedListNodes(list_filled);
//    free(list_uninitialized);
//    free(list_filled);
//    list_uninitialized = NULL;
//    list_filled = NULL;
//  }
//
//  DLinkedList* DLinkedList_nullptr = NULL;
//  DNode* DNode_nullptr = NULL;
//  DLinkedList* list_uninitialized = CreateDLinkedList();
//  DLinkedList* list_filled = CreateDLinkedList();
//  size_t list_filled_size = 7;
//};
