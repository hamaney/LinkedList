
#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
#include "src/linked_list.c"
}

class LinkedListCreation : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown() {
    FreeDLinkedListNodes(list);
    if (!list) {
      free(list);
    }
  }
  DLinkedList* list = NULL;
};

TEST_F(LinkedListCreation, ListCreation) {
  list = CreateDLinkedList();
  ASSERT_NE(list, nullptr);
  ASSERT_EQ(list->head, nullptr);
  ASSERT_EQ(list->tail, nullptr);
  ASSERT_EQ(list->current, nullptr);
  ASSERT_EQ(list->size, 0);
}

TEST_F(LinkedListCreation, NodeCreation) {
  // Creation if the data
  DNode* node = CreateDNode();
  // Creation of nodes
  ASSERT_NE(node, nullptr);
  ASSERT_EQ(node->data, 0);
  ASSERT_EQ(node->prev, nullptr);
  ASSERT_EQ(node->next, nullptr);
  free(node);
}

TEST_F(LinkedListCreation, functionToGenerateLNodesForList) {
  size_t size = 7;
  GenerateDLinkedListForTesting(list, size);
  ASSERT_EQ(list, nullptr);

  list = CreateDLinkedList();
  AddDNodeAtHead(list);
  size_t old_size = list->size;
  GenerateDLinkedListForTesting(list, size);
  ASSERT_EQ(list->size, old_size);

  list = CreateDLinkedList();
  GenerateDLinkedListForTesting(list, size);
  ASSERT_EQ(list->size, size);

  DNode* current = list->head;
  for (auto count(0); count < size; count++) {
    ASSERT_EQ(current->data, count);
    current = current->next;
  }
}