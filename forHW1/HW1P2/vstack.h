
// =======================================================
// HW#: HW1P2 stack
// Your name: Aaron Brunette
// Compiler:  g++ 
// File type: headher file 
//=======================================================

#include <vector>

//----- Globally setting up the alias ----------------

typedef int el_t;      // the el_t type is int for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  vector<el_t> el;      // el is  a vector of el_t's
  
 public:
   // the rest will be exactly the same as HW1P1. Therefore
   // the client should not have to change at all.

	class Underflow{};	//thrown when stack underflows 
	class Overflow{};
 
	stack();	//constructor to create an object
	~stack();	//destructor to destroy an object

	//PURPOSE:
	//PARAMETER:
	void push(el_t);

	//PURPOSE:
	//PARAMETER:
	void pop(el_t&);

	//PURPOSE:
	//PARAMETER:
	void topElem(el_t&);
	
	//PARAMETER:
	bool isEmpty();

	//PURPOSE:
	bool isFull();

	//PURPOSE:
	void displayAll();

	//PURPOSE:
	void clearIt();
};
