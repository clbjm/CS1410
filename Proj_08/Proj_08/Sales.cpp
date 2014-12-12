//============================================================================
// Name:		Sales.cpp
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

#include "Employee.h"

const string SALES_DEFAULT_CONSTRUCTOR_MSG = "Sales default Constructor.";
const string SALES_CONSTRUCTOR_MSG = "Sales Parameterized Constructor: ";

const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double BENEFIT_RATE = 0.0524;
const double WORK_WEEK = 40.0;
const double OVERTIME_RATE = 1.5;

const string EXCEPTION_MSG = "exception thrown: ";



const string HOURS_WORKED = "Hours Worked: ";
const string HOURLY_WAGE = "Hourly Wage:  ";
const string SALES_WAGE = "Weekly Sales: ";

const string SALES_EMPLOYEE = "sales";

//-------------------------------------Sales Class------------------------------------
Sales::Sales(void) : Employee()
{
	_baseSalary = 0;
	_grossSales = 0;
	_commission = 0;
	cout << SALES_DEFAULT_CONSTRUCTOR_MSG << endl;
}

Sales::Sales(int number, string name, string address, string phone,double salary, double sales, double commission) : Employee(number, name, address, phone)
{
	_baseSalary = salary;
	_grossSales = sales;
	_commission = commission;
	cout << SALES_CONSTRUCTOR_MSG << name << endl;
}

//-----------------------Getters & Setters----------------------


double Sales::GetBaseSalary(void)
{
	return _baseSalary;
}

void Sales::SetBaseSalary(double salary)
{
	_baseSalary = salary;
}

double Sales::GetGrossSales(void)
{
	return _grossSales;
}

void Sales::SetGrossSales(double sales)
{
	_grossSales = sales;
}

double Sales::GetCommission(void)
{
	return _commission;
}

void Sales::SetCommission(double commission)
{
	_commission = commission;
}

//-----------------------------member functions -----------------------

void Sales::ReadData(fstream& inFile)
{
	if (inFile.is_open())
	{
		string temp = "";
		//read the remaining data into the derived class
		getline(inFile, temp);
		_baseSalary = StringToValidDouble(temp);//double
		getline(inFile, temp);
		_commission = StringToValidDouble(temp);//double
		getline(inFile, temp);
		_grossSales = StringToValidDouble(temp);//double
		Employee::ReadData(inFile);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

void Sales::WriteData(fstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << SALES_EMPLOYEE << endl;
		outFile << _baseSalary << endl;
		outFile << _grossSales << endl;
		outFile << _commission << endl;
		Employee::WriteData(outFile);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

double Sales::CalcPay()
{
	//gross is weekly Sales
	double gross = _baseSalary/2.0;
	//add commission & sales
	gross += (_commission * _grossSales);
	//calculate the state tax
	double stateTax = gross * STATE_RATE;
	//calculate the federal tax
	double fedTax = gross * FEDERAL_RATE;
	//calculate the benefit
	double benefit = gross * BENEFIT_RATE;
	//return the gross pay after tax is deducted
	return gross - (stateTax + fedTax + benefit);
}

void Sales::PrintCheck()
{
	//print the main check parts
	Employee::PrintCheck();
	//print the  wage
	cout << SALES_WAGE << _baseSalary << endl;
}//end PrintCheck()
