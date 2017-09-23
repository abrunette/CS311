//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.
  
//=========================================================
//HW#: HW1P1 stack
//Your name: Aaron Brunette
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;  
#include <iostream>
#include "vstack.h"

//ALGORITHM: This file containts the functions used in the vstack.cpp file.
// The functions are used to calculate postfix equations input by the user.
// It can determine whether the stack is full and then add or subtract operands
// together. It pushes results to the stack to be futher processed and then
// outputs the result. If there are any errors it displays them to the user.

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{  } // nothing to do
  
//PURPOSE:  removes everything in the stack
stack::~stack()
  {   	// empties the stack
	//el.clearIt();	
  }
//PURPOSE:  checks if the stack is empty. Returns true if it is empty
// else returns false
//PARAMETER: None
bool stack::isEmpty()
{ if (el.size() == 0) return true; else return false; }
    
//PURPOSE: checks if the stack is full. Will always return false because
// the stack cannot become "full".
//PARAMETER: None
bool stack::isFull()
  { return false; }	//Always returns false
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
 void stack::push(el_t elem)
 {
	el.push_back(elem);
 }
 
 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(el_t& elem)
 { if (isEmpty()) throw "Underflow";
   else { 
		elem = el.back();
		el.pop_back();
	}
 }
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(el_t& elem)
 { if (isEmpty()) throw "underflow";
   else { elem = el.back(); } }
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//PARAMETER: None
 void stack::displayAll()
 {  if (isEmpty()) cout << "[ empty ]" << endl;
   else for (int i=el.size()-1; i>=0; i--)
     { cout << el.at(i) << endl; }
   cout << "--------------" << endl;
 }
 
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//PARAMETER: None
 void stack::clearIt()
 {	
	int var;
	while(!isEmpty())
		pop(var);
}
