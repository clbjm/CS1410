//============================================================================
// Name:		FileIO.h
// Purpose:		Class for Input/Output operations
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_09
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#ifndef FILEIO_H_
#define FILEIO_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>//string stream
#include <vector>
#include <stdlib.h>//for POSIX compatibility

#include "Utils.h"
#include "FileException.h"
#include "IOException.h"
#include "Employee.h"

using namespace std;

class FileIO {

	private:
		fstream _ioFile;

	public:
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default
		/// Parameters: None
		///-------------------------- End ------------------------------
		FileIO();
		///----------------------- OpenDB() ----------------------
		/// Purpose: Opens the file on the stream object passed to
		///          and tests to insure the open is successful.
		/// Parameters: string -name of the file to be opened
		///             int 0 ate mode, 1 trunc mode
		///---------------------- end ------------------------------
		bool OpenDB(string , int );
		///--------------------ReadDB Function---------------------
		/// Purpose: read data from a persistence file
		/// Parameters: Reference to a pointer (to be changed)
		/// Returns:
		///---------------------------End-------------------------------
		bool ReadDB(Employee*&);
		///--------------------WriteDB Function---------------------
		/// Purpose: write Data to a persistence File
		/// Returns:
		///---------------------------End-------------------------------
		bool WriteDB(Employee*);
		///--------------------SeekDB Function---------------------
		/// Purpose: Move the file pointer 
		/// Parameters: int signifying beginning or end
		/// Returns:
		///---------------------------End-------------------------------
		bool SeekDB(int);
		///--------------------CloseDB Function---------------------
		/// Purpose: closes the file
		/// Returns:
		///---------------------------End-------------------------------
		bool CloseDB();
		///------------------- CheckErrors() ---------------------
		/// Purpose: Determines if the file operation was successful
		///          by testing the Error Flag Word if not displays
		///          the state of eof, fail and bad bits and then
		///          it clears the Error Flag Word.
		/// Parameters: string - message about the fstream operation
		/// Returns:  Error Flag true was good false not good.
		///---------------------- end ------------------------------
		bool CheckErrors(string&);
};

#endif /* FILEIO_H_ */
