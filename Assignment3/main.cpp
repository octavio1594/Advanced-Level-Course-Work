
//=========================================================
//HW#: HW3P2 slist
//Your name: Octavio Cea
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: this program simply tests a a derived class called slist
int main()
{ 
  slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number

try
  {
    //  1)add to front once (element 4)
    cout << counter << endl; counter++;
    L.addFront(4);
    cout << "Some elements were added to the list" << endl;
    //  2)add to rear 3 times (elements 6,7,8)
    cout << counter << endl; counter++;
    L.addRear(6);
    L.addRear(7);
    L.addRear(8);
    cout << "Some elements were added to the list" << endl;
    //  3)displayAll    - 4 6 7 8
    cout << counter << endl; counter++;
    cout << "The lists contains:  ";
    L.displayAll();
    //  4)search for 6, report the result  - found in pos 2
    cout << counter << endl; counter++;
    foundPos = L.search(6);
    if (foundPos == 0)
    	cout << "The element was not found" << endl;
    else
    	cout << "The element was found in position: #" << foundPos << endl;
    //  5)replace the 6 with 0 using the search result
    cout << counter << endl; counter++;
    L.replace(0, foundPos);
    cout << "The element in the " << foundPos << "th position was replaced" << endl;
    //  6)search for 8 and report the result . found in pos 4
    cout << counter << endl; counter++;
    foundPos = L.search(8);
    if (foundPos == 0)
        cout << "The element was not found" << endl;
    else
	cout << "The element was found in position: #" << foundPos << endl;
    //  7)replace the 8 with 2 using the search result
    cout << counter << endl; counter++;
    L.replace(2, foundPos);
    cout << "The element in the " << foundPos << "th position was replaced" << endl;
    //  8)displayAll                       - 4 0 7 2
    cout << counter << endl; counter++;
    cout << "The lists contains:  ";
    L.displayAll();
    //  9)search for 5 and report the result   - not found
    cout << counter << endl; counter++;
    foundPos = L.search(5);
    if (foundPos == 0)
        cout << "The element was not found" << endl;
    else
	cout << "The element was found in position: #" << foundPos << endl;
    // 10) replace postion 7 with 10
    cout << counter << endl; counter++;
    L.replace(10, 7);
    cout << "The element in the " << foundPos << "th position was replaced" << endl;
    }//end of try
    catch(llist::OutOfRange)
    { 
	cerr << "ERROR: Bad position was given" << endl;}
    }	
    //end of program
