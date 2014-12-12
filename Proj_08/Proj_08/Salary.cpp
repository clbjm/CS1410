//============================================================================
// Name:		Salary.cpp
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

const string SALARY_DEFAULT_CONSTRUCTOR_MSG = "Salary default Constructor.";
const string SALARY_CONSTRUCTOR_MSG = "Salary Parameterized Constructor: ";
const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double BENEFIT_RATE = 0.0524;
const string EXCEPTION_MSG = "exception thrown: ";
const string HOURS_WORKED = "Hours Worked: ";
const string HOURLY_WAGE = "Hourly Wage:  ";
const string SALARY_WAGE = "Monthly Salary: ";
const string SALARY_EMPLOYEE = "salary";

//-------------------------------------Salary Class------------------------------------
Salary::Salary(void) : Employee()
{
	_monthlySalary = 0.0;
	cout << SALARY_DEFAULT_CONSTRUCTOR_MSG << endl;
}

Salary::Salary(int number, string name, string address, string phone, double salary) : Employee(number, name, address, phone)
{
	_monthlySalary = salary;
	cout << SALARY_CONSTRUCTOR_MSG << name << endl;
}

//-----------------------Getters & Setters----------------------
double Salary::GetMonthlySalary()
{
	return _monthlySalary;
}

void Salary::SetMonthlySalary(double MonthlySalary)
{
	_monthlySalary = MonthlySalary;
}

//-----------------------------member functions -----------------------

void Salary::ReadData(fstream& inFile)
{
	if (inFile.is_open())
	{
		string temp = "";
		//read the remaining data into the derived class
		getline(inFile, temp);
		_monthlySalary = StringToValidDouble(temp);//double
		Employee::ReadData(inFile);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

void Salary::WriteData(fstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << SALARY_EMPLOYEE << endl;
		outFile << _monthlySalary << endl;
		Employee::WriteData(outFile);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

double Salary::CalcPay()
{
	//gross is Monthly salary
	double gross = _monthlySalary/2.0;
	//calculate the state tax
	double stateTax = gross * STATE_RATE;
	//calculate the federal tax
	double fedTax = gross * FEDERAL_RATE;
	//calculate the benefit
	double benefit = gross * BENEFIT_RATE;
	//return the gross pay after tax is deducted
	return gross - (stateTax + fedTax + benefit);
}

void Salary::PrintCheck()
{
	//print the main check parts
	Employee::PrintCheck();
	//print the salary line
	cout << SALARY_WAGE << _monthlySalary << endl;
}//end PrintCheck()
