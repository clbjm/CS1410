//============================================================================
// Name        : Utils.h
// Author      : Kevin S. O'Day
// Version     : 1.0
// Project     : Proj_06
// Date        : October 2014
// Date        : 10/27/14 9:59 AM
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
using namespace std;

//Error types
enum ERROR_TYPE{ EOF_E, INT_E, DBL_E, CHR_E, STR_E, INVALID };

// The GetInputInt method
// Purpose: To get a string from the console and convert it to an integer
// Parameters: String containing the prompt message for the user
// Returns: Validated integer
int GetInputInt(string);

// The GetInputInt method
// Purpose: To get a valid integer from the ifstream object
// Parameters: ifstream object reference
// Returns: validated integer
int GetInputInt(ifstream&);

// The GetInputDouble method
// Purpose: To get a valid double from the ifstream object
// Parameters: ifstream object reference
// Returns: validated double
double GetInputDouble(ifstream&);

// The ValidateInt method
// Purpose: Converts a string to an Integer if possible
// Parameters: String reference containing the characters to convert
// Returns: Validated integer
int ValidateInt(string&);

// The ValidateDouble method
// Purpose: Converts a string to a double if possible
// Parameters: String reference containing the characters to convert
// Returns: Validated double
double ValidateDouble(string&);

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
// Purpose: Gets a valid file name from the user
// Parameters: String containing the prompt
// Returns: String containing validated file name
string GetInputFileName(string);

// The ValidateFileName method
// Purpose: Checks to see if a filename is valid
// Parameters: File name to validate
// Returns: True if filename is valid
bool ValidateFileName(string);

#endif /* UTILS_H_ */
