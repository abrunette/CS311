// ====================================================
//HW#: HW3P2 slist with P3 adaptations
//Your name: Aaron Brunette
//Complier:  g++
//File type: slist implementation file
//=====================================================

using namespace std;

#include <iostream>
#include "slist.h" 

//Purpose: To create an empty linked list by calling the inherited
// llist constructor.
//Parameters: None
slist::slist()  // constructor which is the same as the llist one
{
	//llist();
}

//Purpose:to create a copy constructer of a recieved slist list
//Parameters:Original is the slist that is to be copied
slist::slist(const slist& Original)
{
	Node *P;	//local pointer for OtherOne
	P = Original.Front;
	while(P != NULL)	//loops to the end of OtherOne
	{
		this->addRear(P->Elem);
		P = P->Next;
	}
}

//Purpose: to overload the = operator to make a List the same as
// another list.
//Parameters: the list that is to be copied and OtherOne is the list
// that is being copied over.
slist& slist::operator=(const slist& OtherOne)
{
	int temp;	//hold removed variables
	//checks that the two objects are different 
	if(&OtherOne != this)
	{
		//emptying this
		while(!this->isEmpty()) { this->deleteRear(temp); }
		Node *P;	//local pointer for OtherOne
		P = OtherOne.Front;
		while(P != NULL)	//loops to the end of OtherOne
		{
			this->addRear(P->Elem);
			P = P->Next;
		}
	}
	return *this;	//return the result unconditionally
}

//Purpose: to check if two lists are the same or not
//Parameters: the first list to be compared and TheOther
// which is the second list that the first list will be
//compared against
bool slist::operator==(const slist& theOther)
{
	if(this->Count != theOther.Count) {return false;}
	Node *P; Node *Q;
	P = this->Front; Q = theOther.Front;
	while(P != NULL)
	{
		if(P->Elem != Q->Elem) { return false; }
		P = P->Next; Q = Q->Next;
	}
	return true;
}

//Purpose: To search for a specified value in a linked list.
//Parameters: A value from main that is to be search for in the list.
//Algorithm: Uses a while loop to check that the pointer is not at 
// the end of the list. If it is, tells user that the value was not
// found in the list.
int slist::search(el_t Key)
{
	if(isEmpty())	{ cout << "[ empty ]\n"; }
	else 
	{
		int position = 1;	//holds the current location in the list
		Node *p = Front;
		while(p != NULL)	//checks that the Pointer is not after rear
		{
			if(p->Elem == Key) { return position; }
			p = p->Next;
			position++;
		}
		return 0;
 		
	}	

// search through the list to see if any node contains the key.
// If so, return its position (>=1). Otherwise, return 0.
}

//Purpose: To replace the value at a specified location in a linked list.
//Parameters: el_t holds the location in the list that needs to be
// replaced. int holds the value that will replace the one in the list.
void slist::replace(el_t Elem,  int I)
{	
	int temp;	//hold removed variable
	if(I < 1 || I > Count) { throw "OutOfRange"; }
	if(I == 1)
	{
		deleteFront(temp);
		addFront(Elem);
	}
	else if (I == Count)
	{
		deleteRear(temp);
		addRear(Elem);
	}
	else
	{
		deleteIth(I, temp);
		addbeforeIth(I, Elem);
	}

// go to the Ith node (if I is between 1 and Count) and 
// replace the element there with the new element. 
// If I was an illegal value, throw OutOfRange 
}
