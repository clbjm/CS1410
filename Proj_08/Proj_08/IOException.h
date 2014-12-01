//============================================================================
// Name:		IOException.h
// Purpose:		Objects for diagnosing input output exceptions
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_08
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#ifndef IOEXCEPTION_H_
#define IOEXCEPTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>//for POSIX compatibility

using namespace std;

enum ERROR_TYPE{ EOF_E, INT_E, DBL_E, CHR_E, STR_E, INVALID };

///------------------- IOException class------------------
///  Purpose : To handle exceptions thrown from Utils
///-------------------End---------------------------------
class IOException
{
	//Member Data
private:
	string _message;
	int _errorFlag;
	//Member functions
public:

	///----------------- Constructor -----------------------
	/// Purpose: To create a IOException object given its parameters
	/// Parameters: String reference containing an error message
	///				integer representing error type
	///-------------------------- End ------------------------------
	IOException(string&, int);

	///----------------- Default Destructor -----------------------
	/// Purpose: To initialize all data members to their default
	/// Parameters: None
	///-------------------------- End ------------------------------
	~IOException();

	///-------------------- Getter Function -----------------------
	/// Purpose: To return the exception message
	/// Returns: String containing error message
	///-------------------------- End ------------------------------
	string GetMessage();

	///-------------------- Getter Function -----------------------
	/// Purpose: To return the exception error flag
	/// Returns: Integer representing an error flag
	///-------------------------- End ------------------------------
	int GetErrorFlag();

};//End class IOException

#endif /* IOEXCEPTION_H_ */
