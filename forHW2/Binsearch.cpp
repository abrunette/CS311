//===========================================================
//HW#: HW2P1 analysis
//Your name: Aaron Brunette
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;
#include <iostream>

//Algorithm: This program uses binary search to search through a hard-coded
// array for a value that the user inputs. It then recursively calls the
// search function to sort through the array. The search function,
// binarysearch, takes the middle value and compares it to the searched
// value. If they are equal the middle location is returned. If the
// searched value is less or greater than the middle, the last or first
// value is adjusted. The function then recursively calls itself to repeat
// the process, rechecking each time until there is only one value left.
// When this happens it checks if first and last are equal (1 value left)
// then checks if the searched term is equal to first/last. If it is, then
// it returns the position. If it isn't it returns -1. -1 means the value
// was not found in the array. If the value was found it tells the user the
// position the value was found in, in the array.

//Purpose: Recursively calls itself to sort through an array looking
// for the value the user input.
//Paramter: Recieves the array, List[], x, the value the user wants to
// search for, first, the first slot in the array, and last, the last
// slot in the array.
int binarysearch(int List[], int x, int first, int last)
{
	//middle is the middle of the array
	int middle = ((first + last)/2)+1;	//finds med position
	
	if(x > List[last]) { return -1; }	//checks for overflow
	if(x < List[first]) { return -1; }	//checks for underflow

	//checks if searched term is the same as the term in the middle
	if(x == List[middle]) { return middle;  }
	
	//checks if there is only 1 value left
	else if (first == last) 
	{ 
		//if the value doesn't equal x, returns -1
		if(x != List[first]) { return -1;  }
		else { return first;  }  //else returns position
	}
	
	//checks if x is less than the middle value
	//if so, moves last down one
	else if (x < List[middle]) { last = middle - 1; }
	//checks if x is greater than the middle value
	//if so, moves first up one
	else if (x > List[middle]) { first = middle + 1;  }

	//recursively calls itself with new values
	return binarysearch(List, x, first, last);
}

//Purpose: Uses binarysearch function to search the array for the number
// the user inputs.
//Parameter: None
int main()
{
	int cont = 1;	//loop continue value
	while(cont == 1) //continues searching
	{
		//initializes hard coded 10 slot array
		int binaryarray [10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };	
		int usearch;	//holds the value the user wants to search for
		int first = 0; int last = 9;	//initializes array location variables

		//ask user for input
		cout << "Please enter the number you want to search for: \n";	
		cin >> usearch;	//user input

		while(!cin)	//continuously checks if user input is a number
		{
			cin.clear();	//clears stream
			cin.ignore();	//clears input
			//asks user to reinput value
			cout << "Input is invalid, please search for a number:\n";
			cin >> usearch;	//asks for input again
		}

		//recursively calls binary search function and sends results back out to main
		int resultloc = binarysearch(binaryarray, usearch, first, last);
	
		//outputs number location if it exits, else tells user the number does not exit in the array
		//also corrects position bug
		if(resultloc == -1) { cout << "The number was not found in the array.\n"; }
		else if (resultloc ) {  cout << "The number was found at position " << resultloc << ".\n";  }
		else { cout << "The number was found at position " << resultloc << ".\n"; }

		cout << "\nEnter 0 if you want to quit searching: "; //asks user if they want to continue
		cin >> cont;	cout << endl;	//user input and spacing
		if(cont != 0) { cont = 1; }	//makes sure input is 1 or 0
	}

}//end of program
