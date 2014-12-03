//============================================================================
// Project Prolog
// Name:		    Lab_10.h
// Purpose:		  Practice recursion
// Version:		  1.0
// Author:		  Kevin S. O'Day
// Course:		  CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		  Lab_10
// Date:		    November 2014
// Date:		    11/26/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>//for POSIX compat
using namespace std;

#include "Utils.h"

///--------------------TestingRecursion Driver Function---------------------
/// Purpose: Test a recursive function
/// Returns: None
///---------------------------End-------------------------------
void TestingRecursion(void);

///--------------------CountChars Function---------------------
/// Purpose: Recursive function for counting a character in a string
/// Parameters: a string to test and a character to test for
/// Returns: integer count
///---------------------------End-------------------------------
int CountChars(string, char);
