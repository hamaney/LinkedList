#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
#include "src/linked_list.c"
}

class LinkedList : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown() {
    DeallocateDLinkedListDNodes(list);
    free(list);
    list = NULL;
  }

  DLinkedList* list = CreateDLinkedList();
  DLinkedList* DLinkedList_nullptr = NULL;
  DNode* DNode_nullptr = NULL;
};
// Testing list / node creation
TEST_F(LinkedList, List_creation) {
  ASSERT_NE(list, DLinkedList_nullptr);
  ASSERT_EQ(list->head, DNode_nullptr);
  ASSERT_EQ(list->tail, DNode_nullptr);
  ASSERT_EQ(list->current, DNode_nullptr);
  ASSERT_EQ(list->size, 0);
}

// NODES Need to be DELETED
TEST_F(LinkedList, Node_creation) {
  // Creation if the data
  DNode* node = CreateDNode();

  // Creation of nodes
  ASSERT_NE(node, nullptr);
  ASSERT_EQ(node->data, 0);
  ASSERT_EQ(node->prev, nullptr);
  ASSERT_EQ(node->next, nullptr);

  free(node);
  node = NULL;
}

TEST_F(LinkedList, Node_data_ssignment_and_linking_to_other_node) {
  DNode* node = CreateDNode();
  DNode* node_next = CreateDNode();
  DNode* node_prev = CreateDNode();
  int data_prev = 1;
  int data = 2;
  int data_next = 3;
  node_prev->data = data_prev;
  node->data = data;
  node_next->data = data_next;

  // Data assignment
  ASSERT_EQ(node_prev->data, data_prev);
  ASSERT_EQ(node->data, data);
  ASSERT_EQ(node_next->data, data_next);
  // Linking
  node->next = node_next;
  node->prev = node_prev;
  ASSERT_EQ(node->next, node_next);
  ASSERT_EQ(node->prev, node_prev);
  ASSERT_EQ((node->next)->data, node_next->data);
  ASSERT_EQ((node->prev)->data, node_prev->data);

  free(node);
  free(node_next);
  free(node_prev);
  node = NULL;
  node_prev = NULL;
  node_next = NULL;
}

TEST_F(LinkedList, appanding_to_an_empty_list) {
  // Assgine to cuurent test
  addDNode(list);

  ASSERT_NE(list->head, DNode_nullptr);
  ASSERT_NE(list->tail, DNode_nullptr);
  ASSERT_EQ(list->head, list->tail);
  ASSERT_NE(list->size, 0);
}

TEST_F(LinkedList, appanding_to_nonempty_list) {
  // full list
  addDNode(list);
  // extract it data
  DNode* original_list_tail = list->tail;
  int original_list_size = list->size;

  addDNode(list);

  ASSERT_EQ(list->tail, (original_list_tail)->next);
  ASSERT_EQ(list->tail->prev, original_list_tail);
  ASSERT_EQ(list->size, original_list_size + 1);
}

TEST_F(LinkedList, function_to_Generate_list_for_testing) {
  int size = 7;
  GenerateDLinkedListForTesting(list, size);
  DNode* current = list->head;

  ASSERT_EQ(list->size, size);
  for (auto count(0); count < size; count++) {
    ASSERT_EQ(current->data, count);
    current = current->next;
  }
}

// NOTE: check with profiling software some corner cases
TEST_F(LinkedList, deallocate_list_nodes) {
  // populate a list
  GenerateDLinkedListForTesting(list, 7);
  DeallocateDLinkedListDNodes(list);
  // The list has been unlinked
  ASSERT_EQ(list->head, DNode_nullptr);
  ASSERT_EQ(list->tail, DNode_nullptr);
  ASSERT_EQ(list->current, DNode_nullptr);
  ASSERT_EQ(list->size, 0);
}
