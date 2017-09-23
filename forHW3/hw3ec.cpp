//=========================================================
//HW#: HW3EC operator overload ==
//Your name: Aaron Brunette
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;
#include <iostream>
#include "slist.h"

//Purpose: to display the result of the == comparison
//Parameters: theResult is the returned value of the == overload
void displayResult(bool theResult)
{
	if(theResult == true) { cout << "True, the two lists are the same.\n\n"; }
	else { cout << "False, the two lists are not the same.\n\n"; }
}

//Purpose: to run a specified set of instructions to test the functionality of
// the == operator overload.
//Parameters: None
int main()
{
	cout << "\n\nStarting program...\n";

	slist L1;
	slist L2;
	int temp;

	cout << "Test 1. L1 is empty, L2 is empty.\n";

	displayResult(L1 == L2);

	cout << "Test 2. L1 is empty, L2 has 2 elements.\n";

	L2.addRear(1); L2.addRear(0);

	displayResult(L1 == L2);

	L2.deleteRear(temp); L2.deleteRear(temp);

	cout << "Test 3. L1 has 2 elements, L2 is empty.\n";

	L1.addFront(6); L1.addFront(7);

	displayResult(L1 == L2);

	L1.deleteRear(temp); L1.deleteRear(temp);

	cout << "Test 4. L1 has 1,2,3. L2 has 1,2,3.\n";
	
	//loop to insert 1,2,3 into both lists
	for(int i = 1; i < 4; i++) { L1.addRear(i); L2.addRear(i); }

	displayResult(L1 == L2);

	cout << "Test 5. L1 has 1,2,3. L2 has 1,2.\n";

	L2.deleteRear(temp);

	displayResult(L1 == L2);

	cout << "Test 6. L1 has 1,2,3. L2 has 1,2,3,4.\n";

	for(int i = 1; i < 4; i++) { L1.addRear(i); L2.addRear(i); }

	L2.addRear(3); L2.addRear(4);

	displayResult(L1 == L2);

	cout << "Test 7. L1 has 1,2,3. L2 has 1,2,4.\n";

	L2.deleteIth(3, temp);

	displayResult(L1 == L2);

	cout << "\nEnd of program...\n\n";
}
