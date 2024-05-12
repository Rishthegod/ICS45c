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

Picture& Picture::operator=(const Picture &other){
  if(this != &other){
    Picture temp(other);
    swap(temp);
  }
  return *this;
}

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
  ListNode *current = head; 
  while (current) {
      ListNode *temp = head;
      current = current->next; 
      delete temp->shape;
      delete temp;
    
  }
  
}
