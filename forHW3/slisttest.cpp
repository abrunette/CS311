// Use this client file to test your slist after HW3P3 has been completed

#include<iostream>
using namespace std;

#include "slist.h"

slist strange(slist M)
{
  M.addRear(20);
  return M;
}

int main()
{
  slist L;

  for (int i = 1; i <= 10; i++)
    L.addRear(i);

  L.displayAll();
  cout << endl;

  int X;
  for (int i = 1; i <= 10; i++)
    L.deleteRear(X);

  L.displayAll();

  for (int i = 1; i <= 10; i++)
    L.addFront(i);

  L.displayAll();
  cout << endl;
  for (int i = 1; i <= 10; i++)
    L.deleteFront(X);
  L.displayAll();

  for (int i = 1; i <= 10; i++)
    L.addRear(i);

  L.displayAll();
  cout << endl;
  cout << "deleteIth test:" << endl;
  L.deleteIth(1, X);
  L.displayAll();
  cout << endl;
  L.deleteIth(9, X);
  L.displayAll();
  cout << endl;
  L.deleteIth(3, X);
  L.displayAll();
  cout << endl;

  cout << "addbeforeIth test:" << endl;
  L.addbeforeIth(1, 0);
  L.displayAll();
  cout << endl;
  L.addbeforeIth(9, 0);
  L.displayAll();
  cout << endl;
  L.addbeforeIth(3, 0);
  L.displayAll();
  cout << endl;

  cout << "search test:" << endl;
  for (int i = 1; i <= 10; i++)
    cout << i << " found in postition:" << L.search(i) << endl;

  cout << "replace test:" << endl;
  for (int i = 1; i <= 10; i++)
    L.replace(10, i);
  L.displayAll();
  cout << endl;
 
 slist L2;

  L2 = L;

  cout << "L2:";
  L2.displayAll();
  cout << endl;

  L = strange(L2);

  cout << "L2:";
  L2.displayAll();
  cout << endl;
  cout << "L:";
  L.displayAll();
  cout << endl;
}  
   
