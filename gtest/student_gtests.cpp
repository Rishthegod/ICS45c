#include "string.hpp"
#include "gtest/gtest.h"

// Test for static helper method strlen()
TEST(StringFunction, strlen) {
  const char *str = "Hello";
  EXPECT_EQ(String::strlen(str), 5);
}

// Test for static helper method strcpy()
TEST(StringFunction, strcpy) {
  const char *src = "Hello";
  char dest[10];
  String::strcpy(dest, src);
  EXPECT_STREQ(dest, "Hello");
}

// Test for static helper method strncpy()
TEST(StringFunction, strncpy) {
  const char *src = "Hello";
  char dest[10];
  String::strncpy(dest, src, 3);
  EXPECT_STREQ(dest, "Hel");
}

// Test for static helper method strcat()
TEST(StringFunction, strcat) {
  char dest[12] = "Hello";
  const char *src = " World";
  String::strcat(dest, src);
  EXPECT_STREQ(dest, "Hello World");
}

// Test for static helper method strncat()
TEST(StringFunction, strncat) {
  char dest[10] = "Hello";
  const char *src = " World";
  String::strncat(dest, src, 3);
  EXPECT_STREQ(dest, "Hello Wo");
}

// Test for static helper method strcmp()
TEST(StringFunction, strcmp) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  EXPECT_EQ(String::strcmp(str1, str2), 0);
  const char *str3 = "world";
  EXPECT_LT(String::strcmp(str1, str3), 0);
  const char *str4 = "Apple"; 
  EXPECT_GT(String::strcmp(str1, str4), 0);
}

// Test for static helper method strncmp()
TEST(StringFunction, strncmp) {
  const char *str1 = "Hello";
  const char *str2 = "Hel";
  EXPECT_EQ(String::strncmp(str1, str2, 3), 0);
  EXPECT_GT(String::strncmp("hello", "world", 3), 0);
  EXPECT_LT(String::strncmp("world", "hello", 3), 0);
}

// Test for static helper method reverse_cpy()
TEST(StringFunction, reverse_cpy) {
  const char *src = "Hello";
  char dest[10];
  String::reverse_cpy(dest, src);
  EXPECT_STREQ(dest, "olleH");
}

// Test for static helper method strchr()
TEST(StringFunction, strchr) {
  const char *str = "Hello";
  char c = 'e';
  const char *result = String::strchr(str, c);
  EXPECT_EQ(result, str + 1);
}

// Test for static helper method strstr()
TEST(StringFunction, strstr) {
  const char *haystack = "Hello World";
  const char *needle = "World";
  const char *result = String::strstr(haystack, needle);
  EXPECT_EQ(result, haystack + 6);
  const char *needle2 = "apple"; 
  const char *result2 = String::strstr(haystack, needle2);
  EXPECT_EQ(result2, nullptr);
  const char *haystack3 = "";
  const char *needle3 = "hello";
  const char *result3 = String::strstr(haystack3, needle3);
  EXPECT_EQ(result3, nullptr);

  const char *haystack4 = "hello";
  const char *needle4 = "";
  const char *result4 = String::strstr(haystack4, needle4);
  EXPECT_EQ(result4, haystack4);

  const char *haystack5 = "hello";
  const char *needle5 = "hello world";
  const char *result5 = String::strstr(haystack5, needle5);
  EXPECT_EQ(result5, nullptr);

  const char *haystack6 = "hello!@#$%^world";
  const char *needle6 = "!@#$%^";
  const char *result6 = String::strstr(haystack6, needle6);
  EXPECT_EQ(result6, haystack6 + 6);

  const char *haystack7 = "hello world";
  const char *needle7 = " ";
  const char *result7 = String::strstr(haystack7, needle7);
  EXPECT_EQ(result7, haystack7 + 5);
}
