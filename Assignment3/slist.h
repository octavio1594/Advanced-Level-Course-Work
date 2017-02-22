#include"llist.h"

class slist : public llist// HW3P2  Instruction: Inherit everything publicly from llist
{
	public:
		slist();   // constructor which is the same as the llist one
		
		// search through the list to see if any node contains the key.
		// If so, return its position (>=1). Otherwise, return 0.
		int search(el_t key);
		
		// go to the Ith node (if I is between 1 and Count) and
                // replace the element there with the new element.
                // If I was an illegal value, throw OutOfRange
		void replace(el_t element,  int i);

		//Function to overload the = operator
		slist& operator=(const slist& otherList);

		//Copy constructor that takes a list as a parameter and makes 
		//an exact copy of it
		slist(const slist& OriginalList);
};		

