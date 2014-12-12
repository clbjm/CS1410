//============================================================================
// Name:		Hourly.cpp
// Purpose:		Test Employee Inheritance
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

#include "Employee.h"

const string HOURLY_DEFAULT_CONSTRUCTOR_MSG = "Hourlydefault Constructor";
const string HOURLY_CONSTRUCTOR_MSG = "Hourly Parameterized Constructor: ";
const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double BENEFIT_RATE = 0.0524;
const double WORK_WEEK = 40.0;
const double OVERTIME_RATE = 1.5;
const string EXCEPTION_MSG = "exception thrown: ";
const string HOURS_WORKED = "Hours Worked: ";
const string HOURLY_WAGE = "Hourly Wage:  ";
const string HOURLY_EMPLOYEE = "hourly";


//-------------------------------------Hourly Class------------------------------------
Hourly::Hourly() : Employee()
{
	_hoursWorked = 0.0;
	_hourlyWage = 0.0;
	cout << HOURLY_DEFAULT_CONSTRUCTOR_MSG << endl;
}

Hourly::Hourly(int number, string name, string address, string phone, double hours, double wage) : Employee(number, name, address, phone)
{
	_hoursWorked = hours;
	_hourlyWage = wage;
	cout << HOURLY_CONSTRUCTOR_MSG << name << endl;
}

//----------------------Getters & Setters-----------------------
double Hourly::GetHoursWorked(void)
{
	return _hoursWorked;
}

void Hourly::SetHoursWorked(double hours)
{
	_hoursWorked = hours;
}

double Hourly::GetHourlyWage(void)
{
	return _hourlyWage;
}

void Hourly::SetHourlyWage(double wage)
{
	_hourlyWage = wage;
}

//-----------------------------member functions -----------------------

void Hourly::ReadData(fstream& inFile)
{
	if(inFile.is_open())
	{
		string temp = "";
		//read the remaining data into the derived class
		getline(inFile, temp);
		_hoursWorked = StringToValidDouble(temp);//double
		getline(inFile, temp);
		_hourlyWage = StringToValidDouble(temp);//double
		Employee::ReadData(inFile);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

void Hourly::WriteData(fstream& outFile)
{
	if(outFile.is_open())
	{
		outFile << HOURLY_EMPLOYEE << endl;
		outFile << _hoursWorked << endl;
		outFile << _hourlyWage << endl;
		Employee::WriteData(outFile);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

double Hourly::CalcPay()
{
	double gross = 0.0;
	//check to see if there is overtime
	if (_hoursWorked >= WORK_WEEK)
	{
		//base pay for work week
		gross = _hourlyWage * WORK_WEEK;
		//additional pay for overtime at specified rate
		gross += ((_hoursWorked - WORK_WEEK) * _hourlyWage * OVERTIME_RATE);
	}
	else
	{
		//under basic work week
		gross = _hourlyWage * _hoursWorked;
	}
	//calculate the state tax
	double stateTax = gross * STATE_RATE;
	//calculate the federal tax
	double fedTax = gross * FEDERAL_RATE;
	//return the gross pay after tax is deducted
	return gross - (stateTax + fedTax);
}

void Hourly::PrintCheck()
{
	//print the main check parts
	Employee::PrintCheck();
	//print the hours worked
	cout << HOURS_WORKED << _hoursWorked << endl;
	//print the hourly wage
	cout << HOURLY_WAGE << _hourlyWage << endl;
}//end PrintCheck()
