#include <iostream>
using namespace std;

constexpr int STK_MAX = 1000;

class Stack
{
    int _top;
    char buf[STK_MAX];
  
public:
    Stack(){_top = 0;}
    void push(char c){
        if (_top < STK_MAX) {
            buf[_top++] = c;
        } else {
            cout << "Stack is full. Cannot push more elements"<<endl;
        }
    }
    char pop(){
        if (_top > 0) {
            return buf[--_top];
        } else {
            cout << "Stack is empty. Cannot pop." <<endl;
            return '@';
        }
    }
    char top(){
        if (_top > 0){
            return buf[_top - 1];
        }else{
            cout << "Stack is empty, cannot return top" <<endl;
            return '@';
        }
    }
    bool isEmpty(){
        return _top == 0;
    }
    bool isFull(){
        return _top == STK_MAX;
    }

};
void push_all(Stack & stk, string line) {
    for (char c : line) {
        stk.push(c);
    }
}
void pop_all(Stack & stk){
    while (!stk.isEmpty()) {
        cout << stk.pop();
    }

	cout << endl;
}


