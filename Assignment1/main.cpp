
//=========================================================
//HW#: HW1P1 queue
//Your name: Octavio Cea
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: Test a queue implemented with an array of characters
//Algorithm: uses while loop to remove elements and add modified elements back to the queue
int main()
{
	queue Q;
	string item;//item holder
	Q.add("A");
	Q.add("B");
	Q.add("C");
  
	while (!Q.isEmpty())// loop arround until the queue is empty
	{
	 	try
		{
			Q.remove(item);
			cout << item << " " << endl;
			Q.add(item + "A");
        		Q.add(item + "B");
        		Q.add(item + "C");
		}// closes try

	catch(queue::Overflow)//when queue is full
	{
		cerr << "Queue is full, no more elements can be added. " << endl;
		exit(1);
	}

	catch(queue::Underflow)//when queue has not enough items
        {
                cerr << "There are not enough elements in the queue. " << endl;
                exit(1);
        }
	
	
    	}// closes while loop
}// end of int main

