#ifndef READYQUEUE_CPP
#define READYQUEUE_CPP

#include <iostream>
#include "readyQueue.h"
using namespace std;

//Constructor
readyQueue::readyQueue()
{
  process = new PCB[20];  
  numOfProcess = 0;   
  heapSize = 20;    
  lastRemovedProcess = 0; 
}

// Destructor
readyQueue::~readyQueue()
{
  delete[] process;
}

// Reheapify after inserting a PCB
void readyQueue::ReheapifyAfterInsert(int top, int bottom)
{
  int primary;
  PCB temporary;

  if(bottom > top)	//if the heap is not empty
  {
    primary = (bottom -1) / 2;	//*
    if(process[primary].getPr() > process[bottom].getPr())
    {
       // Swap processes
       temporary = process[primary];
       process[primary] = process[bottom];
       process[bottom] = temporary;
       
       // Reheap using recursion where top and bottom are now new values
       ReheapifyAfterInsert(top, bottom);
    }
  }
} 

// Reheapify after removing a PBC
void readyQueue::ReheapifyAfterRemoving(int top, int bottom)
{
  int root;
  int right;
  int left;
  PCB temporary;

  left = top * 2 + 1;    // Geting the index of top's left and right nodes (*)
  right = top * 2 + 2;   

  //Heapifying
  if(left <= bottom)               
  {
    if(left == bottom)    // If root has no right node then 
    {
      root = left;     // left must be root
    }
    else
    {     
      // Get lowest node in readyQueue to become root
      if(process[left].getPr() > process[right].getPr())
        root = right;
      else
        root = left;
    }
    if(process[top].getPr() >= process[root].getPr())
    {
      //Swap processes
      temporary = process[top];
      process[top] = process[root];
      process[root] = temporary;
      //Reheapfy using updated values
      ReheapifyAfterRemoving(root, bottom);
    }
  }
}

// Check if ReadyQueue is full
bool readyQueue::checkIfFull(PCB *Process)  
{
   if(numOfProcess < heapSize)
   {
	process[numOfProcess] = *Process; // Copy item into array
     	ReheapifyAfterInsert(0, numOfProcess);
      	numOfProcess++;
      
	return true; // Queue is not full
   }
   cout << "Cannot add Process " << Process->getID() << ". The queue is full." << endl;
   return false;	// Queue is full
}   

// Add process to queue
bool readyQueue::insertProcess(int id, int priority, string state)
{
   bool testProcess;
   PCB *temporary = new PCB(id, priority, "READY");
   testProcess = checkIfFull(temporary);
   delete temporary; 
   return testProcess;
}

// Remove highest priority process from queue
PCB *readyQueue::removeHighestProc()
{
  if(numOfProcess == 0)
  {
    cout << "Unable to remove. The queue is empty." << endl;
    return NULL;
  }
  else
  {
    PCB *temporary = new PCB(process[0].getID(), process[0].getPr(), process[0].getSt());
    numOfProcess--;
    lastRemovedProcess = process[0].getID();
    // Copy last item into root
    process[0] = process[numOfProcess];
    // Reheap the tree
    ReheapifyAfterRemoving(0, numOfProcess - 1);

    return temporary;
  }
}

// Return the number of elements in the queue
int readyQueue::sizeOfQueue()
{
  return numOfProcess;
}
          
// Display the IDs and priorities of processes in the queue
void readyQueue::printQueue()
{
  cout << "\nPCBs In Queue \n---------------------------------"
  << "\nID:  " << "\tPriority: " << "\tState: " << endl;
  for(int i = 0; i < numOfProcess; i++)
  {
    cout << process[i].getID() << "\t" << process[i].getPr() 
    << "\t\t" << process[i].getSt() << endl;
  }
}

// Return the last process removed from queue
int readyQueue::lastPCBremoved()
{
  return lastRemovedProcess;
}

// Decrement priority ID for existing processes in queue
void readyQueue::ageQueue()
{
  int temporary = 0;
  for(int i = 0; i < numOfProcess; i++)
  {
    temporary = process[i].getPr();
    if(temporary > 1)  // Priority ID should be at least 1
    {
      process[i].setPr(temporary - 1);
    }
  }
}

// Return process ID
int readyQueue::getID(int id)
{
  return process[id].getID();
}
#endif
