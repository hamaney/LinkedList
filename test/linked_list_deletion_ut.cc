#include "gtest/gtest.h"
extern "C" {
#include "include/linked_list.h"
}
class LinkedListDeallocation : public ::testing::Test {
 public:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(LinkedListDeallocation, deallocate_list_nodes) {
  // populate a list
  // NOTE: check with profiling software some corner cases
}