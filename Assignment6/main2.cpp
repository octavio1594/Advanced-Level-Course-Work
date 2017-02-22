#include "dgraph.h"
#include "stack.h"
using namespace std;

int main()
{
  slist adjacent;
  dgraph graph01;
  int count = 1;
  char temporal;
  stack stack01;
  
  graph01.fillTable();
  graph01.displayGraph();
  graph01.visit(count,'A');
  count++;
  
  adjacent = graph01.findAdjacency('A');
  while(!adjacent.isEmpty())			//While the adjacentcy list is not empty
  {
  	adjacent.deleteRear(temporal);		//Delete rear and store it into temporal01.
    	stack01.push(temporal);			//Push the variable stored in temporal01 into the stack
  }
  
  cout << "Initial stack" << endl;
  stack01.displayAll();
  
  while(!stack01.isEmpty())		//While the stack is not empty
  {
 	 stack01.pop(temporal);		//pop from stack and store into temporal01
    	 if(!graph01.isMarked(temporal))	//if a popped item is not marked
         {
		graph01.visit(count,temporal);
      		count++;
      		
		cout << "Visited: " << temporal << endl;
      
		adjacent = graph01.findAdjacency(temporal);
      		while(!adjacent.isEmpty())		//While the adjacentcy list is not empty
        	{
			adjacent.deleteRear(temporal);
        		stack01.push(temporal);
      		}
      
		stack01.displayAll();
    	}
  }
    
  graph01.displayGraph();
}

