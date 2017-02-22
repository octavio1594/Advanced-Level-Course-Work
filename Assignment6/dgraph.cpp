// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================
//Name: Octavio Cea
//compiler: g++
//file type: dgraph implementation file

#include "dgraph.h"
#include<iostream>
#include<fstream>
using namespace std;

//dgraph constructor
dgraph::dgraph() 
{
  for(int i = 0; i<SIZE; i++) 	//Set all values to 0 and vertex names to "blank"
    {
      Gtable[i].vertexName = ' ';  
      Gtable[i].outDegree = 0; 
      Gtable[i].visit = 0;  
    }
  countUsed = 0;
} 

//dgraph destructor
dgraph::~dgraph()
{
}

// reads from the input file table.txt and fills GTable
void dgraph::fillTable()
{
  ifstream fin ("table.txt");
  char v;
  int od;
  int index = 0;
  
  while (fin >> v)  //while the name can be read, stay in the loop
    {
      cout << "Added " << v << " to the table." << endl;

      Gtable[index].vertexName = v;	//store vertex name in v
      fin >> od;

      Gtable[index].outDegree = od;	//store outdegree in od
      countUsed++;

      for (int i = 1; i <= od; i++)  	//iterate through the loop "od" times for each vertex
	{
	  fin >> v;
	  cout << "Added " << v << " to the table." << endl;
	  (Gtable[index].adjacentOnes).addRear(v);	//adding the adjacent ones to the list
	}
      
	cout << endl;
      	index++;	//increment index for next vertex
    }
  	fin.close();
}

// displays the table in an easy to read format
void dgraph::displayGraph()
{
  for (int i = 0; i < countUsed; i++)	
  {
    cout << "Name: " <<  Gtable[i].vertexName << endl;
    cout << "OutDegree: " << Gtable[i].outDegree << endl;
    cout << "NUmber of Visits: " << Gtable[i].visit << endl;
    cout << "Adjacency list: ";
    (Gtable[i].adjacentOnes).displayAll();	//llist function used to display all adjacent nodes
    cout << endl;
  }

}

// returns the out degree of a given vertex - may throw BadVertex
int dgraph::findOutDegree(char name) 
{
  for(int i = 0; i < countUsed; i++) 
    {
      if(Gtable[i].vertexName== name)		//if the vertex passed matches one in the table
	return Gtable[i].outDegree; 
    }
  cout << name << " was not found." << endl;
  throw BadVertex();		//throw execption

}

// returns the adjacency list of a given vertex - may throw BadVertexx
slist dgraph::findAdjacency(char name)
{

  for(int i = 0; i < countUsed; i++)
    {
      if(Gtable[i].vertexName== name)		//if the vertex passed metches one in the table
        return Gtable[i].adjacentOnes;		//return the vertex's adjancency list 
    }
  cout << name << " not found." << endl;
  throw BadVertex();		//throw exception if the vertex passed is not found
}

//This function enters the given visit number for a given vertex
//to indicate the order in which vertices were visited.
void dgraph::visit(int NumOfVisits, char key)
{
  int vertex;			//creating local variable called vertex
  vertex = key - 65;			//finding a value for the vertex based on ASCII value
  
  Gtable[vertex].visit = NumOfVisits;
}

//This function returns true if a given vertex was already visited
//returns false otherwise.
bool dgraph::isMarked(char key)
{
  int vertex;                   //creating local variable called vertex
  vertex = key - 65;                    //finding a value for the vertex based on ASCII value

  if(Gtable[vertex].visit != 0)	//if vertex has already been visited
  	return true;
  
  else
  	return false;
}
