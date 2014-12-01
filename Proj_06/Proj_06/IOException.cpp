//============================================================================
// Name        : IOException.cpp
// Author      : Kevin S. O'Day
// Version     : 1.0
// Project	   : Proj_05
// Purpose	   : Exception class for Input/Output errors
// Date        : October 2014
// Date        : 10/27/14 9:59 AM
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
IOException::IOException(const string& msg, int mode)
{
	_message = msg;
	_mode = mode;
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
int IOException::GetMode(void)
{
	return _mode;
}
