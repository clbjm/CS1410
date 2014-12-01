//============================================================================
// File:		Employee.h
// Purpose:		Employee class exercise
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

// # define guard, prevents multiple inclusion
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>//for POSIX compat

#include "Utils.h" //input validation stuff
#include "FileException.h"
#include "IOException.h"

using namespace std;


///------------------- Employee class------------------
/// Purpose: Keep track of employee information & compute pay
///-------------------End---------------------------------
class Employee
{
	//---------------- variable declarations --------------------
	private:
		int _employeeNumber;
		string _name;
		string _streetAddress;
		string _phoneNumber;
		double _hourlyWage;
		double _hoursWorked;

	//---------------- function prototypes --------------------
	public:
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default
		/// Parameters: None
		///-------------------------- End ------------------------------
		Employee(void);

		///----------------- Constructor -----------------------
		/// Purpose: To create an employee object given its parameters
		/// Parameters: integer employeeNumber,
		///				strings for name, address, phone number
		///				doubles for hours worked & pay rate
		///-------------------------- End ------------------------------
		Employee(int, string, string, string, double, double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the employee number
		/// Returns: int as employee number
		///-------------------------- End ------------------------------
		int GetNumber(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the employee number
		/// Parameters: int for number
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetNumber(int);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the employee name
		/// Returns: string as employee name
		///-------------------------- End ------------------------------
		string GetName(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the employee name
		/// Parameters: string for name
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetName(string);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the employee Address
		/// Returns: string as employee Address
		///-------------------------- End ------------------------------
		string GetAddress(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the employee Address
		/// Parameters: string for address
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetAddress(string);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the employee phone number
		/// Returns: string as employee phone number
		///-------------------------- End ------------------------------
		string GetPhoneNumber(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the employee phone number
		/// Parameters: string for phone number
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetPhoneNumber(string);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the hours worked
		/// Returns: double as hours worked
		///-------------------------- End ------------------------------
		double GetHoursWorked(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the hours worked
		/// Parameters: double for hours worked
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetHoursWorked(double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the hourly wage
		/// Returns: double as hourly wage
		///-------------------------- End -----------------------------
		double GetHourlyWage(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the hoursly wage
		/// Parameters: double for hourly wage
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetHourlyWage(double);

		///--------------------Calculation Function---------------------
		/// Purpose: calculate and return an employees net pay
		/// Returns: double as net pay
		///---------------------------End-------------------------------
		double CalcPay(void);

		///--------------------ReadData Function---------------------
		/// Purpose: read data from a persistence file
		/// Returns:
		///---------------------------End-------------------------------
		void ReadData(ifstream&);

		///--------------------WriteData Function---------------------
		/// Purpose: write data to a persistence file
		/// Returns:
		///---------------------------End-------------------------------
		void WriteData(ofstream&);

		///--------------------ToString Function---------------------
		/// Purpose: Convert the object to a string
		/// Returns: string representation of the object
		///---------------------------End-------------------------------
		string ToString(void);

};


///--------------------PrintCheck Function---------------------
/// Purpose: output the employees name, net pay for pay period, hours worked, and wage.
/// Parameters: Reference to an Employee object
/// Returns: void
///---------------------------End-------------------------------
void PrintCheck(Employee&);

#endif  // EMPLOYEE_H_


