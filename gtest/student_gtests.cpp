#include "gtest/gtest.h"
#include "string.hpp"

// Test for static helper method strlen()
TEST(StringFunction, strlen) {
    const char* str = "Hello";
    EXPECT_EQ(String::strlen(str), 5);
}

// Test for static helper method strcpy()
TEST(StringFunction, strcpy) {
    const char* src = "Hello";
    char dest[10];
    String::strcpy(dest, src);
    EXPECT_STREQ(dest, "Hello");
}

// Test for static helper method strncpy()
TEST(StringFunction, strncpy) {
    const char* src = "Hello";
    char dest[10];
    String::strncpy(dest, src, 3);
    EXPECT_STREQ(dest, "Hel");
}

// Test for static helper method strcat()
TEST(StringFunction, strcat) {
    char dest[12] = "Hello";
    const char* src = " World";
    String::strcat(dest, src);
    EXPECT_STREQ(dest, "Hello World");
}

// Test for static helper method strncat()
TEST(StringFunction, strncat) {
    char dest[10] = "Hello";
    const char* src = " World";
    String::strncat(dest, src, 3);
    EXPECT_STREQ(dest, "Hello Wo");
}

// Test for static helper method strcmp()
TEST(StringFunction, strcmp) {
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    EXPECT_EQ(String::strcmp(str1, str2), 0);
}

// Test for static helper method strncmp()
TEST(StringFunction, strncmp) {
    const char* str1 = "Hello";
    const char* str2 = "Hel";
    EXPECT_EQ(String::strncmp(str1, str2, 3), 0);
}

// Test for static helper method reverse_cpy()
TEST(StringFunction, reverse_cpy) {
    const char* src = "Hello";
    char dest[10];
    String::reverse_cpy(dest, src);
    EXPECT_STREQ(dest, "olleH");
}

// Test for static helper method strchr()
TEST(StringFunction, strchr) {
    const char* str = "Hello";
    char c = 'e';
    const char* result = String::strchr(str, c);
    EXPECT_EQ(result, str + 1);
}

// Test for static helper method strstr()
TEST(StringFunction, strstr) {
    const char* haystack = "Hello World";
    const char* needle = "World";
    const char* result = String::strstr(haystack, needle);
    EXPECT_EQ(result, haystack + 6);
}

