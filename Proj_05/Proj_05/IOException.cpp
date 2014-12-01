//============================================================================
// Name:		IOException.cpp
// Purpose:		Objects for diagnosing input output exceptions
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_05
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include "IOException.h"

const string IOEXCEPTION_CONSTRUCTOR_MSG = "IOException Constructor";
const string IOEXCEPTION_DEFAULT_DESTRUCTOR_MSG = "IOException Default Destructor";

//--------------------class IOException implementations--------------------------------
IOException::IOException(string& msg, int errorFlag)
{
	_message = msg;
	_errorFlag = errorFlag;
	cout << IOEXCEPTION_CONSTRUCTOR_MSG << endl;
}
IOException::~IOException()
{
	cout << IOEXCEPTION_DEFAULT_DESTRUCTOR_MSG << endl;
}
string IOException::GetMessage(void)
{
	return _message;
}
int IOException::GetErrorFlag(void)
{
	return _errorFlag;
}
