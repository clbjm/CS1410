//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Lab_13
// Purpose: Demonstrate understanding of function & class templates.
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
#include "Pair.h"
using namespace std;


int main()
{
	Pair<char> letters('a', 'd');
	cout << "\nThe first letter is: " << letters.getFirst();
	cout << "\nThe second letter is: " << letters.getSecond();

	cout << endl;
	system("Pause");
	return 0;
}