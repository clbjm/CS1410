//============================================================================
// File Prolog
// File:		Proj_06.cpp
// Purpose:		Demonstrate the use of pointers
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_06
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================
//============================================================================

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include <vector>
#include "Proj_06.h"

const int BUFF_LENGTH = 500;
const int SENTENCE_LENGTH = 30;
const char ZERO = '0';
const string PROMPT = "Enter a sentence or 0";

// The main method
// Purpose: Entry point to the program
// Parameters: None
// Returns: None
void main()
{
	TestPointers();
	system("PAUSE");
	return;
}//End main()


void TestPointers(void)
{
	//dynamically allocate memory for the buffer
	char* buffer = new char[BUFF_LENGTH]{NULL};
	//create a vector to store pointers
	vector <char*> chrPtrVctr;
	//create a pointer to increment without losing the buffer pointer
	char* myArray = buffer;
	//number of sentences
	int sentenceCount = 0;
	//boolean for exit of loop
	bool exitRequested = false;
	do
	{
		//prompt
		cout << PROMPT << endl;
		//store the sentence in the char Array
		cin.getline(myArray, SENTENCE_LENGTH);
		//test to see if exit was requested
		if (myArray[0] == '0' && strlen(myArray) == 1)
		{
			exitRequested = true;
		}
		else
		{
			//only if the user didn't enter '0'
			//lengthen the vector
			//store the pointer to the sentence in the buffer in a vector
			chrPtrVctr.push_back(myArray);
			//add one to the number of sentences
			sentenceCount++;
			//increment myArray by the length of the string
			myArray += strlen(myArray) + 1;
		}
		
	} 
	while (!exitRequested);
	
	//give some space
	cout << endl << endl;

	//print backwards
	for (sentenceCount -= 1; sentenceCount >= 0; sentenceCount--)
	{
		char* sentPtr = chrPtrVctr[sentenceCount];
		string str(sentPtr);
		cout << str << endl;
	}
}
