
// ====================================================
//HW#: HW3P1 llist
//Your name: Octavio Cea
//Complier:  g++
//File type: llist implementation file
//=====================================================

#include"llist.h" 

//Constructor initializes Front and Rear to be NULL and Count = 0.
llist::llist()
{
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
  
//Destructor, while the list is not empty, it calls deleteFront repeatedly 
//to delete all nodes.
llist::~llist()
{
	cout << "(Now calling the llist desctructor.)" << endl;
	
	while(Front != NULL)
	{
		el_t OldNum;
		deleteFront(OldNum);
	}

}

//return true if Front and Rear are both pointing to NULL and Count is 0.
bool llist::isEmpty()
{
	if ((Rear == NULL)&&(Front == NULL))
	{	
		if (Count == 0)
			return true;
		
		else
			return false;
	}
	
	else
		return false;
}

//if the list is empty, function displays [ empty ] ). Otherwise function 
//displays each element of the list horizontally starting from Front in [ ].
void llist::displayAll()
{
	if (isEmpty() == true)
		cout << "[ empty ]." << endl;
	
	else
	{	
		Node* P = Front;
		while(P != NULL)
		{
			cout << "[" << P->Elem << "]" << "  ";
			P = P->Next;
		}

		cout << endl;
	}
}
 
//if this is going to be the very first node, the function
//creates a new node and it makes Front and Rear point to it. It places 
//the  NewNum and updates Count. Otherwise it adds a new node at the rear
//and puts NewNum in the Elem field of this new node. Count is updated.
void llist::addRear(el_t NewNum)
{
	if (isEmpty() == true)
		addFront(NewNum);

        else
        {
		Rear->Next = new Node;
    		Rear = Rear->Next;
    		Rear->Elem = NewNum;
    		Rear->Next = NULL;
		Count++;
	}
}



//if this is going to be the very first node, the function
//creates a new node and it makes Front and Rear point to it. 
//It places the NewNum and it updates the count. Otherwise it
//adds a new node to the front of the list and it updates the count.
void llist::addFront(el_t NewNum)
{
	if (isEmpty() == true)
	{
		Rear = Front = new Node;
		Front->Elem = NewNum;
		Count++;
	}

	else
	{
		Node *x;
  		x = new Node;
  		x->Next = Front;
  		Front = x;
  		Front->Elem = NewNum;
		Count++;
	}
}

//if the List is empty, the function throws Underflow, if currently only one Node,
//the function gives back the front node element through OldNum (pass by reference) 
//and it makes sure both Front and Rear become NULL. Count is updated. If the list
//has nodes the function gives back the front node element through OldNum 
//(pass by reference) and it removes the front node. Count is updated.
void llist::deleteFront(el_t& OldNum)
{
	if (isEmpty() == true)
		throw Underflow();

	else if (Front->Next == NULL)
	{
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
		 
	}

	else
	{
		OldNum = Front->Elem;
  		Node *Second;
  		Second = Front->Next;
  		delete Front;
  		Front = Second;
		Count--;
	}
}

//if the List is empty, the function throws Underflow, if currently only one Node,
//the function gives back the rear node element through OldNum (pass by reference)
//and it makes sure both Front and Rear become NULL. Count is updated. If the list
//has nodes the function gives back the rear node element through OldNum
//(pass by reference) and it removes the rear node. Count is updated.
void llist::deleteRear(el_t& OldNum)
{
	if (isEmpty() == true)
		deleteFront(OldNum);

	else if (Front->Next == NULL)
        {
		deleteFront(OldNum);
	}

	else
	{
		OldNum = Rear->Elem;
  		Node *P;
		P = Front;
  		while(P->Next->Next != NULL)
                {
                	P = P->Next;
                }
  		delete Rear;
  		Rear = P;
		Rear->Next = NULL;
		Count--;
	}
}

//If I is an illegal value (i.e. > Count or < 1) the function throws OutOfRange.
//otherwise this function should simply call deleteFront when I is 1 or deleteRear 
//when I is Count. If not the function deletes the Ith node (I starts out at 1). 
//Count is updated.
void llist::deleteIth(int I, el_t& OldNum)
{
	if ((I > Count)||(I < 1))
		throw OutOfRange();

	else if (I == 1)
		deleteFront(OldNum);

	else if (I == Count)
		deleteRear(OldNum);

	else
	{
		Node* P = Front;
		for (int K = 1; K <= I-2; K++)
		{ 
			P = P->Next; 
		}
	
		Node* Q = P->Next;
		P->Next = Q->Next;
		OldNum = Q->Elem; 
		delete Q;
		Count--;
	}
}	

//If I is an illegal value (i.e. > Count+1 or < 1) the function throws OutOfRange.
//otherwise this function should simply call addFront when I is 1 or addRear
//when I is Count+1. If not the function adds a node before the Ith node 
//(I starts out at 1). Count is updated.
void llist::addbeforeIth(int I, el_t newNum)
{
	if ((I > Count+1)||(I < 1))
                throw OutOfRange();

        else if (I == 1)
                addFront(newNum);

        else if (I == Count+1)
                addRear(newNum);

        else
	{
		Node* P = Front;
        	for (int K = 1; K <= I-2; K++)
        	{
               	 	P = P->Next;
        	}

        	Node* Q = P->Next;
        	P->Next = new Node;
		P->Next->Next = Q;
		P->Next->Elem = newNum;
		Count++;
	}
}
