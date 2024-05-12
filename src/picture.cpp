#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture():head(nullptr), tail(nullptr){}

Picture::Picture(const Picture& other){
  ListNode *current = other.head;
  while(current){
    ListNode *newNode = new ListNode{current->shape->clone(), nullptr};
    if (!head){
      head  = newNode;
      tail =newNode;
      
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
    current = current -> next;
    
  }
    
}

Picture::Picture(Picture &&other){
  head = other.head;
  tail = other.tail;
  other.head = nullptr;
  other.tail = nullptr; 
}

void Picture::swap(Picture &other){
  std::swap(head, other.head);
  std::swap(tail, other.tail);
}

Picture &Picture::operator=(const Picture &other) {

  // using swap for the copy assignment like I did for hw 3,4,5 was giving me sanitizer errors for some reason, so had to do it manually.
    if (this != &other) {
        // Clear existing data
        ListNode *current = head;
        while (current) {
            ListNode *temp = current;
            current = current->next;
            delete temp->shape;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;

        // Copy new data
        ListNode *currentOther = other.head;
        
        while (currentOther) {
            ListNode *newNode = new ListNode{currentOther->shape->clone(), nullptr};
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            currentOther = currentOther->next;
        }
    }
    return *this;
}


/*
Picture& Picture::operator=(const Picture &other){
  
  if(this != &other){
    Picture temp(other);
    swap(temp);
  }
  return *this;
}*/

Picture& Picture::operator=(Picture &&other){
  
  swap(other);
  return *this;
}

void Picture::add(const Shape &shape){
  ListNode *newNode = new ListNode{shape.clone(), nullptr};
  if (!head) { 
    head = newNode;
    tail = newNode;
  }
  else{
    tail->next = newNode;
    tail = newNode;
  }
}

void Picture::print_all(std::ostream& out) const{
  ListNode *current = head; 
  while (current) { 
  current -> shape -> print(out);
  current -> shape -> draw(out);
  current = current -> next;}
}

void Picture::draw_all(std::ostream& out) const{
  ListNode *current = head; 
  while (current) { 
  current -> shape -> draw(out);
  current = current -> next;}
}

double Picture::total_area() const{
  double total = 0.0;
  ListNode *current = head;
  while (current) { 
    total += current -> shape -> area();
    current  =current -> next;
    
  }
  return total;
}


Picture::~Picture(){

  while (head) {
      ListNode *temp = head -> next;
      delete head->shape;
      delete head;
      head = temp;
    
  }
  
}
