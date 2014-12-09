//============================================================================
// File Prolog
// Name:		Lab_10.cpp
// Purpose:		Practice recursion
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Lab_10
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------


#include "Lab_10.h"

const string PROMPT1 = "This program counts the number of ";
const string PROMPT2 = "'\s in a string of characters.\n Enter a string to count: ";
const string RESULT1 = "The number of ";
const string RESULT2 = "'\s found in the string is: ";
const char CHARACTER = 'a';

// The main method
// Purpose: Entry point to the program
// Parameters: None
// Returns: 0
int main()
{
	TestingRecursion();
	Pause();
	return 0;
}//End main()

void TestingRecursion()
{
	string temp = "";
	int number = 0;
	cin.clear();
	//Prompt the user to enter a value.
	cout << PROMPT1 << CHARACTER << PROMPT2;
	//place the value in string temp
	getline(cin, temp);
	int count = CountChars(temp, CHARACTER);
	//print the result
	cout << RESULT1 << CHARACTER << RESULT2 << count << endl;
}

int CountChars(string str, char chr)
{
	int count = 0;
	if (str == "")
		return count;
	else
	{
		//test to see if the first character matches the test character
		if (str[0] == chr)
		{
			count++;// add a character to the count
		}
		return count + CountChars(str.substr(1), chr);// function calls itself, shortens the string by one
	}
}