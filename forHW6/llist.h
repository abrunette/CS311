
//****************************************************************************
//  CS311 Linked - by Rika for those who could not get HW3 to work
//  Header File  llist.h
//****************************************************************************

typedef char el_t ;

	   // list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node   *Next;  // next is the pointer to the next node
};

// I could have done class Node and add the data members under public
// but it will use too much space


class llist
{
  
 protected:
  
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
 public:
  
  class Underflow{};
  class OutOfRange {};
    
  llist ();                       // constructor  
  ~llist();                       // destructor
  
  bool isEmpty();
    
  void displayAll();
    
  void addRear(el_t NewNum);
    
  void deleteFront(el_t& OldNum);
    
  void addFront(el_t NewNum);
    
  void deleteRear(el_t& OldNum);
    
  void deleteIth(int I, el_t& OldNum);
    
  void addbeforeIth(int I, el_t newNum);
    
};
