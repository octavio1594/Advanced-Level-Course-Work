#include <iostream>
#include <vector>
using namespace std;
//This function takes two sorted vectors by reference and combines them into a single sorted vector
//which is then returned to the main program
vector<int> combine(vector<int> &A, vector<int> &B)
{
	vector<int> C;			//create vector to place the sorted values

	while (A.size() > 0)			//execute loop until vector A is empty
	{
		if (A[0] < B[0])		//compare first value of each vector
		{
			C.push_back(A[0]);	//push value into vector C if A[0] is less than B[0]
			A.erase(A.begin());	//delete first value of A and shift indeces of the remaining values
			cout << "Comparison" << endl;	
		}
		else
		{
			C.push_back(B[0]);	//push value into vector C if B[0] is less than A[0]
			B.erase(B.begin());	//delete first value of B and shift indeces of the remaining values
			cout << "Comparison" << endl;
		}
	}

	while (B.size() > 0)		//execute loop until vector B is empty
	{
		C.push_back(B[0]);	//push first value of B into C
                B.erase(B.begin());	//delete first value of B and shift indeces of the remaining values
	}
	return C;	
}

int main()
{
	vector<int> L1;		//create vectors for all three lists
	vector<int> L2;
	vector<int> L3;
	int number;
	int listSize;

	cout << "Enter the desired size for both lists: ";
	cin >> listSize;
	
	cout << "Type the integers for list 1 in acending order." << endl;
	for (int i = 0; i < listSize; i++)	//loop ends when the number of inputs is equal to the list size
	{
		cout << "Enter an integer: ";
		cin >> number;

		L1.push_back(number);		//fill the vector L1 with the values entered by the user
	}

	cout << "Type the integers for list 2 in acending order." << endl;
	for (int i = 0; i < listSize; i++)	//loop ends when the number of inputs is equal to the list size
        {
                cout << "Enter an integer: ";
                cin >> number;

                L2.push_back(number);		//fill the vector L2 with the values entered by the user
        }

	L3 = combine(L1, L2);		//calling the fuction combine
	
	cout << "Lists 1 and 2 combined in order: ";
	for (int i = 0; i < L3.size(); i++)	//loop ends when i is equal or greater than the size of vector L3
	{
		cout << L3[i] << " ";
	}

	cout << endl;
}
