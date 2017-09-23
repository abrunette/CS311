//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Aaron Brunette
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//Purpose: To initialize an empty linked list.
//Parameters: None
llist::llist()		//constructor
{
	cout << "Calling llist constructor.\n";
	Front = NULL;
	Rear = NULL;
	Count = 0;

/*
Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.
*/
}

//Purpose: To remove a linked list using a while loop to call deleteFront repeatedly.
//Parameters: None
llist::~llist()	//destructor
{
	cout << "Calling llist destructor.\n";
	int x;	//temporary variable to hold removed variable
	while(!isEmpty())
	{
		deleteFront(x);
	}

/*
Destructor  
- while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."
*/
}

//Purpose: To check if a linked list is empty or not.
//Parameters: None
bool llist::isEmpty()
{
	if(Front == NULL && Rear == NULL && Count == 0)
		return true;
	else
		return false;

/*
  - return true if Front and Rear are both pointing to NULL and Count is 0.
  - (all 3 conditions must be checked)
*/
}

//Purpose: To display all values in a linked list.
//Parameters: None
//Algorith: As the P pointer goes down the list the while loop
// checks that is isn't equal to NULL or the location after Rear.
void llist::displayAll()
{
	//cout << "test" << endl;//***
	if(isEmpty())	{ cout << "[ empty ]\n"; }
	else 
	{
		//cout << "test1" << endl;
		//cout << Front->Elem << endl << Rear->Elem << endl;
		Node *P = Front;	//P pointer to run through the linked list
		cout << "[ ";
		while(P != NULL)	//checks that the Pointer is not after rear
		{
			cout << P->Elem << " ";
			P = P->Next;
		}
		cout << "]";
	}

/*
  - Special case: if the list is empty, display [ empty ] ).
  - Regular: 
    displays each element of the list horizontally starting from Front in [ ].
*/
}

//Purpose: To add a node to the end of a linked list.
//Parameters: NewNum holds the value that is to be added to the new node.
// It is passed by value to the function.
void llist::addRear(el_t NewNum) 
{
	if(isEmpty())
	{
		Rear = new Node;
		Rear->Next = NULL;
		Rear->Elem = NewNum;
		Front = Rear;
	}
	else
	{
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = NewNum;
		Rear->Next = NULL;
	}
	Count++;

/*
2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.

    if ( ** )
      {}
      else
	{
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
	}
*/
}

//Purpose: To add a node to the front of a linked list.
//Parameter: NewNum holds the value that is to be added to the new node.
// It is passed by value to the function.
void llist::addFront(el_t NewNum)
{
	if(isEmpty())
	{
		Front = new Node;
		Front->Next = NULL;
		Front->Elem = NewNum;
		Rear = Front;
	}
	else
	{
		Node *x;
		x = new Node;
		x->Next = Front;
		Front = x;
		Front->Elem = NewNum;
	}
	Count++;

/*
2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum and
   Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.

  Regular case:
  Node *x;
  x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;
*/
}

//Purpose: To remove a node from the front of a linked list.
//Parameter: OldNum holds the value that was held in the removed node.
// It is passed back to main by reference to be read to the user.
void llist::deleteFront(el_t& OldNum)
{
	if(isEmpty())
		throw Underflow();
	else if (Count == 1) 
	{ 
		OldNum = Front->Elem;
		delete Front;
		Front = Rear = NULL;
		Count--;  
	}
	else
	{
		OldNum = Front->Elem;
		Node *Second;
  		Second = Front->Next;
		delete Front;
  		Front = Second;
		Count--;
	}

/*
3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.

      if (//error case)
	{}
	else if {//special case)
	  {}
	  else
	    {

  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
	    }
*/
}

//Purpose: To remove a node from the end of a linked list.
//Parameter: OldNum holds the value that was held in the removed node.
// It is passed back to main by reference to be read to the user.
//Algorithm: A while loop is used to move the P pointer down the list.
// p->Next is checked to make sure it is not Rear.
void llist::deleteRear(el_t& OldNum)
{
	if(isEmpty())
		throw Underflow();
	else if (Front == Rear)
	{ 
		OldNum = Rear->Elem;
		delete Rear;
		Front = NULL; Rear = NULL;
		Count--; 
	}
	else
	{
		OldNum = Rear->Elem;
  		Node *p = Front;
		//checks that the node after P is not Rear
		while(p->Next != Rear) { p = p->Next; }
  		delete Rear;
  		Rear = p; Rear->Next = NULL;
		Count--;
	}

/*
 3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p;
      if (//error case)
	{}
	else if {//special case)
	  {}
	  else
	    {

	      Your NAME: 

	      Date turned in:
*/
}

//Purpose: To delete the Ith node in a list.
// Ith is a specified node location from main.
//Parameter: I is the location of the node in the linked list
// that the user or main wants to remove.
// Old num holds the value that was held in the removed node.
// It is passed back by reference to be read to the user.
//Algorithm: A for loop is used to move the p and q pointers down
// the list until it reaches the end.
void llist::deleteIth(int I, el_t& OldNum)
{
	if(I > Count || I < 1)
		throw OutOfRange();

	else if(I == 1) { deleteFront(OldNum); }
	else if(I == Count) { deleteRear(OldNum); }

	else
	{ 
		Node *p = Front; Node *q = Front->Next;		//local pointers to move down the list
		//moves the p and q pointer down the list
		for(int K = 1; K < I-1; K++)
		{ p = p->Next; q = q->Next; }

		OldNum = q->Elem;

		q = q->Next;
		delete p->Next;
		p->Next = q;
		Count--;
	}

/*
4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
*/
}

//Purpose: To add a node to the Ith location in a linked list.
// Ith is a specified node location from main.
//Parameter: I is the location of the node in the linked list
// that the user or main wants to remove.
// Old num holds the value that was held in the removed node.
// It is passed back by reference to be read to the user.
//Algorithm: A for loop is used to move the p and q pointers
// down the list until it reaches the end.
void llist::addbeforeIth(int I, el_t newNum)
{
	if(I > Count+1 || I < 1)
		throw OutOfRange();
	else if(I == 1) { addFront(newNum); }
	else if(I == Count+1) { addRear(newNum); }

	else
	{
		Node *p = Front; Node *q = Front->Next;
		//moves the p and q pointers down the list
		for(int K = 1; K < I-1; K++)
		{ p = p->Next; q = q->Next; }

		p->Next = new Node;
		p->Next->Elem = newNum;
		p = p->Next;
		p->Next = q;
		Count++;
	}

/*
4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Count if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
*/
}










