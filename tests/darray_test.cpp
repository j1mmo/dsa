#include <gtest/gtest.h>
#include <darray.hpp>


TEST(darray, init) {
  darray<float> a{};
}

TEST(darray, indexing_operator) {
  darray<int> a{0,1,2,3,4};
  for(int i = 0; i < 5; i++) {
      EXPECT_EQ(a[i], i);
  }
}

TEST(darray, indexing_operator_assign) {
  darray<int> a{0,0,0,0,0};
  for(int i = 0; i < 5; i++) {
      a[i] = i;
  }
  
  for(int i = 0; i < 5; i++) {
      EXPECT_EQ(a[i], i);
  }
}

TEST(darray, c_array_transfer) {
  int cArray[] = {0,1,2,3,4};
  darray<int> a(cArray);
  for(int i = 0; i < 5; i++) {
    EXPECT_EQ(a[i], i);
  }
}

TEST(darray, size) {
  darray<float> a{};
  EXPECT_EQ(a.size(), 0);
}

TEST(darray, for_loop) {
  darray<int> a{0,1,2,3,4};
  int counter = 0;
  for(const int i : a) {
      EXPECT_EQ(counter, i);
      counter++;
  }
}

TEST(darray, push) {
  darray<int> arr;
  for (int i = 0; i < 50; i++) {
      arr.push(i);
  }
  
  for (int i = 0; i < 50; i++) {
      EXPECT_EQ(arr[i], i);
  }
}


