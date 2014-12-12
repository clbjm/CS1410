//============================================================================
// Name:		Employee.h
// Purpose:		Employee classes
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

// # define guard, prevents multiple inclusion
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>//for POSIX compat

#include "FileException.h"
#include "Utils.h" //input validation stuff

using namespace std;

enum ORDER{ EMP_NUM = 0, NAME = 1, ADDRESS = 2, PHN_NUM = 3, HOURS = 4, WAGE = 5, SALES = 6, COMMISSION = 7 };
const string FILE_NOT_OPEN_ERROR_MSG = "Error, File not open.";

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
		///-------------------------- End ------------------------------
		Employee(int, string, string, string);

		///----------------- virtual Destructor -----------------------
		/// Purpose: Clean up and destroy employee object.
		///-------------------------- End ------------------------------
		virtual ~Employee();

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

		///--------------------ReadData virtual Function---------------------
		/// Purpose: read data from a persistence file
		///	Parameters: reference to an fstream object
		/// Returns:
		///---------------------------End-------------------------------
		virtual void ReadData(fstream&);

		///--------------------WriteData virtual Function---------------------
		/// Purpose: write data to a persistence file
		///	Parameters: reference to an fstream object
		/// Returns:
		///---------------------------End-------------------------------
		virtual void WriteData(fstream&);

		///-------------------CalcPay function---------------------------
		/// Purpose: Pure Virtual function
		///---------------------------End--------------------------------
		virtual double CalcPay(void) = 0;

		///--------------------PrintCheck  virtual Function---------------------
		/// Purpose: Print the common parts of the check.
		/// Parameters: None
		/// Returns: None
		///---------------------------End-------------------------------
		virtual void PrintCheck();
};


///------------------- Hourly class------------------
/// Purpose: Keep track of employee information & compute pay
///-------------------End---------------------------------
class Hourly : public Employee
{
	//---------------- variable declarations --------------------
	private:
		double _hourlyWage;
		double _hoursWorked;

	//---------------- function prototypes --------------------
	public:
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default
		/// Parameters: None
		///-------------------------- End ------------------------------
		Hourly(void);

		///----------------- Constructor -----------------------
		/// Purpose: To create an hourly employee object given its parameters
		/// Parameters: integer employeeNumber,
		///				strings for name, address, phone number
		///				doubles for hours worked & pay rate
		///-------------------------- End ------------------------------
		Hourly(int, string, string, string, double, double);

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

		///--------------------ReadData Function---------------------
		/// Purpose: read data from a persistence file
		/// Returns:
		///---------------------------End-------------------------------
		void ReadData(fstream&);

		///--------------------WriteData Function---------------------
		/// Purpose: write data to a persistence file
		/// Returns:
		///---------------------------End-------------------------------
		void WriteData(fstream&);

		///--------------------Calculation Function---------------------
		/// Purpose: calculate and return an employees net pay
		/// Returns: double as net pay
		///---------------------------End-------------------------------
		virtual double CalcPay(void);

		///--------------------PrintCheck Function---------------------
		/// Purpose: output the employees name, net pay for pay period, hours worked, and wage.
		/// Parameters: None
		/// Returns: None
		///---------------------------End-------------------------------
		void PrintCheck();
};


///------------------- Sales class------------------
/// Purpose: Keep track of employee information & compute pay
///-------------------End---------------------------------
class Sales : public Employee
{
	//---------------- variable declarations --------------------
	private:
		double _baseSalary;
		double _grossSales;
		double _commission;

	//---------------- function prototypes --------------------
	public:
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default
		/// Parameters: None
		///-------------------------- End ------------------------------
		Sales(void);

		///----------------- Constructor -----------------------
		/// Purpose: To create an employee object given its parameters
		/// Parameters: integer employeeNumber,
		///				strings for name, address, phone number
		///				doubles for _baseSalary,_grossSales, _commission
		///-------------------------- End ------------------------------
		Sales(int, string, string, string, double, double, double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the base salary
		/// Returns: double as base salary
		///-------------------------- End -----------------------------
		double GetBaseSalary(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the base salary
		/// Parameters: double base salary
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetBaseSalary(double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the gross sales
		/// Returns: double as gross sales
		///-------------------------- End -----------------------------
		double GetGrossSales(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the gross sales
		/// Parameters: double gross sales
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetGrossSales(double);

		///-------------------- Getter Function -----------------------
		/// Purpose: To return the commission
		/// Returns: double as commission
		///-------------------------- End -----------------------------
		double GetCommission(void);

		///-------------------- Setter Function -----------------------
		/// Purpose: To set the commission
		/// Parameters: double commission
		/// Returns: void
		///-------------------------- End ------------------------------
		void SetCommission(double);

		///--------------------ReadData Function---------------------
		/// Purpose: read data from a persistence file
		/// Returns:
		///---------------------------End-------------------------------
		void ReadData(fstream&);

		///--------------------WriteData Function---------------------
		/// Purpose: write data to a persistence file
		/// Returns:
		///---------------------------End-------------------------------
		void WriteData(fstream&);

		///--------------------Calculation Function---------------------
		/// Purpose: calculate and return an employees net pay
		/// Returns: double as net pay
		///---------------------------End-------------------------------
		virtual double CalcPay(void);

		///--------------------PrintCheck Function---------------------
		/// Purpose: output the employees name, net pay for pay period, hours worked, and wage.
		/// Parameters: None
		/// Returns: None
		///---------------------------End-------------------------------
		void PrintCheck();
};


///------------------- Salary class------------------
/// Purpose: Keep track of employee information & compute pay //TODO Fix
///-------------------End---------------------------------
class Salary : public Employee
{
	//---------------- variable declarations --------------------
private:
	double _monthlySalary;

	//---------------- function prototypes --------------------
public:
	///----------------- Default Constructor -----------------------
	/// Purpose: To initialize all data members to their default
	/// Parameters: None
	///-------------------------- End ------------------------------
	Salary(void);

	///----------------- Constructor -----------------------
	/// Purpose: To create an employee object given its parameters
	/// Parameters: integer employeeNumber,
	///				strings for name, address, phone number
	///				double for salary
	///-------------------------- End ------------------------------
	Salary(int, string, string, string, double);

	///-------------------- Getter Function -----------------------
	/// Purpose: To return the monthly salary
	/// Returns: double as monthly salary
	///-------------------------- End -----------------------------
	double GetMonthlySalary(void);

	///-------------------- Setter Function -----------------------
	/// Purpose: To set the Monthly salary
	/// Parameters: double Monthly salary
	/// Returns: void
	///-------------------------- End ------------------------------
	void SetMonthlySalary(double);

	///--------------------ReadData Function---------------------
	/// Purpose: read data from a persistence file
	/// Returns:
	///---------------------------End-------------------------------
	void ReadData(fstream&);

	///--------------------WriteData Function---------------------
	/// Purpose: write data to a persistence file
	/// Returns:
	///---------------------------End-------------------------------
	void WriteData(fstream&);

	///--------------------Calculation Function---------------------
	/// Purpose: calculate and return an employees net pay
	/// Returns: double as net pay
	///---------------------------End-------------------------------
	virtual double CalcPay(void);

	///--------------------PrintCheck Function---------------------
	/// Purpose: output the employees name, net pay for pay period, hours worked, and wage.
	/// Parameters: None
	/// Returns: None
	///---------------------------End-------------------------------
	void PrintCheck();
};

#endif  // EMPLOYEE_H_
