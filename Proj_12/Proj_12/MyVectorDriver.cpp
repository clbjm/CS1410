//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Proj_12
// Purpose: Demonstrate understanding of dynamic storage & memorty management.
// Date: December 2014 
// Date: 12/09/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

// --------------------------------------------------------
// DO NOT CHANGE ANY CODE PAST THIS POINT
//---------------------------------------------------------
#include <iostream>
#include "MyVector.h"     
using namespace std;

// the printV function
// used to test the copy constructor
// parameter: a MyVector object
void PrintV(MyVector);
void Menu();

void main()
{
	Menu();
}
void Menu()
{
	cout << "\nCreating a vector Sam of size 4.";
	MyVector sam(4);

	cout << "\nPush 12 values into the vector.";
	for (int i = 0; i < 12; i++)
		sam.Push_Back(i);

	cout << "\nHere is sam: ";
	cout << sam;
	cout << "\n---------------\n";

	cout << "\nCreating a vector Joe of size 4.";
	MyVector joe(4);
	cout << "\nPush 6 values into the vector.";
	for (int i = 0; i < 6; i++)
		joe.Push_Back(i * 3);

	cout << "\nHere is joe: ";
	cout << joe;
	cout << "\n---------------\n";

	cout << "\nTest the overloaded assignment operator \"joe = sam\": ";
	joe = sam;

	cout << "\nHere is sam: ";
	cout << sam;
	cout << "\n---------------\n";

	cout << "\nHere is joe: ";
	cout << joe;
	cout << "\n---------------\n";

	// pass a copy of sam by value
	PrintV(sam);


	cout << endl;
	system("PAUSE");
}

void PrintV(MyVector v)
{
	cout << "\n--------------------\n";
	cout << "Printing a copy of a vector\n";
	cout << v;
}