
// =======================================================
// HW#: HW1P1 stack
// Your name: Octavio Cea
// Compiler:  g++ 
// File type: headher file Vstack.h
//=======================================================

//----- Globally setting up the aliases ----------------
#include <vector>
#include<iostream>
using namespace std;

class stack
{ 
  
  private: // to be hidden from the client
  
  vector<int> V;       // el is  a vector of el_t's

  public: // prototypes to be used by the client
  		// Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(int);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(int&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provide variable to receive the top element (pass by ref)
  void topElem(int&);
  
  // You must add good comments for each function - See Notes1B

  //PURPOSE: checks the top of the stack and returns true if it is empty,
  // if it is not empty then it returns false. (if top is empty, top = -1)
  bool isEmpty();
  
  //PURPOSE: If this function returns true,it throws the exception Overflow
  // if it returns false, it adds an element to el and it increments top by 1.
  bool isFull();
  
  //PURPOSE: This function calls isEmpty and if isEmpty returns true, 
  // displayAll displays [ empty ]. to the screen, if isEmpty returns false,
  // displayAll displays the elements in the stack vertically.
  void displayAll();
  
  //PURPOSE: This function pops all the elements from the stack until it 
  // is empty if it is not empty yet.
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

