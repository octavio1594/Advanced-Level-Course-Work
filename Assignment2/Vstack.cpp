  
//=========================================================
//HW#: HW1P1 stack
//Your name: Octavio Cea
//Complier:  g++
//File type: stack implementation file
//=========================================================

#include "Vstack.h"

//PURPOSE:  Constructor does not have to do anything.
stack::stack()
{ 
 
}		
  
//PURPOSE:  Destructor has to make sure there are no cells left behind.
stack::~stack()
{
	clearIt();
}			
  
//PURPOSE:  checks top and returns true if empty, false otherwise.
// 	    If the stack is empty, top = -1 .
bool stack::isEmpty()
{ 
	if (V.size() == 0)
		return true;
	else 
		return false;
}
    
//PURPOSE: checks top and returns true if full, false otherwise.
//	   The stack is full if top = MAX -1.
bool stack::isFull()
{ 
	return false;	 //returns false all the time since vector grows and shrinks, never fills up.
}
  
//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
 void stack::push(int num)
 {
	V.push_back(num);
 }

 //PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
 //  Otherwise, removes an element from el and gives it back.
 //PARAMETER: provide a holder (elem) for the element popped (pass by ref)
 void stack::pop(int& elem)
 { 
	if (isEmpty())
		throw Underflow();
   	else 
	{ 
		elem = V.back();
		V.pop_back();
	}
}
 
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
 void stack::topElem(int& elem)
 { 
	if (isEmpty()) 
		throw Underflow();
   	else 
		elem = V.back(); 
 }
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
 void stack::displayAll()
 {  
	if (isEmpty()) 
		cout << "[ empty ]." << endl;
   	else 
		for (int i = (V.size() - 1); i >= 0; i--)
     		{ 
			cout << V[i] << endl;
		}
   	
	cout << "--------------" << endl;
 }
 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
 void stack::clearIt()
 {
	if (isEmpty()) 
                cout << "[ empty ]." << endl;
	else
		for (int i = (V.size()-1); i < V.size(); i--)
                { 
                        pop(V[i]);
		}
						// i is a local variable
}
 

