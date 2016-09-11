
#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
//#include "src/linked_list.c"
}

class LinkedList_getters : public ::testing::Test {
 public:
  virtual void SetUp() {
    GenerateDLinkedListForTesting(list_filled, list_filled_size);
  }
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
  DLinkedList* list_null = NULL;
  DLinkedList* list_uninitialized = CreateDLinkedList();
  DLinkedList* list_filled = CreateDLinkedList();
  size_t list_filled_size = 7;
};

// WARNING: O(n)
TEST_F(LinkedList_getters, get_a_node_at_given_index) {
  // with (null list  or empty list )the index value does not matter
  size_t index = 0;
  ASSERT_FALSE(getDnodeAtIndex(list_null, index));
  ASSERT_FALSE(getDnodeAtIndex(list_uninitialized, index));

  index = -1;
  ASSERT_FALSE(getDnodeAtIndex(list_filled, index));
  index = list_filled_size;
  ASSERT_FALSE(getDnodeAtIndex(list_filled, index));
  index = list_filled_size + 1;
  ASSERT_FALSE(getDnodeAtIndex(list_filled, index));

  index = 0;
  ASSERT_TRUE(getDnodeAtIndex(list_filled, index));
  DNode* node_at_index = getDnodeAtIndex(list_filled, index);
  ASSERT_EQ(node_at_index->data, index);  // the GenerateDLinkedListForTesting()
                                          // assigne values based on their index
                                          // when creating the tested list
  index = list_filled_size / 2;
  ASSERT_TRUE(getDnodeAtIndex(list_filled, index));
  node_at_index = getDnodeAtIndex(list_filled, index);
  ASSERT_EQ(node_at_index->data, index);
}