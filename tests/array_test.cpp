#include <gtest/gtest.h>
#include <array.hpp>

TEST(array, init) {
  array<float, 5> a{};
}

TEST(array, indexing_operator) {
  array<int, 5> a{0,1,2,3,4};
  for(int i = 0; i < 5; i++) {
      EXPECT_EQ(a[i], i);
  }
}

TEST(array, indexing_operator_assign) {
  array<int, 5> a;
  for(int i = 0; i < 5; i++) {
      a[i] = i;
  }
  
  for(int i = 0; i < 5; i++) {
      EXPECT_EQ(a[i], i);
  }
}

TEST(array, c_array_transfer) {
  int cArray[] = {0,1,2,3,4};
  array<int, 5> a(cArray);
  for(int i = 0; i < 5; i++) {
      EXPECT_EQ(a[i], i);
  }
}

TEST(array, size) {
  array<float, 5> a{};
  EXPECT_EQ(a.size(), 5);
}

TEST(array, for_loop) {
  array<int, 5> a{0,1,2,3,4};
  int counter = 0;
  for(const int i : a) {
      EXPECT_EQ(counter, i);
      counter++;
  }
}

