//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Aaron Brunette
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"
#include <cstdlib>

//Purpose of the program: To call functions to run a postfix calculator 
//Algorithm: First accepts user input of a postfix string. Parses out characters
// from string to analyze individually. Checks if individual characters are operators
// or operands. Pushes operands into stack. If character is an operand it pushes
// the top two operands and appiles the last operator to them. Pushes the result back
// into the stack. If the stack is full, throws Overflow error. If the stack is
// empty, throws Underflow error. If there is an invalid character, throws 
// invalid item error. Also throws general errorcodes if something else occurs.
// If no error or incomplete expression, posts result/last push when complete.
// If there is an incomplete expression, tells user.
int main()
{
	stack postfixstack;  // integer stack
	string expression;   // user entered expression
  
	cout << "type a postfix expression: " ;
  	cin >> expression;	//user inputs
  
  	int i = 0;  // character position within expression
  	char item;  // one char out of the expression
  
  	int box1;  // receive things from pop
  	int box2;  // receive things from pop
  	int result; //holds result of two inputs 
 
  	while (expression[i] != '\0')	//checks for end of string
    	{
		try
		{
	  		item = expression[i];  // current char

	  		//tests for if item is a digit or operand
	  		if(isdigit(item))
	  		{
	      			int dig = int(expression[i])-48;	//converts char to int
	      			postfixstack.push(dig);			//pushes int into stack
				postfixstack.displayAll();		//displays everything in stack
	  		}  
	  
	  		//3.  else if it is an operator,
	  		//    pop the two operands (you might get Underflow exception), and
	 		//	apply the operator to the two operands, and
	  		//    push the result.
	  		else if ( (item == '+') || (item == '-') || (item == '*') )	//test for operator
			{
	      			postfixstack.pop(box1);		//pulls first operand
	      			postfixstack.pop(box2);		//pulls second operand

	      			if (item == '-') result = box2-box1;		//subtraction

	      			else if (item == '+') result = box1+box2;	//addition

	      			else if (item == '*') result = box1*box2;	//multiplication

	      			postfixstack.push(result);	//push operand result
				postfixstack.displayAll();	//display everything in stack
	    		}
	  		else throw "Invalid Item";	//throws error if user inputs invalid item
		} // this closes try
      
      		// Catch exceptions and report problems and quit the program now. 
      		// Error messages describe what is wrong with the expression.
      		catch (stack::Overflow) 
			{ cerr << "The stack is full.\n"; exit(1); }
      		catch (stack::Underflow) // for too few operands
			{ cerr << "The stack is empty.\n"; exit(1); }
      		catch (char const* errorcode) // for invalid item
			{ cerr << "Error: " << errorcode << endl; exit(1); }
      		// go back to the loop after incrementing i
      		i++;
    	}// end of while
  
  	// After the loop successfully completes: 
  	// The result will be at the top of the stack. Pop it and show it.
  
  	postfixstack.pop(result);
  	cout << "The result is: " << result << endl;
  	// If anything is left on the stack, an incomplete expression was found.
  	// Inform the user.

  	try
	{
		if(!postfixstack.isEmpty())
	  	{ throw stack::Overflow();  postfixstack.push(result);	}
     	}//end try
  	catch (stack::Overflow)
	{ 	
		cerr << "There were leftover items in the stack. Incomplete expression.\n" << endl; //informs user of leftover items
  		postfixstack.displayAll();	//posts leftover items in the stack
	}
}// end of the program
