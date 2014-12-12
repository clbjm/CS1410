//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Proj_07
// Purpose: Demonstrate understanding of Vectors, Arrays, & pointers.
// Date: October 2014 
// Date: 10/28/14 9:59 AM
//============================================================================

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include "MyVectorDriver.h"


const int VAL1 = 21;
const int VAL2 = 31;
const int VAL3 = 41;
const int MAX = 12;

int main()
{
	// Create a default MyVector on the Stack (cap = 2)
	MyVector sam;

	// push some data into sam
	cout << "\nPushing three values into sam";
	sam.Push_Back(VAL1);
	sam.Push_Back(VAL2);
	sam.Push_Back(VAL3);

	cout << "\nThe values in sam are: ";

	// test for out of bounds condition here
	for (int i = 0; i < sam.Size() + 1; i++)
	{
		try
		{
			cout << sam.ValueAt(i) << " ";
		}
		catch (int badIndex)
		{
			cout << "\nOut of bounds at index " << badIndex << endl;
		}
	}
	cout << "\n--------------\n";

	// clear sam and display its size and capacity
	sam.Clear();
	cout << "\nsam has been cleared.";
	cout << "\nSam's size is now " << sam.Size();
	cout << "\nSam's capacity is now " << sam.Capacity() << endl;
	cout << "---------------\n";

	// Push 12 values into the vector - it should grow
	cout << "\nPush 12 values into sam.";
	for (int i = 0; i < MAX; i++)
		sam.Push_Back(i);

	cout << "\nSam's size is now " << sam.Size();
	cout << "\nSam's capcacity is now " << sam.Capacity() << endl;
	cout << "---------------\n";

	cout << "\nTest to see if contents are correct...";
	// display the values in the vector
	for (int i = 0; i < sam.Size(); i++)
	{
		cout << sam.ValueAt(i) << " ";
	}
	cout << "\n--------------\n";

	cout << "\n\nTest Complete...";

	cout << endl;
	system("PAUSE");
	return 0;
}
