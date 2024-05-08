#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}


TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.
TEST(ListTests, FromStringValid) {
    const char* s = "Hello";
    list::Node* head = list::from_string(s);
    EXPECT_NE(head, nullptr);
    std::stringstream ss;
    list::print(ss, head);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
}

TEST(ListTests, FromStringNullptr) {
    list::Node* head = list::from_string(nullptr);
    EXPECT_EQ(head, nullptr);
}

TEST(ListTests, FreeValid) {
    list::Node* head = list::from_string("Test");
    list::free(head);
}

TEST(ListTests, FreeNullptr) {
    list::free(nullptr);
}

TEST(ListTests, PrintValid) {
    list::Node* head = list::from_string("Hello");
    std::stringstream ss;
    list::print(ss, head);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
}

TEST(ListTests, CopyValid) {
    list::Node* head = list::from_string("Hello");
    list::Node* copy = list::copy(head);
    std::stringstream ss;
    list::print(ss, copy);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
    list::free(copy);
}

TEST(ListTests, CopyNullptr) {
    list::Node* copy = list::copy(nullptr);
    EXPECT_EQ(copy, nullptr);
}

TEST(ListTests, CompareEqual) {
    list::Node* head1 = list::from_string("Hello");
    list::Node* head2 = list::from_string("Hello");
    EXPECT_EQ(list::compare(head1, head2), 0);
    list::free(head1);
    list::free(head2);
}

TEST(ListTests, CompareDifferent) {
    list::Node* head1 = list::from_string("Hello");
    list::Node* head2 = list::from_string("World");
    EXPECT_NE(list::compare(head1, head2), 0);
    list::free(head1);
    list::free(head2);
}

TEST(ListTests, LengthValid) {
    list::Node* head = list::from_string("Hello");
    EXPECT_EQ(list::length(head), 5);
    list::free(head);
}

TEST(ListTests, LengthNullptr) {
    EXPECT_EQ(list::length(nullptr), 0);
}

TEST(ListTests, ReverseValid) {
    list::Node* head = list::from_string("Hello");
    list::Node* reversed = list::reverse(head);
    std::stringstream ss;
    list::print(ss, reversed);
    EXPECT_EQ(ss.str(), "olleH");
    list::free(head);
    list::free(reversed);
}

TEST(ListTests, AppendValid) {
    list::Node* head1 = list::from_string("Hello");
    list::Node* head2 = list::from_string("World");
    list::Node* appended = list::append(head1, head2);
    std::stringstream ss;
    list::print(ss, appended);
    EXPECT_EQ(ss.str(), "HelloWorld");
    list::free(head1);
    list::free(head2);
    list::free(appended);
}

TEST(ListTests, AppendNullptr) {
    list::Node* head = list::from_string("Hello");
    list::Node* appended = list::append(head, nullptr);
    std::stringstream ss;
    list::print(ss, appended);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
    list::free(appended);
}

TEST(ListTests, FromStringValid) {
    const char* s = "Hello";
    list::Node* head = list::from_string(s);
    EXPECT_NE(head, nullptr);
    std::stringstream ss;
    list::print(ss, head);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
}

TEST(ListTests, FromStringNullptr) {
    list::Node* head = list::from_string(nullptr);
    EXPECT_EQ(head, nullptr);
}


TEST(ListTests, PrintValid) {
    list::Node* head = list::from_string("Hello");
    std::stringstream ss;
    list::print(ss, head);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
}



TEST(ListTests, ConstructorValidCString) {
    const char* s = "Hello";
    String str(s);
    EXPECT_EQ(str.size(), 5);
    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[4], 'o');
}

TEST(ListTests, ConstructorNullptr) {
    String str(nullptr);
    EXPECT_EQ(str.size(), 0);
}

TEST(ListTests, CopyConstructor) {
    String str1("Hello");
    String str2(str1);
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1[0], str2[0]);
}

TEST(ListTests, MoveConstructor) {
    String str1("Hello");
    String str2(std::move(str1));
    EXPECT_EQ(str1.size(), 0);
    EXPECT_EQ(str2.size(), 5);
}

TEST(ListTests, AssignmentOperator) {
    String str1("Hello");
    String str2;
    str2 = str1;
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1[0], str2[0]);
}

TEST(ListTests, MoveAssignmentOperator) {
    String str1("Hello");
    String str2;
    str2 = std::move(str1);
    EXPECT_EQ(str1.size(), 0);
    EXPECT_EQ(str2.size(), 5);
}

TEST(ListTests, InBoundsValid) {
    String str("Hello");
    EXPECT_TRUE(str.in_bounds(0));
    EXPECT_TRUE(str.in_bounds(4));
    EXPECT_FALSE(str.in_bounds(-1));
    EXPECT_FALSE(str.in_bounds(5));
}


TEST(ListTests, ConstructorValidCString) {
    const char* s = "Hello";
    String str(s);
    EXPECT_EQ(str.size(), 5);
    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[4], 'o');
}

TEST(ListTests, ConstructorNullptr) {
    String str(nullptr);
    EXPECT_EQ(str.size(), 0);
}

TEST(ListTests, CopyConstructor) {
    String str1("Hello");
    String str2(str1);
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1[0], str2[0]);
}

TEST(ListTests, MoveConstructor) {
    String str1("Hello");
    String str2(std::move(str1));
    EXPECT_EQ(str1.size(), 0);
    EXPECT_EQ(str2.size(), 5);
}

TEST(ListTests, AssignmentOperator) {
    String str1("Hello");
    String str2;
    str2 = str1;
    EXPECT_EQ(str1.size(), str2.size());
    EXPECT_EQ(str1[0], str2[0]);
}

TEST(ListTests, MoveAssignmentOperator) {
    String str1("Hello");
    String str2;
    str2 = std::move(str1);
    EXPECT_EQ(str1.size(), 0);
    EXPECT_EQ(str2.size(), 5);
}

TEST(ListTests, InBoundsValid) {
    String str("Hello");
    EXPECT_TRUE(str.in_bounds(0));
    EXPECT_TRUE(str.in_bounds(4));
    EXPECT_FALSE(str.in_bounds(-1));
    EXPECT_FALSE(str.in_bounds(5));
}

TEST(ListTests, ReverseValid) {
    String str("Hello");
    String reversed = str.reverse();
    EXPECT_EQ(reversed.size(), 5);
    EXPECT_EQ(reversed[0], 'o');
    EXPECT_EQ(reversed[4], 'H');
}

TEST(ListTests, IndexOfCharValid) {
    String str("Hello");
    EXPECT_EQ(str.indexOf('H'), 0);
    EXPECT_EQ(str.indexOf('o'), 4);
    EXPECT_EQ(str.indexOf('x'), -1);
}

TEST(ListTests, IndexOfStringValid) {
    String str("Hello World");
    String substr("World");
    EXPECT_EQ(str.indexOf(substr), 6);
}

TEST(ListTests, ConcatenationOperatorValid) {
    String str1("Hello");
    String str2(" World");
    String concatenated = str1 + str2;
    EXPECT_EQ(concatenated.size(), 11);
    EXPECT_EQ(concatenated[5], ' ');
}

TEST(ListTests, ConcatenationOperatorNullptr) {
    String str("Hello");
    String concatenated = str + nullptr;
    EXPECT_EQ(concatenated.size(), 5);
}

TEST(ListTests, ConcatenationAssignmentOperatorValid) {
    String str1("Hello");
    String str2(" World");
    str1 += str2;
    EXPECT_EQ(str1.size(), 11);
    EXPECT_EQ(str1[5], ' ');
}

TEST(ListTests, PrintValid) {
    String str("Hello");
    std::stringstream ss;
    str.print(ss);
    EXPECT_EQ(ss.str(), "Hello");
}

TEST(ListTests, ReadValid) {
    std::stringstream ss("Hello");
    String str;
    str.read(ss);
    EXPECT_EQ(str.size(), 5);
    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[4], 'o');
}
