#ifndef READYQUEUE_H
#define READYQUEUE_H

#include "pcb.h"

class readyQueue
{
  private:
    PCB *process;    		// Pointer to array
    int numOfProcess;    	// Number of elements in the  heap
    int heapSize;    		// Size of the array
    int lastRemovedProcess;	// ID of last element removed

  public:
     readyQueue();    
    ~readyQueue();    

    // Reheapify after inserting a PCB
    void ReheapifyAfterInsert(int top, int bottom);    
    
    // Reheapify after removing a PBC

    void ReheapifyAfterRemoving(int top, int bottom);    
    
    // Check if the readyQueue is full
    bool checkIfFull(PCB *Process);
    
    // Add the PCB of a process into the ready queue
    bool insertProcess(int id, int priority, string state);
    
    // Remove a PCB from the readyQueue and return the PCB with the highest priority
    PCB *removeHighestProc();
    
    // Return the number of elements in the readyQueue
    int sizeOfQueue();    
    
    // Print the IDs and priorities of elements to the screen
    void printQueue(); 
    
    // Return the id of the last eleemnt removed from readyQueue
    int lastPCBremoved();   
    
    // Decrement priority ID for existing processes in queue
    void ageQueue();  
    
    // Return the ID of an element
    int getID(int id);
};

#endif   
