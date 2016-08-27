
#include "gtest/gtest.h"
#include "include/linked_list.h"

class LinkedList : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown() {}

 // DLinkedList* test_list = CreateDLinkedList();
};
// Tesing list / node creation
TEST_F(LinkedList, CreatingList) {ASSERT_EQ(0,0);}
