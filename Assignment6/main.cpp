====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.
//Name: Octavio Cea
//Compiler: g++
//File type: dgraph client file

#include "dgraph.h"

int main()
{
  dgraph g1;  		// 0.Declare table object
  g1.fillTable(); 	// 1.fillTable()
  g1.displayGraph(); 	// 2.displayGraph()
  char name;		//make dummy variable for reading vertex name
  int num;		//creating local variable for users choice
  slist listFound;	//creating local slist object to get adjacency list

  cout << "Enter '1' for Out-degree and '3' for adjacency: " << endl;
  cin >> num;
  while (num ==1)
  {			//user wants out degree
    	try
	{
    		cout << "Enter desired Vertex to find its adjecent verteces." << endl;	//a.the user will specify which vertex     
    		cin >> name;      //b.findOutDegree of the vertex and display the result
    
    		cout << "Out-Degree: " << g1.findOutDegree(name) << endl;
    		cout << "Enter '0' to quit, '1' for Out-degree or '3' for adjacency: " << endl;
    		cin >> num;
	}
    	
	catch(dgraph::BadVertex)
      	{
		cout << "Vertex entered is not in the table." << endl;
      	}  
    	//c.catch exception but do not exit
  }  
			    
  while (num == 3)
  {		//user wants adjacency
   	try
	{ 
		cout << "Enter desired Vertex to find its adjecent verteces." << endl;
    		cin >> name;	     //  a.the user will specify which vertex

    		listFound=g1.findAdjacency(name);	   
    		
		if(listFound.isEmpty())		//check if list is empty
      			cout << "Empty list" << endl;
    		else 
      		{
			listFound.displayAll(); // b.findAdjacency of the vertex and display the result (see Hint)
    			cout << "Enter '0' to quit, '1' for Out-degree or '3' to find adjacency. " << endl;
    			cin >> num;
		}
	}

    	catch(dgraph::BadVertex)
	{  				// c.catch exception but do not exit
      		cout << "Vertex entered is not on the table." << endl;  
    	}
  }
  return 0;
}

