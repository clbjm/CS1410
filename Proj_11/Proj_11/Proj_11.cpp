//============================================================================
// File Prolog
// Name:		Proj_11.cpp
// Purpose:		Practice overloading operators
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_11
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include "Proj_11.h"
#include <iostream>
using namespace std;

int main()
{
	// Create complex numbers to do arithmentic with
	ComplexNumber cm1(1, 2);
	ComplexNumber cm2(1, -2);

	// test addition operator
	ComplexNumber cm3 = cm1 + cm2;
	cout << cm3 << endl;

	// test subtraction operator
	ComplexNumber cm4 = cm1 - cm2;
	cout << cm4 << endl;

	// test multiplication operator
	ComplexNumber cm5 = cm1 * cm2;
	cout << cm5 << endl;

	// test division operator
	ComplexNumber cm6 = cm1 / cm2;
	cout << cm6 << endl;

	// test assignment operator
	cm6 = cm5;
	cout << cm6 << endl;

	// test comparison operator
	if (cm1 == cm2)
		cout << "\nThey are equal.\n";
	else
		cout << "\nThey are not equal.";

	ComplexNumber cm8(1, 2);
	if (cm1 == cm8)
		cout << "\nThey are equal.\n";
	else
		cout << "\nThey are not equal.";

	system("PAUSE");
	return 0;
}