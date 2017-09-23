//HW#: 7 Part 2
//Name: Aaron Brunette
//Compiler Used: g++
//File type: client

#include <iostream>
#include "dgraph.h"
#include "stack.h"
using namespace std;

//Purpose: To read in graph data from a file in order to
// perform DFS on the data.
//Algorithm/Design: The program holds the information from the file in
// a dgraph object that includes infomation about each vertex. It also
// initializes a stack to hold adjacent values, as well as a linked list
// to temporarily hold adjacent values before moving them to the stack.
// It then visits each object in the stack in order of Depth First. It
// checks each new vertex it visits to make sure it hasn't been visited
// already and marks the vertexes that haven't been visited with a
// consecutive number to show the order the graph took. It shows the stack
// after every successful visit then displays the entire graph with the order.
int main()
{
	dgraph TableObj;	//initializes dgraph object
	stack adjacentStack;	//initializes stack 
	slist adjacentList;	//initializes linked list
	char vHold;		//holds vertex name for DFS
	int traverse = 2;	//holds visit number, 1 is A by default

	TableObj.fillTable();		//fills TableObj from table.txt
	TableObj.displayGraph();	//displays TableObj

	//visits vertex 'A' and gives it a visit value of 1 by default
	TableObj.visit(1, 'A');

	cout << "\n\n\nNow doing DFS...\n\n\n\n";

	cout << "\nVisited A...\n\n";
	adjacentList = TableObj.findAdjacency('A');

	//while linked list is not empty, moving vertexes from slist to stack
	while(!adjacentList.isEmpty())
	{
		adjacentList.deleteRear(vHold);
		adjacentStack.push(vHold);
	}

	adjacentStack.displayAll();
	cout << endl;			//spacing

	//while stack is not empty, pops adjacent from stack
	while(!adjacentStack.isEmpty())
	{
		cout << "Pulling a vertex from the stack...\n";
		adjacentStack.pop(vHold);

		cout << "Vertex Name: " << vHold << endl;
		//checks if visit is 0, if so does statement
		if(!TableObj.isMarked(vHold) == 1)
		{
			TableObj.visit(traverse, vHold);
			cout << "Visited " << vHold << "...\n";
			adjacentList = TableObj.findAdjacency(vHold);

			//moving vertexes from slist to stack
			while(!adjacentList.isEmpty())
			{
				adjacentList.deleteRear(vHold);
				adjacentStack.push(vHold);
			}
			cout << "stack is:\n";
			adjacentStack.displayAll();
			cout << endl;	//spacing
			traverse++;	//increase visit number
		}
		else	//tells user the vertex has already been visited
			cout << "Vertex " << vHold << " has already been visited.\n\n";
	}
	cout << endl << endl << "Displaying final graph after DFS..." << endl << endl;
	TableObj.displayGraph();

	return 0;
}
