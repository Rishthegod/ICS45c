#include "string.hpp"
#include <iostream>
#include <compare>
#include <iosfwd>

// Helper function to copy list::Node to String::Node
static list::Node* copyList(list::Node* head) {
    return list::copy(head);
}

// Helper function to delete list::Node to avoid memory leaks
static void deleteList(list::Node* head) {
    list::free(head);
}

String::String(const char* s) : head(list::from_string(s)) {
    
}

String::String(const String& s) : head(copyList(s.head)) {
    
}

String::String(String&& s) : head(s.head) {
    s.head = nullptr;
}

String::String(list::Node* head) : head(head) {
    
}
void String::swap(String& s) {
    std::swap(head, s.head);
}

String& String::operator=(const String& s) {
    if (this != &s) {
        String temp(s);
        swap(temp);
    }
    return *this;
}

String& String::operator=(String&& s) {
    swap(s);
    return *this;
}

bool String::in_bounds(int index) const {
    return index >= 0 && index < size();
}

char String::operator[](int index) const {
    if (!in_bounds(index)){
        std::cout << "Error: Index out of bounds" << std::endl;
        return '\0';
    }
    return list::nth(head, index)->data;
}

int String::size() const {
    return list::length(head);
}

String String::reverse() const {
    return String(list::reverse(head));
}

int String::indexOf(char c) const {
    list::Node* node = list::find_char(head, c);
    if (!node) return -1;
    return list::index(head, node);
}

int String::indexOf(const String& s) const {
    list::Node* node = list::find_list(head, s.head);
    if (!node) return -1;
    return list::index(head, node);
}

bool String::operator==(const String& s) const {
    return list::compare(head, s.head) == 0;
}

std::strong_ordering String::operator<=>(const String& s) const {
    return list::compare(head, s.head) <=> 0;
}


String String::operator+(const String& s) const {
    list::Node* newHead = list::copy(head);
    list::Node* lastNode = list::last(newHead);
    list::Node* sCopy = list::copy(s.head);
    if (lastNode) {
        lastNode->next = sCopy;
    } else {
        newHead = sCopy;
    }
    return String(newHead);
}

String& String::operator+=(const String& s) {
    list::Node* lastNode = list::last(head);
    list::Node* sCopy = list::copy(s.head);
    if (lastNode) {
        lastNode->next = sCopy;
    } else {
        head = sCopy;
    }
    return *this;
}

void String::print(std::ostream& out) const {
    list::print(out, head);
}

void String::read(std::istream& in) {
    // Clear existing data
    deleteList(head);
    head = nullptr;
    // Read characters into a temporary linked list
    list::Node* tempHead = nullptr;
    list::Node* tempTail = nullptr;
    char c;
    while (in.get(c) && c != '\n') {
        list::Node* newNode = new list::Node{c, nullptr};
        if (!tempHead) {
            tempHead = newNode;
            tempTail = newNode;
        } else {
            tempTail->next = newNode;
            tempTail = newNode;
        }
    }
    // Assign temporary linked list to this String
    head = tempHead;
}

String::~String() {
    deleteList(head);
}



std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}

