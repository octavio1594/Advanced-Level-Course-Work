#ifndef ASSINGMENT1_CPP
#define ASSINGMENT1_CPP

#include "readyQueue.h"
#include <stdlib.h>
#include <sys/time.h>

int main()
{
	bool test2 = true;
	int randomTemp = 0;
	struct timeval tim;	

	cout << "Assingment 1 by Octavio Cea and Reinier Pamintuan, CS 433: \n Press ENTER to begin test 1"<< endl;
	getchar();

	PCB PCBtable[20];
	for (int i = 0; i < 20; i++)
	{
		PCBtable[i] = PCB(i + 1, i + 1, "NEW");
	}

	readyQueue *q1 = new readyQueue();
 
  	q1->insertProcess(PCBtable[4].getID(), PCBtable[4].getPr(), "READY");
  	q1->insertProcess(PCBtable[0].getID(), PCBtable[0].getPr(), "READY");
  	q1->insertProcess(PCBtable[7].getID(), PCBtable[7].getPr(), "READY");
  	q1->insertProcess(PCBtable[10].getID(), PCBtable[10].getPr(), "READY");
  	q1->printQueue();

	q1->removeHighestProc();
  	PCBtable[(q1->lastPCBremoved())-1].setSt("RUNNING");
  	q1->printQueue();

	q1->removeHighestProc();
        PCBtable[(q1->lastPCBremoved())-1].setSt("RUNNING");
        q1->printQueue();

	q1->insertProcess(PCBtable[2].getID(), PCBtable[2].getPr(), "READY");
        q1->insertProcess(PCBtable[6].getID(), PCBtable[6].getPr(), "READY");
        q1->insertProcess(PCBtable[1].getID(), PCBtable[1].getPr(), "READY");
        q1->insertProcess(PCBtable[11].getID(), PCBtable[11].getPr(), "READY");
      	q1->insertProcess(PCBtable[8].getID(), PCBtable[8].getPr(), "READY");

	q1->printQueue();

	for(int i = 0; i < 7; i++)
  	{
    		q1->removeHighestProc();
    		PCBtable[(q1->lastPCBremoved())-1].setSt("RUNNING");
    		q1->printQueue();
  	} 

	cout << "Press Enter to begin Test 2" << endl;
  	getchar();

	for(int i = 0; i < 10; i++)
  	{
    		q1->insertProcess(PCBtable[rand()%19].getID(), 1+rand()%50, "READY");
 	}
  
	gettimeofday(&tim, NULL);  
  	double t1=tim.tv_sec+(tim.tv_usec/1000000.0);

	for(int i=0; i<1000000; i++)
  	{
        	q1->removeHighestProc();
    		PCBtable[(q1->lastPCBremoved())-1].setSt("RUNNING");
    
    		q1->ageQueue();
    
    		while(test2 == true)  // While loop to check
    		{
      			randomTemp = rand()%19;  // Generate a random number
      			bool notFound = true;
      			for(int i = 0; i < q1->sizeOfQueue(); i++)
      			{
        			if(randomTemp == q1->getID(i))  // Check if random index matches ID in queue
        			{
          				notFound = false;  // Return false if there is a match
        			}
      			}
      
			if(notFound)  // If the ID is not in queue, add the process to the queue
      			{
          			q1->insertProcess(PCBtable[randomTemp].getID(), 1+rand()%50, "READY");
          			PCBtable[randomTemp].setSt("READY");
          			test2 = false;  // Break out of the while loop
      			}
    		}
    
		test2 = true;  // Reset the while loop before returning to the main for loop
  	}
	
	gettimeofday(&tim, NULL);  
  	double t2=tim.tv_sec+(tim.tv_usec/1000000.0);  
  	printf("%.6lf seconds elapsed\n", t2-t1); 
	
	return 0;     
}

#endif
