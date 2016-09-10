//#include "gtest/gtest.h"
//extern "C" {
//#include "include/linked_list.h"
//// #include "src/linked_list.c"
//}
//
//class LinkedList_insertion : public ::testing::Test {
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
//
//TEST_F(LinkedList_insertion, insert_a_node_to_the_end_of_an_empty_list) {
//  // Assgine to cuurent test
//  AddDNode(list_uninitialized);
//  ASSERT_NE(list_uninitialized->head, DNode_nullptr);
//  ASSERT_NE(list_uninitialized->tail, DNode_nullptr);
//  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
//  ASSERT_NE(list_uninitialized->size, 0);
//}
//
//TEST_F(LinkedList_insertion, insert_a_node_to_the_end_of_a_nonempty_list) {
//  // full list
//  AddDNode(list_uninitialized);
//  // extract it data
//  DNode* original_list_tail = list_uninitialized->tail;
//  size_t original_list_size = list_uninitialized->size;
//  AddDNode(list_uninitialized);
//  ASSERT_EQ(list_uninitialized->tail, (original_list_tail)->next);
//  ASSERT_EQ(list_uninitialized->tail->prev, original_list_tail);
//  ASSERT_EQ(list_uninitialized->size, original_list_size + 1);
//}
//
//TEST_F(LinkedList_insertion, insert_a_node_to_the_start_of_an_empty_list) {
//  AddDNodeAtHead(list_uninitialized);
//  ASSERT_NE(list_uninitialized->head, DNode_nullptr);
//  ASSERT_NE(list_uninitialized->tail, DNode_nullptr);
//  ASSERT_EQ(list_uninitialized->head, list_uninitialized->tail);
//  ASSERT_EQ(list_uninitialized->size, 1);
//}
//
//TEST_F(LinkedList_insertion, insert_a_node_to_the_start_of_nonempty_list) {
//  DNode* original_list_head = list_filled->head;
//  // DNode* original_list_tail = list_filled->tail;
//  size_t original_list_size = list_filled->size;
//  AddDNodeAtHead(list_filled);
//  ASSERT_NE(list_filled->head, original_list_head);
//  ASSERT_EQ(list_filled->head->next, original_list_head);
//  ASSERT_EQ(list_filled->head, original_list_head->prev);
//  ASSERT_EQ(list_filled->size, original_list_size + 1);
//}
//
//TEST_F(LinkedList_insertion, insert_a_node_to_the_midile_of_nonempty_list) {
//  // Original          [A Dnode]-[B   DNode]
//  // New structure     [A Dnode]-[New DNode]-[B DNode]
//  // prepare
//  // new node info
//  size_t new_node_index = 6;
//  // get orriginal info
//  size_t original_list_size = list_filled->size;
//  DNode* B_node = getDnodeAtIndex(list_filled, new_node_index);
//  // DNode* A_node = B_node->prev;
//
//  // make insertion
//  // PrintListValues(list_filled);
//  // DNode* new_node = InsertNewDNodeAt(list_filled, new_node_index);
//  // PrintListValues(list_filled);
//  // ASSERT_EQ(new_node, getDnodeAtIndex(list_filled, new_node_index));
//  //  ASSERT_EQ(new_node->prev, A_node);
//  //  ASSERT_EQ(new_node, A_node->next);
//  //  ASSERT_EQ(new_node->next, B_node);
//  //  ASSERT_EQ(new_node, B_node->prev);
//  //  ASSERT_EQ(list_filled->size, original_list_size + 1);
//}
