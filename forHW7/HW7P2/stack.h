//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Aaron Brunette
// Compiler:  g++ 
// File type: header file stack.h
//=======================================================

#ifndef STACK_H
#define STACK_H

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef char el_t;      // the el_t type is int for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  el_t     el[MAX];       // el is  an array of el_t's
  int      top;           // top is index to the top of stack
  
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: Pass by reference the int el_t to the function topElem
  void topElem(el_t&);
  
  // Must add good comments for each function - See Notes1B

  //PURPOSE: returns true if the stack size is -1, else returns false
  bool isEmpty();
  //PURPOSE: returns true if the stack size is == to MAX, else returns false
  bool isFull();
  //PURPOSE: Counts down from the top of stack, returns empty when stack size == -1
  void displayAll();
  //PURPOSE: Sets stack size to -1
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

#endif
