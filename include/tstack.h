// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename Type, int size>
class TStack {
  private:
    Type arr[100];
    int top;
    
  public:
    TStack() :top(-1) {}
    void push(Type value) {
      if (isFull()) {
        throw std::string("Full!");
      } else {
        arr[++top] = value;
      }
    }
    const Type& pop() {
      if (isEmpty()) {
        throw std::string("Empty!");
      } else {
        return arr[top--];
      }
    }
    const Type& get()const {
      return arr[top];
    }
    bool isEmpty()const {
      return top == -1;
    }
    bool isFull()const {
      return top == size - 1;
    }
};   
#endif // INCLUDE_TSTACK_H_
