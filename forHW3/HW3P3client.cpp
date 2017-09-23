//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P3 slist
//Your name: Aaron Brunette
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: This function simply tests the copy constructor of the slist class
//and adds 6 to a the rear of copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList
void CopyTest(slist copiedList)
{
  cout << "in copy test" << endl;
 
  copiedList.addRear(6);
  copiedList.displayAll();
 
  cout << "\nfinished" << endl;
}


//PURPOSE of the Program: to run a specified set of instructions in order
// to test the = overload and the copy constructor.
//Algorithm/Design: some for loops are used to add values to the list
// otherwise goes normally through the program.
int main()
{
  slist L1, L2;
  int temp;
  int counter = 1;

 //1.Create a 5 element list with  1,2,3,4,5 (L1)
  cout << counter << endl; counter++;
  for(int i = 1; i < 6; i++) { L1.addRear(i); } 
 
  //2.Pass the list to a client function called CopyTest to 
  //test your copy constructor.
  cout << counter << endl; counter++;
  CopyTest(L1);
  cout << "-- After copytest --- " << endl;

  //3.Display L1 (this should still be a 5 element list)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << "\n-- Testing operator overloading ---" << endl;

  //4.Do L1 = L1;
  cout << counter << endl; counter++;
  L1 = L1;

  //5.Display L1    (this should still be 1 2 3 4 5)
  cout << counter << endl; counter++;
  L1.displayAll();

  //6.Create a 4 element list L2 with 7,8,9,10.
  cout << endl << counter << endl; counter++;
  for(int k = 7; k < 11; k++) { L2.addRear(k); }

  //7.Display L2
  cout << counter << endl; counter++;
  L2.displayAll();

  //8.Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << endl << counter << endl; counter++;
  L2 = L1;

  //9.Display L2.
  cout << counter << endl; counter++;
  L2.displayAll();

  //10.Remove a rear node from L1. (This should not affect L2).
  cout << endl << counter << endl; counter++;
  L1.deleteRear(temp);

  //11.Display L1.   (L1 is 1,2,3,4)
  cout << counter << endl; counter++;
  L1.displayAll();

  //12.Display L1 again. (4 elements . just to make sure)
  cout << endl << counter << endl; counter++;
  L1.displayAll();

  //13.Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << endl << counter << endl; counter++;
  L2.displayAll();
  cout << endl;

 }//end of program

