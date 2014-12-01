//============================================================================
// File Prolog
// Name:		Proj_10.cpp
// Purpose:		Practice recursion
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_10
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------


#include "Proj_10.h"

const string PROMPT1 =  "This program will find the occurence of one string inside another.\n"
						"Enter the string to be searched: ";
const string PROMPT2 = "Now enter the string to search for: ";
const string RESULT1 = "The index of the substring is = ";
const string RESULT2 = "There is no match.";
const char CHARACTER = 'a';

// The main method
// Purpose: Entry point to the program
// Parameters: None
// Returns: 0
int main()
{
	TestingRecursion();
	system("PAUSE");
	return 0;
}//End main()


void TestingRecursion()
{
	string mainString = "";
	string subString = "";
	int number = 0;
	cin.clear();
	//Prompt the user to enter a value.
	cout << PROMPT1;
	//place the value in string temp
	getline(cin, mainString);
	//Prompt the user to enter a value.
	cout << PROMPT2;
	//place the value in string temp
	getline(cin, subString);
	//count for result
	int count = index_of(mainString, subString);
	//test to see if it was found
	if (count < 0)
	{
		cout << RESULT2 << endl;
	}
	else
	{
		//print the result
		cout << RESULT1 << count << endl;
	}
}


int index_of(string str, string subStr)
{
	// function calls itself, shortens the string by one
	return index_of(str, subStr, 0);
}

int index_of(string str, string subStr, int index)
{
	//test if there are enough remaining characters in the string for a match
	if ((str.length() - index) < subStr.length())
	{
		return -1;
	}
	//test if there is a match
	else if (str.substr(index, subStr.length()) == subStr)
	{
		return index;
	}
	else
	{
		//recursively calls itself, increasing the index count in the next iteration by one.
		return index_of(str, subStr, index + 1);// function calls itself
	}
	return -1;
}