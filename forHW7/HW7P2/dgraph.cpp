//HW#: 7 Part 2
//Name: Aaron Brunette
//Compiler Used: G++
//File type: Implementation File 

#include "dgraph.h"

dgraph::dgraph()     // initialize vertexName (blank) and visit numbers (0) initialize countUsed to be 0
{
	countUsed = 0;
	//traverses through every location in the graph
	for(int i = 0; i < SIZE; i++)
	{	
		Gtable[i].vertexName = ' ';
		Gtable[i].visit = 0;
	}
}

dgraph::~dgraph()	//calls llist destructor
{

}

//Purpose: To read in information from a file about the out degree and adjacent values
// for the vertexes in a graph, and put them into the graph.
//Parameters: None
void dgraph::fillTable()
{
	char x;			//holds adjacent vertexes
	ifstream fin;		//file read-in
	fin.open("table.txt");

	while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
	{
		fin >> Gtable[countUsed].outDegree;
  		// Then for the outDegree times do the following: (use a for-loop)
  		for(int j = 0; j < Gtable[countUsed].outDegree; j++)
		{
    			fin >> x;
     			(Gtable[countUsed].adjacentOnes).addRear(x); 
                      // this uses a slist function from HW3
  		}//end of for
  		// increment the countUsed
		countUsed++;
	}//end of while
	fin.close();
}

//Purpose: To display the vertex, out degree, and adjacent values of every vertex
// in the graph
//Parameters: None
void dgraph::displayGraph()
{
	//traverses through the whole graph
	for (int l = 0; l < countUsed; l++)
	{ 
		
 
    		cout << "Vertex: " << Gtable[l].vertexName << endl;
    		cout << "Out Degree: " << Gtable[l].outDegree << endl;
		cout << "Displaying all adjacent values:\n";   
 		(Gtable[l].adjacentOnes).displayAll();
		if(Gtable[l].visit != 0)	//checks if a vertex has been visited or not
			cout << "The vertex " << Gtable[l].vertexName << " was visted. (" << Gtable[l].visit << ")\n\n";
		else
			cout << "The vertex " << Gtable[l].vertexName << " was not visited. (0)\n\n";
	}  	
}

//Purpose: Finds the out degree of a specified vertex
//Parameters: Vcheck is the name of the vertex the user is checking
int dgraph::findOutDegree(char Vcheck)  
{
	int count = 0;	//beginning of the graph
	//Checks that the loop is still within countUsed
	while(count < countUsed)
	{
		//checks if the searched vertex exists at location count
		if(Gtable[count].vertexName == Vcheck)
			return Gtable[count].outDegree;
		else	//if not moves to next location
			count++;
	}
	//tells user they searched for a nonexistent vertex
	throw BadVertex();
}

//Purpose: Finds the adjacent values of a specified vertex
//Parameters: Acheck is the vertex the user wants to check for adjacent values
slist dgraph::findAdjacency(char Acheck)
{
	int Acount = 0;	//beginning of the graph
	//Checks that the loop is still within countUsed
	while(Acount < countUsed)
	{
		//checks if the searched vertex exists at location Acount
		if(Gtable[Acount].vertexName == Acheck)
			return Gtable[Acount].adjacentOnes;
		else	//if not moves to next location
			Acount++;
			
	}
	//tells user they searched for a nonexistent vertex
	throw BadVertex();
}

//Purpose: To visit a vertex if it hasn't been already and
// assign it a visit number.
//Paramters: vNum holds the number that the vertex, vName, was
// visited at. vName is the name of the vertex.
void dgraph::visit(int vNum, char vName)
{
	int gLoc = int(vName) - 65;

	Gtable[gLoc].visit = vNum;
}

//Purpose: To check if a vertex has been visited already.
//Parameters: vCheck is the name of the vertex the function is checking.
bool dgraph::isMarked(char vCheck)
{
	int cLoc = int(vCheck) - 65;

	//debug
	//cout << "This is cLoc: " << cLoc << endl;

	if(Gtable[cLoc].visit == 0)
		return 0;

	else
		return 1;
}
























