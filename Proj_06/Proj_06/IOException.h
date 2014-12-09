//============================================================================
// Name         : IOException.h
// Author       : Kevin S. O'Day
// Version      : 1.0
// Project	: Proj_06
// Purpose	: Exception class for Input/Output errors
// Date         : October 2014
// Date         : 10/27/14 9:59 AM
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
#include <sstream>//string stream
#include <vector>
#include <stdlib.h>//for POSIX compatibility
using namespace std;

// enum for modes
enum MODE{ DEFAULT, EXIT };

// The IOException class
// Purpose : To handle exceptions thrown from KSO_Utils
class IOException
{
	//Member Data
	private:
		string _message;
		int _mode;
	//Member functions
	public:
		///----------------- Constructor -----------------------
		/// Purpose: To create an IOExeption object given its parameters
		/// Parameters: string reference containing error message,
		///				integer containing error mode
		///-------------------------- End ------------------------------
		IOException(const string&, int);
		///----------------- Destructor -----------------------
		/// Purpose: Handles cleanup tasks before object destruction, prints destruction message.
		/// Parameters: none
		///-------------------------- End ------------------------------
		~IOException();
		///-------------------- Getter Function -----------------------
		// The GetMessage method
		// Purpose: To get the error message
		// Parameters: none
		// Returns: string containing error message
		///-------------------------- End ------------------------------
		string GetMessage();
		///-------------------- Getter Function -----------------------
		// The GetMode method
		// Purpose: To get the error mode message
		// Parameters: none
		// Returns: integer containing error mode
		///-------------------------- End ------------------------------
		int GetMode();
};//End class IOException


