//============================================================================
// Name:		FileException.cpp
// Purpose:		Objects for diagnosing File exceptions
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

#include "FileException.h"

const string FILEEXCEPTION_CONSTRUCTOR_MSG = "FileException Constructor";
const string FILEEXCEPTION_DEFAULT_DESTRUCTOR_MSG = "FileException Default Destructor";

//--------------------class FileException implementations--------------------------------
FileException::FileException(string& msg, int errorFlag)
{
	_message = msg;
	_errorFlag = errorFlag;
	cout << FILEEXCEPTION_CONSTRUCTOR_MSG << endl;
}
FileException::~FileException()
{
	cout << FILEEXCEPTION_DEFAULT_DESTRUCTOR_MSG << endl;
}
string FileException::GetMessage(void)
{
	return _message;
}
int FileException::GetErrorFlag(void)
{
	return _errorFlag;
}
