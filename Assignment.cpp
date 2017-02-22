#include<iostream>
using namespace std;

int binarySearch(int[], int ,int ,int);

int main()
{
	int Array[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  	int number;
	int first = 0;
 	int last = 9;		 //  set up initial indices 
   
	while (number >= 0)
	{
		cout << "Enter the number you are looking for: " << endl;
		cin >> number;
	
		int location = binarySearch(Array, number, first, last); 
 
		if (location == -1)
			cout << "The number " << number << " was not found on the list." << endl;
			
		else
			cout << "Found " << number << " in position " << location + 1 << " of the list." << endl;
	}
	return 0;
}

// the function
int binarySearch(int A[], int x, int first, int last) 
{// Compare with the middle entry 
	if (first > last)
		return -1;
	
	int middle = (first+last)/2;  // note that if first == last, there is only one element left
   	
	if (x == A[middle]) 
		return middle;  // found x at location middle

	 if (x < A[middle]) 
		last = middle - 1; // go to first half

	if (x > A[middle]) 
		first = middle + 1; // go to second half
	
	return binarySearch(A, x, first, last); // recursive call
}
