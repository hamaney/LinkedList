#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
#include "src/linked_list.c"
}

class LinkedList : public ::testing::Test {
 public:
  virtual void SetUp() { GenerateDLinkedListForTesting(list_filled, 7); }
  virtual void TearDown() {
    FreeDLinkedListNodes(list_uninitialized);
    FreeDLinkedListNodes(list_filled);
    free(list_uninitialized);
    free(list_filled);
    list_uninitialized = NULL;
    list_filled = NULL;
  }

  DLinkedList* DLinkedList_nullptr = NULL;
  DNode* DNode_nullptr = NULL;
  DLinkedList* list_uninitialized = CreateDLinkedList();
  DLinkedList* list_filled = CreateDLinkedList();
};
// Testing list / node creation
TEST_F(LinkedList, List_creation) {
  ASSERT_NE(list_uninitialized, DLinkedList_nullptr);
  ASSERT_EQ(list_uninitialized->head, DNode_nullptr);
  ASSERT_EQ(list_uninitialized->tail, DNode_nullptr);
  ASSERT_EQ(list_uninitialized->current, DNode_nullptr);
  ASSERT_EQ(list_uninitialized->size, 0);
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

TEST_F(LinkedList, add_node_to_the_end_of_an_empty_list) {
  // Assgine to cuurent test
  AddDNode(list_uninitialized);
  ASSERT_NE(list_uninitialized->head, DNode_nullptr);
  ASSERT_NE(list_uninitialized->tail, DNode_nullptr);
  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
  ASSERT_NE(list_uninitialized->size, 0);
}

TEST_F(LinkedList, add_node_to_the_end_of_a_nonempty_list) {
  // full list
  AddDNode(list_uninitialized);
  // extract it data
  DNode* original_list_tail = list_uninitialized->tail;
  int original_list_size = list_uninitialized->size;
  AddDNode(list_uninitialized);
  ASSERT_EQ(list_uninitialized->tail, (original_list_tail)->next);
  ASSERT_EQ(list_uninitialized->tail->prev, original_list_tail);
  ASSERT_EQ(list_uninitialized->size, original_list_size + 1);
}

TEST_F(LinkedList, add_node_to_the_start_of_an_empty_list) {
  AddDNodeAtHead(list_uninitialized);
  ASSERT_NE(list_uninitialized->head, DNode_nullptr);
  ASSERT_NE(list_uninitialized->tail, DNode_nullptr);
  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
  ASSERT_EQ(list_uninitialized->size, 1);
}

TEST_F(LinkedList, add_node_to_the_start_of_nonempty_list) {
  DNode* original_list_head = list_filled->head;
  DNode* original_list_tail = list_filled->tail;
  int original_list_size = list_filled->size;
  AddDNodeAtHead(list_filled);
  ASSERT_NE(list_filled->head, original_list_head);
  ASSERT_EQ(list_filled->head->next, original_list_head);
  ASSERT_EQ(list_filled->head, original_list_head->prev);
  ASSERT_EQ(list_filled->size, original_list_size + 1);
}

TEST_F(LinkedList, function_to_Generate_list_for_testing) {
  int size = 7;
  GenerateDLinkedListForTesting(list_uninitialized, size);
  DNode* current = list_uninitialized->head;
  ASSERT_EQ(list_uninitialized->size, size);
  for (auto count(0); count < size; count++) {
    ASSERT_EQ(current->data, count);
    current = current->next;
  }
}

TEST_F(LinkedList, deallocate_list_nodes) {
  // populate a list
  // NOTE: check with profiling software some corner cases
}
