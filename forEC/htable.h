// Hash Table Header File by Rika Yoshii 

#include <iostream>
using namespace std;
#include "slist2.h"

// I had to create slist2 which has both int and string elements per node 

class htable
{
 private:
  slist table[37];   // each node is a key and name
  int hash(int);  
  
 public:
  htable();
  ~htable();
  int add(int, string); // adds the element to the table
  string find(int);     // looks up using the key - returning the name
  void displayTable();   

};
