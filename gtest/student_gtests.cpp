#include <gtest/gtest.h>

#include "list.hpp"

#include "string.hpp"

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



TEST(ListTests, FreeValid) {
    list::Node* head = list::from_string("Test");
    list::free(head);
}

TEST(ListTests, FreeNullptr) {
    list::free(nullptr);
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


TEST(ListTests, PrintValid) {
    list::Node* head = list::from_string("Hello");
    std::stringstream ss;
    list::print(ss, head);
    EXPECT_EQ(ss.str(), "Hello");
    list::free(head);
}













TEST(ListTest, NthValid) {
    list::Node* head = list::from_string("Hello");
    EXPECT_EQ(list::nth(head, 0)->data, 'H');
    EXPECT_EQ(list::nth(head, 4)->data, 'o');
    list::free(head);
}

TEST(ListTest, LastValid) {
    list::Node* head = list::from_string("Hello");
    EXPECT_EQ(list::last(head)->data, 'o');
    list::free(head);
}



TEST(ListTest, IndexValid) {
    list::Node* head = list::from_string("Hello");
    list::Node* node = list::nth(head, 2);
    EXPECT_EQ(list::index(head, node), 2);
    list::free(head);
}















TEST(ListTest, LengthEmptyList) {
    list::Node* head = nullptr;
    EXPECT_EQ(list::length(head), 0);
}


TEST(ListTest, AppendEmptyLists) {
    list::Node* head1 = nullptr;
    list::Node* head2 = nullptr;
    list::Node* appended = list::append(head1, head2);
    EXPECT_EQ(appended, nullptr);
}
