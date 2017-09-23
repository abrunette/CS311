//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: 7 Part 2
//Your name: Aaron Brunette
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1; } // indicate an empty stack
  
//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
  { }	// nothing to do
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
// empty is returned true when the top location is -1.
// In the comment, make sure you define "empty" in terms of top.
//PARAMETER: None
bool stack::isEmpty()
{ if (top == -1) return true; else return false; }
    
//PURPOSE: checks top and returns true if full, false otherwise.
// full is returned true when the top location is 1 less than MAX.
// In the comment, make sure you define "full" in terms of top.
//PARAMETER: None
bool stack::isFull()
  { if (top == MAX-1 ) return true; else return false; }
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
 void stack::push(el_t elem)
 { if (isFull()) throw "Overflow";
   else { top++; el[top] = elem; }}
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
 { if (isEmpty()) throw "Underflow";
   else { elem = el[top]; top--;}}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
 { if (isEmpty()) throw "underflow";
   else { elem = el[top]; } }
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//PARAMETER: None
 void stack::displayAll()
 {  if (isEmpty()) cout << "[ empty ]" << endl;
   else for (int i=top; i>=0; i--)
     { cout << el[i] << endl; }
   cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//PARAMETER: None
 void stack::clearIt()
 {	
	char var;
	while(!isEmpty())
		pop(var);
}
