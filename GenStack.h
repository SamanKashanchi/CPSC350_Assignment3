#ifndef __GENSTACK_H
#define __GENSTACK_H
#include <iostream>

template <typename T>
class Genstack
{
  public:
    T* ArrayStack;
    int top;
    int capacity;
//initiating a stack with defult(has cap of 50) and overloaded constructors
    Genstack() {
      ArrayStack = new T(50);
      capacity = 50;
      top = -1;
    }

    Genstack(int cap) {
      ArrayStack = new T(cap);
      capacity = cap;
      top = -1;
    }

    //Basic Stack Functions

    void push(T val) {
//Checks if stack is full then doubles size if full before pushing.
      if(full())
        MakeSpace();
    	  ArrayStack[++top] = val;
    }
    T pop() {
//Checks if stack is empty thorws expection if needed.
      if(empty())
        throw "Your stack is empty.";
      else
    	 return ArrayStack[top--];
    }

    T peek() {
      return ArrayStack[top];
    }

    bool full() {
    	return (top == capacity - 1);
    }

    bool empty() {
      return (top == -1);
    }

    ~Genstack() {
      delete ArrayStack;
    }

//Doubles stack size when called (stackOverflow)
    void MakeSpace() {
      T* arr = new T[capacity*2];
      for(int i = 0; i < capacity; i++)
      {
        arr[i] = ArrayStack[i];
      }
      capacity *= 2;
      delete ArrayStack;
      ArrayStack = arr;
    }
};
#endif
