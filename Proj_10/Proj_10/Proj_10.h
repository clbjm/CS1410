//============================================================================
// Project Prolog
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

#include <iostream>
#include <string>
#include <cstdlib>//for POSIX compat
using namespace std;

///--------------------TestingRecursion Driver Function---------------------
/// Purpose: Test a recursive function
/// Returns: None
///---------------------------End-------------------------------
void TestingRecursion(void);

///--------------------index_of Function---------------------
/// Purpose: Looks for a string of characters within another string, acts as a wrapper for a recursive function
/// Parameters: A string to search in and a string to search for
/// Returns: An integer representing the index of the substring or -1 if it's not found
///---------------------------End-------------------------------
int index_of(string s, string t);

///--------------------index_of (recursive) Function---------------------
/// Purpose: Looks for a string of characters within another string
/// Parameters: A string to search in and a string to search for, int for current index.
/// Returns: An integer representing the index of the substring or -1 if it's not found
///---------------------------End-------------------------------
int index_of(string s, string t, int i);
