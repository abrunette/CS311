
// Stack test program (by Yoshii)
// -- Should be used to test your stack class thoroughly
//
// Note that the client knows nothing about the data members
// Note that the client does not know about el_t and MAX
// =========================================================

using namespace std;

#include <iostream>
#include "stack.h"    

// Purpose of the Program:
// This test program tests an integer stack class you have developed.
// It tests each method using a menu.
// It displays the stack whenever it is modified.
// How to use: ./a.out after compiling all .cpp files.
// Overall Algorithm: switch inside a do-while loop
int main ()
{
  
  cout << "************** STACK Test Program *************" << endl;
  cout << "This program tests an integer stack ADT implemented as" << endl;
  cout << "an array.  " << endl;
  cout << "It is a menu based program allowing you to test each method. "
       <<  endl;
  cout << "It displays the entire stack whenever it is modified." << endl;
  cout << "***********************************************" << endl;
  
  stack S;  // this is the stack object S
  
  int selection; // this will indicate what the user wants to do
  
  do
    {
      try 
	{
	  cout << endl << "MENU: These are your options: " << endl << endl;
	  cout << "   (1) Push an element   " << endl;
	  cout << "   (2) Display the entire stack  " << endl;
	  cout << "   (3) Pop the top element" << endl;
	  cout << "   (4) Display the top element" << endl;
	  cout << "   (5) Check to see if is it empty" << endl;
	  cout << "   (6) Check to see if is it full" << endl;
	  cout << "   (7) Clear the entire stack" << endl;
	  cout << "    Enter ( 0 ) to quit " << endl;
	  cout << "===>";
	  
	  cin >> selection;

	  int toadd; //this is the number the user wants to add to the stack
	  int erased; // this is the number removed from the stack
	  int looked; // this is the number at the top
	  
	  switch (selection) {
	    
	  case 1:  // the Push choice
	    cout << "Enter a positive integer to be added : ";
	    cin >> toadd;
	    S.push(toadd);
	    cout << "The updated contents of the stack are:  " << endl;
	    S.displayAll();
	    break;
	    
	  case 2: // the Display choice
	    cout << "The current contents are: " << endl;
	    S.displayAll();
	    break;
	    
	  case 3:  // The Pop choice
	    S.pop(erased);
	    cout << erased << " has been removed." << endl;
	    cout << "The updated contents of the stack are: ";
	    S.displayAll();
	    break;
	    
	  case  4:  // the top element case 
	    S.topElem(looked);
	    cout << looked << " is at the top." << endl;
	    break;
	    
	  case 5:   // the check-empty case
	    if (S.isEmpty())
	      cout << "Stack is empty right now." << endl;
	    else
	      cout << "Stack has some elements." << endl;
	    break;
	    
	  case 6:   // the check-full case
	    if (S.isFull())
	      cout << "Stack is full right now." << endl;
	    else
	      cout << "Stack has more room." << endl;
	    break;
	    
	  case 7:   // the clear the stack case 
	    S.clearIt();
	    S.displayAll();
	    break;
	    
	  }   // end of switch statement
	  
      }// end of try - Now catch exceptions
      catch(stack::Overflow)
	{cerr << "Error: You have caused the stack to overflow." << endl;}
      catch(stack::Underflow)
	{cerr << "Error: You have caused the stack to underflow." << endl;}
      
    } while(selection!=0);
  
  cout << "Bye bye - ending the stack test program" << endl;
  
}// end of main

