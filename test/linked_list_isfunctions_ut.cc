#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
//#include "src/linked_list.c"
}

class LinkedListIsFunctions : public ::testing::Test {
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
};

TEST_F(LinkedListIsFunctions, isTheListEmpty) {
  ASSERT_FALSE(isEmptyDLinkedList(list_null));
  ASSERT_TRUE(isEmptyDLinkedList(list_uninitialized));
  ASSERT_FALSE(isEmptyDLinkedList(list_filled));
}

TEST_F(LinkedListIsFunctions, isTheIndexInTheRangeOfTheList) {
  size_t index = -1;
  ASSERT_FALSE(isIndexInRange(list_filled->size, index));
  index = 0;
  ASSERT_TRUE(isIndexInRange(list_filled->size, index));
  index = list_filled_size - 1;
  ASSERT_TRUE(isIndexInRange(list_filled->size, index));
  index = list_filled_size;
  ASSERT_FALSE(isIndexInRange(list_filled->size, index));
  index = list_filled_size + 1;
  ASSERT_FALSE(isIndexInRange(list_filled->size, index));
}