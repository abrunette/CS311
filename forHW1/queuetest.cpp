
// Queue test program (by Yoshii)
// - Should be used to test your queue class thoroughly
//
// Note that the client knows nothing about the data members
// Note that the client does not know about el_t and MAX
// =========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"    

// Purpose of the Program:
// This test program tests a string queue class you have developed.
// It tests each method using a menu. 
// It displays the queue whenever it is modified.
// How to use: ./a.out after compiling all .cpp files.
// Overall Algorithm: switch inside a do-while loop
int main ()
{
  
  cout << "************** Queue Test Program *************" << endl;
  cout << "This program tests the queue ADT implemented as" << endl;
  cout << "an array.  " << endl;
  cout << "It is a menu based program allowing you to test each method. "
       <<  endl;
  cout << "It displays the entire queue whenever it is modified." << endl;
  cout << "***********************************************" << endl;
  
  queue Q;  // this is the queue object Q
  
  int selection; // this will indicate what the user wants to do
  
  do
    {
      try 
	{
	  cout << endl << "MENU: These are your options: " << endl << endl;
	  cout << "   (1) Add an element   " << endl;
	  cout << "   (2) Display the entire queue  " << endl;
	  cout << "   (3) Remove an element" << endl;
	  cout << "   (4) Display the front element" << endl;
	  cout << "   (5) Check to see if is it empty" << endl;
	  cout << "   (6) Check to see if is it full" << endl;
	  cout << "   (7) Go to Back" << endl;
	  cout << "    Enter ( 0 ) to quit " << endl;
	  cout << "===>";
	  
	  cin >> selection;

	  string toadd;  //this is what the user wants to add to the queue
	  string erased; // this is what is removed from the queue
	  string looked; // this is the element at the front
	  
	  switch (selection) {
	    
	  case 1:  // the Add choice
	    cout << "Enter a string to be added : ";
	    cin >> toadd;
	    Q.add(toadd);
	    cout << "The updated contents of the queue are:  " << endl;
	    Q.displayAll();
	    break;
	    
	  case 2: // the Display choice
	    cout << "The current contents are: " << endl;
	    Q.displayAll();
	    break;
	    
	  case 3:  // The Pop choice
	    Q.remove(erased);
	    cout << erased << " has been removed." << endl;
	    cout << "The updated contents of the queue are: ";
	    Q.displayAll();
	    break;
	    
	  case  4:  // the top element case 
	    Q.frontElem(looked);
	    cout << looked << " is at the front." << endl;
	    break;
	    
	  case 5:   // the check-empty case
	    if (Q.isEmpty())
	      cout << "Queue is empty right now." << endl;
	    else
	      cout << "Queue has some elements." << endl;
	    break;
	    
	  case 6:   // the check-full case
	    if (Q.isFull())
	      cout << "Queue is full right now." << endl;
	    else
	      cout << "Queue has more room." << endl;
	    break;
	    
	  case 7:   // go to back case
	    Q.goToBack();
	    Q.displayAll();
	    break;
	    
	  }   // end of switch statement
	  
	}// end of try - Now catch exceptions
      catch(queue::Overflow)
	{cerr << "Error: You have caused the queue to overflow." << endl;}
      catch(queue::Underflow)
	{cerr << "Error: You have caused the queue to underflow." << endl;}
      
    } while(selection!=0);
  
  cout << "Bye bye - ending the queue test program" << endl;
  
}// end of main

