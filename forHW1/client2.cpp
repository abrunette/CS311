//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Aaron Brunette
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"
#include <cstdlib>

//Purpose of the program: Too print out all iterations of A,B,C in 3 characters.
//Algorithm: Queue starts by initializing a string Queue. Has a user input to start
// the loop. Begins by adding A, B, C to queue by default. This is to have a starting
// point for the looping characters that will be appended to the string. It removes
// the front value in the queue and holds it in a temp variable. The temp variable is
// displayed and is then appended with A, B, and C and added back into the queue.
// If there is an error it will throw the relevant error message.
int main()
{ //A, B, C in the queue
    
	queue stringQueue;  	//initialize queue names stringQueue
	int input;		//holds user input to run or stop program

	stringQueue.add("A");	//adds char A before loop
	stringQueue.add("B");	//adds char B before loop
	stringQueue.add("C");	//adds char C before loop

	//Asks user to start program
	cout << "This program runs an infinite loop, input 1 to start: "; cin >> input; cout << endl;
	if(input != 1)	//checks input
	{
		cout << "Ending Program!" << endl; exit(1);	//ends program
	}

    	while(input == 1) 	//loop -- indefinitely
    	{	
      		try	//begins adding and removing to queue to print strings
		{
			string temp; //local temp variable to hold string from queue
			stringQueue.remove(temp);	//removes front and stores in temp
			cout << temp << endl;		//couts front
			stringQueue.add(temp + 'A');	//re-adds front with A
			stringQueue.add(temp + 'B');	//re-adds front with B
			stringQueue.add(temp + 'C');	//re-adds front with C
		}
      		catch(queue::Overflow) //error for full queue
		{	cerr << "Error: Overflow, too many items in queue." << endl; exit(1);	}
		catch(queue::Underflow) //error for empty queue
		{	cerr << "Error: Underflow, no items in queue." << endl;	exit(1); }
		catch (char const* errorcode) //error for invalid item
			{ cerr << "Error: " << errorcode << endl; exit(1); }

    	}
}

