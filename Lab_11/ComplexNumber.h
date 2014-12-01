//============================================================================
// File Prolog
// Name:		ComplexNumber.h
// Purpose:		Complex numbers
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

#include <iostream>
#include <string>
#include <cstdlib>//for POSIX compat
using namespace std;



///------------------- ComplexNumber class------------------
/// Purpose: Utilities for working with imaginary numbers
///-------------------End---------------------------------
class ComplexNumber
{
	//---------------- variable declarations --------------------
	private:
		double _realNumber;
		double _imaginaryNumber;

	//---------------- function prototypes --------------------
	public:
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default
		/// Parameters: None
		///-------------------------- End ------------------------------
		ComplexNumber(void);

		///----------------- Constructor -----------------------
		/// Purpose: To create an employee object given its parameters
		/// Parameters: integer employeeNumber,
		///				strings for name, address, phone number
		///-------------------------- End ------------------------------
		ComplexNumber(double, double);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the real number part
		/// Parameters: double for number
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetRealNumber(double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the real number part
		/// Returns: double for real number
		///-------------------------- End ------------------------------
		double GetRealNumber(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the imaginary number part
		/// Parameters: double for number
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetImaginaryNumber(double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the imaginary number part
		/// Returns: double for imaginary  number
		///-------------------------- End ------------------------------
		double GetImaginaryNumber(void);

		///-------------------- addition operator overloading Function -----------------------
		/// Purpose: Adds two ComplexNumber objects together
		/// Returns: ComplexNumber Result
		///-------------------------- End ------------------------------
		ComplexNumber operator + (const ComplexNumber& rho);

		///-------------------- subtraction operator overloading Function -----------------------
		/// Purpose: Subtracts two ComplexNumber objects
		/// Returns: ComplexNumber Result
		///-------------------------- End ------------------------------
		ComplexNumber operator - (const ComplexNumber& rho);

		///-------------------- multiplication operator overloading Function -----------------------
		/// Purpose: Multiplies two ComplexNumber objects together
		/// Returns: ComplexNumber Result
		///-------------------------- End ------------------------------
		ComplexNumber operator * (const ComplexNumber& rho);

		///-------------------- division operator overloading Function -----------------------
		/// Purpose: Devides two ComplexNumber objects
		/// Returns: ComplexNumber Result
		///-------------------------- End ------------------------------
		ComplexNumber operator / (const ComplexNumber& rho);

		///-------------------- assignment operator overloading Function -----------------------
		/// Purpose: Assigns the values of one ComplexNumber object to another
		/// Returns: ComplexNumber Result
		///-------------------------- End ------------------------------
		ComplexNumber operator = (const ComplexNumber& rho);

		///-------------------- equality operator overloading Function -----------------------
		/// Purpose: Test to see if two ComplexNumber objects are equal
		/// Returns: true it equal
		///-------------------------- End ------------------------------
		bool operator == (const ComplexNumber& rho);
};


//-------------------------Stand Alone Functions ----------------------------------


///-------------------- stream insertion overloading Function -----------------------
/// Purpose: Test to see if two ComplexNumber objects are equal
/// Returns: true it equal
///-------------------------- End ------------------------------
ostream& operator<<(ostream& out, const ComplexNumber& rho);