//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P2 slist with P3 adaptations
// Your name: Aaron Brunette
// Compiler:  g++ 
// File type: header file 
//=======================================================
#include "llist.h"

class slist: public llist	//inherits from llist.h
{
	public:

	//PURPOSE: Contructs an empty linked list using the inherited
	// llist constructor.
	//PARAMETERS: None
	slist();   // constructor which is the same as the llist one

	//Purpose: to create a copy constructor for an slist
	//Parameters: the list that is to be copied
	slist(const slist&);

	//Purpose: to make one list the same as another
	//Parameters: the original list and the list that is being
	// copied over.
	slist& operator=(const slist&);

	//Purpose: to check if two lists are the same as one another
	//Parameters: the original list to be compared and the second list
	bool operator==(const slist&);

	//Purpose: To search for a specified value in a linked list.
	//Parameters: A value from main that is to be search for in the list.
	int search(el_t);
	// search through the list to see if any node contains the key.
	// If so, return its position (>=1). Otherwise, return 0.

	//Purpose: To replace the value at a specified location in a linked list.
	//Parameters: el_t holds the location in the list that needs to be
	// replaced. int holds the value that will replace the one in the list.
	void replace(el_t, int);
	// go to the Ith node (if I is between 1 and Count) and 
	// replace the element there with the new element. 
	// If I was an illegal value, throw OutOfRange 

};
