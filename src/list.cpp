#include "list.hpp"
#include <compare>
#include <iosfwd>
#include <iostream>

namespace list {

Node* from_string(const char* s) {
    if (!s) return nullptr; // Check for nullptr
    Node* head = nullptr;
    Node* current = nullptr;
    while (*s) {
        Node* newNode = new Node{ *s, nullptr };
        if (!head) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
        ++s;
    }
    return head;
}

void free(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

void print(std::ostream& out, Node* head) {
    for(; head != nullptr; head = head->next){
        out << head->data; //idk how to implement this
       
    }
}

Node* copy(Node* head) {
if(!head){
    return nullptr;
}
    Node * newhead = new Node{head->data, copy(head->next)};

    return newhead;
    
}

int compare(Node* lhs, Node* rhs) {
    while (lhs && rhs) {
        if (lhs->data < rhs->data){
            return -1;}
        if (lhs->data > rhs->data) {
            return 1;}
        lhs = lhs->next;
        rhs = rhs->next;
    }
    if (!lhs && !rhs) {
        return 0;}
    if (lhs){ 
        return 1;}
    return -1;
}

int compare(Node* lhs, Node* rhs, int n) {
    while (n > 0 && lhs && rhs) {
        if (lhs->data < rhs->data){
            return -1;}
        if (lhs->data > rhs->data) {
            return 1;}
        lhs = lhs->next;
        rhs = rhs->next;
        --n;
    }
    if (n == 0){ 
        return 0;}
    if (!lhs && !rhs) {
        return 0;}
    if (lhs){ 
        return 1;}
    return -1;
}

int length(Node* head) { //not sure if head is permanently lost
    int len = 0;
    while (head) {
        ++len;
        head = head->next;
    }
    return len;
}

Node* reverse(Node* head) {
    Node * temp = nullptr;
    for (Node * p = head ; p!= nullptr; p = p->next){
        temp = new Node{p->data, temp};
    }
    return temp;
}

Node* append(Node* lhs, Node* rhs) {
return !lhs ? copy(rhs) : new Node{lhs->data, append(lhs->next, rhs)};
    
}

int index(Node* head, Node* node) {
    int index = 0;
    while (head) {
        if (head == node){
            return index;}
        ++index;
        head = head->next;
    }
    return -1;
}

Node* find_char(Node* head, char c) {
    while (head) {
        if (head->data == c) {
            return head;}
        head = head->next;
    }
    return nullptr;
}
    
Node* find_list(Node* haystack, Node* needle) {
    /*if (!needle){ 
        return nullptr;}*/
    while (haystack) {
        Node* currhaystack = haystack;
        Node* currneedle = needle;
        while (currhaystack && currneedle && currhaystack->data == currneedle->data) {
            currhaystack = currhaystack->next;
            currneedle = currneedle->next;
        }
        if (!currneedle){ 
            return haystack;}
        
        haystack = haystack->next;
    }
    return nullptr;
}
    

Node* nth(Node* head, int n) {
    int index = 0;
    while (head && index < n) {
        head = head->next;
        ++index;
    }
    return head;
}

Node* last(Node* head) {
    
    if (!head){ 
        return nullptr;}
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}




} // namespace list

