
//=========================================================
//HW#: HW1P1 stack
//Your name: Octavio Cea
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: Program evaluates postfixed expressions
//Algorithm: Checks expression items using a while loop, converts characters to integers using their ascii value 
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;

  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	if ((int(item) >= 48) && (int(item) <= 57)) 
		{
			int number;
			number = int(item)-48;	
			postfixstack.push(number);
		}
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      	if (item == '-') result = box2-box1;
	      	if (item == '+') result = box2+box1;
	 	if (item == '*') result = box2*box1;
	      //Finally push the result
		postfixstack.push(result);

	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
		cerr << "The stack is full, no more operands can be added to the stack. " << endl;
		exit(1);	
	}
      catch (stack::Underflow) // for too few operands
	{
		cerr << "Not enough operands in the stack to perform operatons. " << endl;
		exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
		cerr << "Invalid Item, please enter integers only. " << endl;
		exit(1);
	}
      // go back to the loop after incrementing i
      	i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
   	postfixstack.pop(box1);
	if (postfixstack.isEmpty() == true)
	cout << "Result: " << box1 << endl;
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
   	if (postfixstack.isEmpty() == false)
		{	
			cerr << "An incomplete expression was found." << endl;
			exit(1);
		}

}// end of the program
