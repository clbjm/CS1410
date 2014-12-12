//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Lab_15
// Purpose: Templatized vector
// Date: December 2014 
// Date: 12/09/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include <iostream>
#include "MyVector.h"     
using namespace std;

int main()
{
	const char START = 'A';
	const int MAX = 12;

	// create a vector of doubles
	MyVector<char> vectD;

	// push some values into the vector
	for (int i = 0; i < MAX; i++)
	{
		vectD.Push_Back(START + i);
	}

	// remove the last element
	vectD.Pop_Back();

	// add another value
	vectD.Push_Back('Z');

	// test memory management
	MyVector<char> vectD2 = vectD;
	// display the contents
	cout << "\n[";
	for (int i = 0; i < vectD2.Size() - 1; i++)
	{
		cout << vectD2[i] << ", ";
	}

	cout << "..., " << vectD2.Last() << "]\n";

	system("PAUSE");

	return 0;
}
