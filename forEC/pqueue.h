// Priority Queue Header File by Rika Yoshii
// heaptree impleneted using an array

#include <iostream>
using namespace std;

class pqueue
{
 private:
  int Q[10];   // array holding jobs - only priority numbers are stored
  int count;   // how many jobs are in the array
  // jobs are in slots 0 through count-1

  // Utility functions follow:
  void reheapify();  // reheapify after printing
           // involves moving the last job to the front and trickling down
  void trickleup();  // trickling up after adding at the rear
  bool isEven(int);  // is the number even?  Needed to find the parent
  int smallerchild(int);  // location of the smaller child
                     //- compares L and R children of the given location
  

public:
    pqueue();
    ~pqueue();
    void insertjob(int);  // supply the job priority number
    void printjob();      
    void displayAll();

};
