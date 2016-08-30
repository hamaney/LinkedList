
#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
#include "src/linked_list.c"
}
class LinkedList : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown() {
    free(test_list);
    test_list = NULL;
  }

  DNode* test_list = CreateDNode();
};
// Tesing list / node creation
TEST_F(LinkedList, List_creation) { ASSERT_TRUE(test_list); }

// NODES Nedd to be DELETED
TEST_F(LinkedList, Node_creation) {
  // Creation if the data
  DNode* test_node = CreateDNode();

  // Creation of nodes
  // ASSERT_TRUE(test_node);

  ASSERT_NE(test_node, nullptr);
  ASSERT_EQ(test_node->data, 0);
  ASSERT_EQ(test_node->prev, nullptr);
  ASSERT_EQ(test_node->next, nullptr);

  // free(test_node);
  test_node = NULL;
}

TEST_F(LinkedList, Node_data_ssignment_and_linking) {
  DNode* test_node = CreateDNode();
  DNode* test_node_next = CreateDNode();
  DNode* test_node_prev = CreateDNode();
  int data_prev = 1;
  int data = 2;
  int data_next = 3;
  test_node_prev->data = data_prev;
  test_node->data = data;
  test_node_next->data = data_next;

  // Data assignment
  ASSERT_EQ(test_node_prev->data, data_prev);
  ASSERT_EQ(test_node->data, data);
  ASSERT_EQ(test_node_next->data, data_next);
  // Linking
  test_node->next = test_node_next;
  test_node->prev = test_node_prev;
  ASSERT_EQ(test_node->next, test_node_next);
  ASSERT_EQ(test_node->prev, test_node_prev);
  ASSERT_EQ((test_node->next)->data, test_node_next->data);
  ASSERT_EQ((test_node->prev)->data, test_node_prev->data);

  free(test_node);
  free(test_node_next);
  free(test_node_prev);
  test_node = NULL;
  test_node_prev = NULL;
  test_node_next = NULL;
}
