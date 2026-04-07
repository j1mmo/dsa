#include <gtest/gtest.h>
#include <string.hpp>

const string s("hello world");


TEST(string, string_copy) {
  string s2("hello my name is jeff");
  string s3 = s2;
  EXPECT_NE(s2.data(), s3.data());
  EXPECT_EQ(s2.size(), s3.size());
}

TEST(string, indexing) {
  EXPECT_EQ(s[0], 'h');
  EXPECT_EQ(s[1], 'e');
  EXPECT_EQ(s[2], 'l');
  EXPECT_EQ(s[3], 'l');
  EXPECT_EQ(s[4], 'o');
  EXPECT_EQ(s[5], ' ');
  EXPECT_EQ(s[6], 'w');
  EXPECT_EQ(s[7], 'o');
  EXPECT_EQ(s[8], 'r');
  EXPECT_EQ(s[9], 'l');
  EXPECT_EQ(s[10], 'd');
}

TEST(string, string_size) {
  EXPECT_EQ(s.size(), 11);
}

TEST(string, number_to_string) {
  string a = string::toString(123);
  string b = string::toString(12);
  string c = string::toString(1);
  string d = string::toString(0);

  string am = string::toString(-123);
  string bm = string::toString(-12);
  string cm = string::toString(-1);
  string dm = string::toString(0);

  EXPECT_EQ(a.size(), 3);
  EXPECT_STREQ(a.data(), "123");
  EXPECT_STREQ(b.data(), "12");
  EXPECT_STREQ(c.data(), "1");
  EXPECT_STREQ(d.data(), "0");

  /*
  EXPECT_STREQ(am.data(), "-123");
  EXPECT_STREQ(bm.data(), "-12");
  EXPECT_STREQ(cm.data(), "-1");
  EXPECT_STREQ(dm.data(), "0");
  */
  
}
