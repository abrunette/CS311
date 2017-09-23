//HW#: 6
//Name: Aaron Brunette
//Compiler: g++
//File type: Client file

#include "dgraph.h"
using namespace std;

//Purpose: To allow the user to search a graph for certain information. 
//Algorithm: To create a graph with specified vertexes that the user can search for.
// Displays the values in the graph after creating it.
// The user has the option of finding out the out degree and adjacent values of a vertex.
// The program calls the relevent function depending on what the user is looking for.
int main()
{
	dgraph TableObj;	//the graph that holds the file input
	int stop = 1;		//used to determine if the user wants to continue
	char whichV = ' ';	//holds the vertex the user wants to search for
	int result;		//holds the result of the search for out degree
	slist Sresult;		//holds the result of the search for adjacent values
	int caught = 0;		//tells if there was an exception called

	TableObj.fillTable();
	TableObj.displayGraph();

	while(stop == 1)	//runs until the user inputs anything but 1
	{
		cout << "\nPlease enter the vertex out degree you wish to search for: "; 
		cin >> whichV;
		cout << endl;
		try { result = TableObj.findOutDegree(whichV); }
		//tells the user that the vertex they searched for is not in the graph
		catch(dgraph::BadVertex)
    		{ cerr << "ERROR: The vertex you searched for does not exist in the graph!" << endl; caught = 1; }

		if(caught == 0)
			cout << "The Out Degree of vertex " << whichV << " is " << result << endl;

		cout << "If you want to continue, please enter 1.\n";
		cin >> stop;
		caught = 0;
	}
	stop = 1;
	
	while(stop == 1)	//runs until the user inputs anything but 1
	{
		cout << "\nPlease enter the vertex ajacencies you wish to search for: ";
		cin >> whichV;
		cout << endl;
		try { Sresult = TableObj.findAdjacency(whichV); }
		//tells the user that the vertex they searched for is not in the graph
		catch(dgraph::BadVertex)
    		{ cerr << "ERROR: The vertex you searched for does not exist in the graph!" << endl; caught = 1; }
	
		if(caught == 0)
			Sresult.displayAll();		

		cout << "If you want to continue, please enter 1.\n";
		cin >> stop;
		caught = 0;
	}
}
