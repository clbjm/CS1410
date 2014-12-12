//============================================================================
// Name:		Utils.h
// Purpose:		Utilities for validating input
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

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>//string stream
#include <vector>
#include <stdlib.h>//for POSIX compatibility

#include "FileException.h"
#include "IOException.h"

using namespace std;

// The GetInputInt method
// Purpose: To get a string from the console and convert it to an integer
// Parameters: String containing the prompt message for the user
// Returns: Validated integer
int GetInputInt(string);

// The StringToValidInt method
// Purpose: Converts a string to an integer if it is valid
// Parameters: String reference containing the characters to be converted
// Returns: Validated integer
int StringToValidInt(string&);

// The StringToValidDouble method
// Purpose: To get a string from the console and convert it to a double
// Parameters: String reference containing the characters to be converted
// Returns: Validated double
double StringToValidDouble(string&);

// The StreamToValidInt method
// Purpose: Converts a string to an integer if it is valid
// Parameters: String reference containing the characters to be converted
// Returns: Validated integer
int StreamToValidInt(ifstream&);

// The GetValidInputDouble method
// Purpose: To get a valid double from the ifstream object
// Parameters: ifstream object reference
// Returns: validated double
double StreamToValidDouble(ifstream&);

// The IsDigit method
// Purpose: To verify that a given character represents a valid digit
// Parameters: a character to test
// Returns: boolean false if the character is not a valid digit
bool IsDigit(char);

// The SplitString method
// Purpose: Splits a string into a bunch of substrings delimited by character, stores in vector reference
// Parameters: String reference, delimiting character, reference to vector
// Returns: none
void SplitString(string&, char, vector <string>&);

// The GetInputFileName method
// Purpose: To get a string from the console and make sure it is a valid file name
// Parameters: String containing the prompt message for the user
// Returns: Validated string for file name
string GetInputFileName(string);


// The GetValidReadFile method
// Purpose: Test that the file opened without error
// Parameters: None
// Returns: ifstream object that opened correctly
ifstream GetValidReadFile();

// The GetValidWriteFile method
// Purpose: Test that the file opened without error
// Parameters: None
// Returns: ofstream object that opened correctly
ofstream GetValidWriteFile();

// The BadFileChoice method
// Purpose: Let the user choose if they want to re-enter a file name or exit the program
// Parameters: None
// Returns: None
void BadFileNameChoice();

// The Pause method
// Purpose: to pause the console, waiting for any character before resuming
//		Unix portable
// Returns: none
void Pause(void);


#endif /* UTILS_H_ */
