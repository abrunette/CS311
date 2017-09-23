//HW2P2
//Name: Aaron Brunette
//Compiler Used: g++
//File type: client file

#include <iostream>
#include <vector>
using namespace std;

//Parameters: L1, L2, and L3 are vectors that are passed by value into
// combine. L1 and L2 hold user inputed values that are compared against
// one another and sorted sequentially into L3. L3 is passed back to main
// by reference to be called there for display. The size of the vectors L1
// and L3 are passed as the size variable.

//Algorithm: Three variables are declared to hold the indexes for the
// three vectors. They all start at index 0. A loop is started to check
// if either of the vectors are out of values. If not then it does a
// a comparison between the values in L1 and L2 at their respective indexes.
// It pushes back the lesser value into L3 at the index i3.
// If either are greater or less the respetive comparison is called and 
// the respective index is incremented as well as the index for L3.
// The both L1 and L2 are checked to see if there are any remaining values.
// If there are they will be appended to the end of L3 since they are
// already sorted. It then ends the function and returns to main.

void Combine(vector<int> L1, vector<int> L2, vector<int> &L3, int size)
{
	int i1 = 0;	//declares initial index for List 1
	int i2 = 0;	//declares initial index for List 2
	int i3 = 0;	//declares initial index for List 3

	//Checks if List 1 or List 2 has values remaining
	//If so continues comparisons
	//else stops comparisons because one list is out of values
	while(i1 != size && i2 != size)
	{
		//compares value in L1 to value in L2
		//pushes smaller value into L3 and increments the index for the pushed value
		//outputs "comparison" to let user know a comparison was made
		if(L1[i1] < L2[i2]) { L3.push_back(L1[i1]); cout << "comparison\n"; i1 = i1 + 1; }
		else { L3.push_back(L2[i2]); cout << "comparison\n"; i2 = i2 + 1; }
	
		i3 = i3 + 1;	//increments L3 index to continue adding to L3
	}
	//checks if there are values left in L1
	//if there are values puts them into L3 in order until none are left in L1
	if(L1.size() != i1)
	{
		while(L1.size() != i1)	//loops to check remaining number of values in L1
		//pushes L2 values into L3, increments variables to keep adding
		{ L3.push_back(L1[i1]); i1 = i1 + 1; i3 = i3 + 1; }
	}
	//if there are no values in L1 checks L2 for leftover values
	// if there are values puts them in to L3 in order until none are left in L2
	else if (L2.size() != i2)
	{
		while(L2.size() != i2)	//loops to check remaining number of values in L2
		//pushes L2 values into L3, increments variables to keep adding
		{ L3.push_back(L2[i2]); i2 = i2 + 1; i3 = i3 + 1; }
	}
	return;
}

//Purpose: To receive input and perform a merge sort to put the values in order
// from smallest to largest.

//Algorithm: Initializes three vectors. Two vectors, L1 and L2, hold user input.
// L3 holds the sorted values from L1 and L2 after they have been compared.
// The variable size holds the number of values the user plans to input.
// The variable hold holds the values that are to be added to the list. There is
// input checking to make sure the user inputs integers only. The variable decision
// is used to determine if the user wants to keep sorting or not. If they want to
// stop it is changed to 0. Otherwise it stays 1. The programs asks for the number
// of values the user wants to add to the lists, value stored in size. If input
// is 0 the program ends. It them moves to input for L1. User inputs a value which
// is checked to make sure it is an integer. If it isn't error is thrown and user
// is asked to input another value. If it is, it is pushed into L3 at the back.
// After the number of inputs for L1 is the same as the size the user input the
// program switches to L2 and follows the same instructions as above for L2.
// The function combine is then called and is passed the three vectors. L1 and
// L2 by value and L3 by reference. All the values in L3 are then displayed in
// main. The program then asks the user if they want to start a new sort. The
// user then inputs 0 or anything else to end or continue sorting.

main()
{
  int cont = 1;		//variable for loop to start new sort
  while(cont != 0)	//loop for starting new sort
  {
	//L1 holds first user inputs
	//L2 holds second user inputs
	//L3 holds the resulting comparions between L1 and L2
	vector <int> L1;	//declares vector L1
	vector <int> L2;	//declares vector L2
	vector <int> L3;	//declares vector L3

	int size = 0;
	int hold;		//user input
	int decision = 1;	//keeps loop going

	//user inputs number of values to be added to both lists 	
	cout << "Please enter the number of values you want to sort for both lists: ";
	cin >> size;	//user input
	
	//checks user input is a digit
	while(isdigit(size)) { cout << "Please enter an integer: "; cin >> size; }
	//if input is 0 ends program, no comparisons to be made
	if(size == 0) { cout << "\nEnding program!\n"; return 0;}
	
	//asks for L1 input, loops for the size the user specifys
	for (int L1size = 0; L1size < size; L1size++)
	{
		//asks for user input
		cout << "\nPlease enter incrementing integers for list 1: ";
		cin >> hold;	//holds user input for exception checking

		while(isdigit(hold))	//checks user input is a digit
		{
			cout << "\nPlease enter an integer: ";	//error message
			cin >> hold;	//user input
		}
		
		L1.push_back(hold);	//if input is a digit, pushes it into L1
	}
	
	cout << "\n\nNow inputing for list 2...\n\n";	//spacing

	//asks for L1 input, loops for the size the user specifys
	for (int L2size = 0; L2size < size; L2size++)
	{
		//asks for user input
		cout << "\nPlease enter incrementing integers for list 2: ";
		cin >> hold;	//holds user input for exception

		while(isdigit(hold))	//checks user input is a digit
		{
			cout << "\nPlease enter an integer: ";	//error message
			cin >> hold;	//user input
		}
		
		L2.push_back(hold);	//if input is a digit, pushes it into L1

	}

	cout << "\n";	//spacing
	Combine(L1, L2, L3, size);	//calls comparison function to merge lists into L3
	cout << endl;			//spacing

	//Displays all values in the L3 list
	for(int l = 0; l < L3.size(); l++)
	{
		cout << L3[l] << " ";	//outputs value in L3
	}
	//checks if user wants to continue sorting
	cout << "\n\nEnter 0 to quit sorting or anything else to continue sorting: ";
	cin >> cont;
	if (cont != 0) { cont = 1; cout << "\n\n\n\n"; } 	//if input isn't 0 starts new sort
  }
}
