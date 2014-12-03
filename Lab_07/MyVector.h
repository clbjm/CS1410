//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Proj_07
// Purpose: Demonstrate understanding of Vectors, Arrays, & pointers.
// Date: October 2014 
// Date: 10/28/14 9:59 AM
//============================================================================

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;


class MyVector
{
	private:
		//pointer of type int
		int* _pData = NULL;
		//the current number of elements in the array
		int _size;
		//the total current capacity of the array
		int _capacity;
	
	public:
	
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		MyVector();
	
		///----------------- Constructor -----------------------
		/// Purpose: To construct a MyVector object, setting its capacity to provided value
		/// Parameters: integer for capacity
		///-------------------------- End ------------------------------
		MyVector(int);
	
		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~MyVector();
	
		///--------------------size Function---------------------
		/// Purpose: get the current number of elements in the array
		/// Parameters: none
		/// Returns: integer current number of elements in the array
		///---------------------------End-------------------------------
		int size();
	
		///--------------------capacity Function---------------------
		/// Purpose: get the total capacity of the array
		/// Parameters: none
		/// Returns: integer total capacity of the array
		///---------------------------End-------------------------------
		int capacity();
	
		///--------------------clear Function---------------------
		/// Purpose: Clar all the elements in the array, reset size and capacity to default
		/// Parameters: none
		/// Returns: none
		///---------------------------End-------------------------------
		void clear();
	
		///--------------------push_back Function---------------------
		/// Purpose: add the integer value to the end of the array, grow as needed
		/// Parameters: integer to add to the array
		/// Returns: none
		///---------------------------End-------------------------------
		void push_back(int);
	
		///--------------------at Function-------------------------------------------------
		/// Purpose: Returns the value of the element at given index
		/// Parameters: integer for index
		/// Returns: integer at given index, throws exception if index is greater than size
		///---------------------------End--------------------------------------------------
		int at(int);
};
