//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Aaron Brunette
// Compiler:  g++ 
// File type: header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Purpose: to check if the list is empty
  //Parameters: None
  bool isEmpty();
    
  //Purpose: to display all values in the list
  //Parameters: None
  void displayAll();

  //Purpose: to add a node to the front of the list
  //Parameters: holds the value that is placed in the Frontnode
  void addFront(el_t);
    
  //Purpose: to add a node to the front of the list
  //Parameters: holds the value that is placed in the Rear node
  void addRear(el_t);

  //Purpose: to delete a node from the front of the list
  //Parameters: holds the value that is removed from the Front node
  void deleteFront(el_t&);
    
  //Purpose: to delete a node from the rear of the list
  //Parameters: holds the value that is removed the Rear node
  void deleteRear(el_t&);
    
  //Purpose: to delete a node from the Ith place in the list
  // Ith is determined by user input
  //Parameters: holds the value that is removed from the Ith node
  void deleteIth(int, el_t&);

  //Purpose: to add the node before the Ith place in the list
  //Ith is determined by user input
  //Parameters: holds the value that is placed before the Ith node
  void addbeforeIth(int, el_t);
    
};
