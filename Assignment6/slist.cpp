#include"slist.h"

//Constructor initializes Front and Rear to be NULL and Count = 0.
slist::slist()
{
        Front = NULL;
        Rear = NULL;
        Count = 0;
}

// search through the list to see if any node contains the key.
// If so, return its position (>=1). Otherwise, return 0.
int slist::search(el_t key)
{
	if (isEmpty() == true)
                return 0;

        else
	{
		Node *P;
                P = Front;
		int position = 1;
		while(P != NULL)
                {
                        if (P->Elem == key)
				return position;
			else
				position++;
				P = P->Next;
                }
	
		return 0;
	}
}
	
// go to the Ith node (if I is between 1 and Count) and
// replace the element there with the new element.
// If I was an illegal value, throw OutOfRange
void slist::replace(el_t element,  int i)
{
	if ((i > Count+1)||(i < 1))
                throw OutOfRange();

	addbeforeIth(i, element);
	deleteIth((i+1), element);
}

slist& slist::operator=(const slist& OtherList)
  {
     // First making sure this-> and OtherOne are not the same object.
     // To do this, compare the pointers to the objects .
     if (&OtherList != this)
     {
        el_t item;
        
	while (! this-> isEmpty() ) //empting this->
        {
        	this-> deleteRear(item);
    	}
        
	Node* P;  
        P = OtherList.Front;
        
	while (P != NULL)
        {
        	this->addRear(P->Elem);    
        	P = P->Next;               
        }
      }
     
	return *this;    // return the list.
}

slist::slist(const slist& OriginalList)
{
		 
	Node* P; 
	P = OriginalList.Front;  //creating this-> list by allocating new cells
	while (P != NULL)
	{
		 this->addRear(P->Elem);
		 P = P->Next;
	}
}


