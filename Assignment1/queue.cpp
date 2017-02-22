
//=========================================================
//HW#: HW1P1 queue
//Your name: Octavio Cea
//Complier:  g++
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
	front = 0;
	rear = -1;
	count = 0;
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if(count == 0)
		return true;
	else 
		return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if(count == MAX_SIZE)
		return true;
	else
		return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
	if(isFull())
		throw Overflow();
	else
	{
		rear = (rear+1) % MAX_SIZE; 
		el[rear] = newElem; 
		count++;
	}
}

// PURPOSE: if empty, throws exemption underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
	if(isEmpty())
		throw Underflow();
	else
	{
		removedElem = el[front]; 
		front = (front+1) % MAX_SIZE; 
		count--;
	}
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
	if(isEmpty())
                throw Underflow();
	else
		theElem = el[front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
	if (isEmpty())
        {
		cout << "[ empty ]." << endl;
		return;
        }
	
	int frontPos = front;

	if (frontPos <= rear)
	{
		while (frontPos <= rear)
		{
			cout << el[frontPos] << endl;
			frontPos++;
		}
	}
	
	else
	{
		while (frontPos <= MAX_SIZE - 1)
		{
			cout << el[frontPos] << endl;
                        frontPos++;
		}
	
		frontPos = 0;
		
		while (frontPos <= rear)
                {
                        cout << el[frontPos] << endl;
                        frontPos++;
                }
	}
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
	string elem;		// a local variable

	if (isEmpty())
                cout << "[ empty ]." << endl;

	if (count == 1)
		return;
	
	if (count >= 1)
	{
		remove(el[front]);
		add(el[front-1]);
	}
}




