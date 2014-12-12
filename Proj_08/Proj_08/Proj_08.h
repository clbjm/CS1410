//============================================================================
// Project Prolog
// Name:		Proj_08.h
// Purpose:		Test Employee Inheritance
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


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>//for POSIX compat

#include "Utils.h"
#include "FileIO.h"
#include "Employee.h"

///--------------------TestEmployee Driver Function---------------------
/// Purpose: test the employee class & methods
/// Returns: void
///---------------------------End---------------------------------------
void TestEmployee(void);

///--------------------MenuOne function---------------------------------
/// Purpose: Open or create database files
/// Returns void
///---------------------------End---------------------------------------
void MenuOne(FileIO*);

///--------------------MenuTwo function---------------------------------
/// Purpose: Saves or Restores Database file
/// Returns void
///---------------------------End---------------------------------------
void MenuTwo(FileIO*);

///--------------------MenuThree function---------------------------------
/// Purpose: Moves the file pointer in the open database
/// Returns void
///---------------------------End---------------------------------------
void MenuThree(FileIO*);

///--------------------MenuFour function---------------------------------
/// Purpose: Prints paychecks
/// Returns void
///---------------------------End---------------------------------------
void MenuFour(FileIO*, vector<Employee*>&);
