#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
//#include "src/linked_list.c"
}

class LinkedListInsertion : public ::testing::Test {
 public:
  virtual void SetUp() {
    GenerateDLinkedListForTesting(list_filled, list_filled_size);
  }
  virtual void TearDown() {
    FreeDLinkedListNodes(list_null);
    FreeDLinkedListNodes(list_uninitialized);
    FreeDLinkedListNodes(list_filled);
    free(list_null);
    free(list_uninitialized);
    free(list_filled);
  }
  DLinkedList* list_null = NULL;
  DLinkedList* list_uninitialized = CreateDLinkedList();
  size_t list_filled_size = 7;
  DLinkedList* list_filled = CreateDLinkedList();
  DNode* DNode_nullptr = NULL;
};

TEST_F(LinkedListInsertion, insertANodeToHeadOfAList) {
  AddDNodeAtHead(list_null);
  ASSERT_EQ(list_null, nullptr);

  AddDNodeAtHead(list_uninitialized);
  ASSERT_NE(list_uninitialized->head, nullptr);
  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
  ASSERT_EQ(list_uninitialized->size, 1);

  DNode* old_list_filled_head = list_filled->head;
  AddDNodeAtHead(list_filled);
  ASSERT_NE(list_filled->head, nullptr);
  ASSERT_EQ((list_filled->head)->next, old_list_filled_head);
  ASSERT_EQ((list_filled->head)->prev, nullptr);
  ASSERT_EQ(list_filled->head, old_list_filled_head->prev);
  ASSERT_EQ(list_filled->size, list_filled_size + 1);
}

TEST_F(LinkedListInsertion, insertANodeToTailOfAList) {
  AddDNodeAtTail(list_null);
  ASSERT_EQ(list_null, nullptr);

  AddDNodeAtTail(list_uninitialized);
  ASSERT_NE(list_uninitialized->head, nullptr);
  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
  ASSERT_EQ(list_uninitialized->size, 1);

  DNode* old_list_filled_tail = list_filled->tail;
  AddDNodeAtTail(list_filled);
  ASSERT_EQ((list_filled->tail)->prev, old_list_filled_tail);
  ASSERT_EQ((list_filled->tail)->next, nullptr);
  ASSERT_EQ(list_filled->tail, old_list_filled_tail->next);
  ASSERT_EQ(list_filled->size, list_filled_size + 1);
}

TEST_F(LinkedListInsertion, insertANodeAtIndexOfList) {
  // Same apply for any index value will give the same result
  // list = NULL , I = -1
  // list = NULL , I = 0
  // list = NULL , I = MiddleValue
  // list = NULL , I = size
  size_t index = 0;
  ASSERT_FALSE(InsertNewDNodeAt(list_null, index));

  // Same apply for any index value will give the same result
  // list = Empty , I = -1
  // list = Empty , I = 0
  // list = Empty , I = MiddleValue
  // list = Empty , I = size
  InsertNewDNodeAt(list_uninitialized, index);
  ASSERT_NE(list_uninitialized->head, nullptr);
  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
  ASSERT_EQ(list_uninitialized->size, 1);

  // list = filled , I = -1
  index = -1;
  ASSERT_FALSE(InsertNewDNodeAt(list_filled, index));

  // list = filled , I = 0
  index = 0;
  DLinkedList* temp_list = CreateDLinkedList();
  GenerateDLinkedListForTesting(temp_list, list_filled_size);
  size_t old_temp_list_size = temp_list->size;
  DNode* B_node = getDnodeAtIndex(temp_list, index);
  DNode* A_node = DNode_nullptr;
  InsertNewDNodeAt(temp_list, index);
  size_t new_temp_list_size = temp_list->size;
  DNode* new_node = getDnodeAtIndex(temp_list, index);
  ASSERT_EQ(new_node->prev, A_node);
  ASSERT_EQ(new_node->next, B_node);
  ASSERT_EQ(new_node, B_node->prev);
  ASSERT_EQ(new_temp_list_size, old_temp_list_size + 1);
  FreeDLinkedListNodes(temp_list);
  free(temp_list);
  temp_list = NULL;

  // list = filled , I = MiddleValue
  index = list_filled_size / 2;
  temp_list = CreateDLinkedList();
  GenerateDLinkedListForTesting(temp_list, list_filled_size);
  old_temp_list_size = temp_list->size;
  B_node = getDnodeAtIndex(temp_list, index);
  A_node = B_node->prev;
  InsertNewDNodeAt(temp_list, index);
  new_temp_list_size = temp_list->size;
  new_node = getDnodeAtIndex(temp_list, index);
  ASSERT_EQ(new_node->prev, A_node);
  ASSERT_EQ(new_node->next, B_node);
  ASSERT_EQ(new_node, A_node->next);
  ASSERT_EQ(new_node, B_node->prev);
  ASSERT_EQ(new_temp_list_size, old_temp_list_size + 1);
  FreeDLinkedListNodes(temp_list);
  free(temp_list);
  temp_list = NULL;

  // list = filled , I = size-1 insert at tail
  index = list_filled_size - 1;
  temp_list = CreateDLinkedList();
  GenerateDLinkedListForTesting(temp_list, list_filled_size);
  old_temp_list_size = temp_list->size;
  B_node = getDnodeAtIndex(temp_list, index);
  A_node = B_node->prev;
  InsertNewDNodeAt(temp_list, index);
  new_temp_list_size = temp_list->size;
  new_node = getDnodeAtIndex(temp_list, index);
  ASSERT_EQ(new_node->prev, A_node);
  ASSERT_EQ(new_node->next, B_node);
  ASSERT_EQ(new_node, A_node->next);
  ASSERT_EQ(new_node, B_node->prev);
  ASSERT_EQ(new_temp_list_size, old_temp_list_size + 1);
  FreeDLinkedListNodes(temp_list);
  free(temp_list);
  temp_list = NULL;

  // list = filled , I = size
  index = list_filled_size;
  ASSERT_FALSE(InsertNewDNodeAt(list_filled, index));

  // list = filled , I = sizePlus
  index = list_filled_size + 1;
  ASSERT_FALSE(InsertNewDNodeAt(list_filled, index));
}
