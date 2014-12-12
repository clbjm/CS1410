//============================================================================
// Name:		Employee.cpp
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

const string DEFAULT_CONSTRUCTOR_MSG = "Employee default Constructor.";
const string DEFAULT_DESTRUCTOR_MSG = "Employee default Destructor.";
const string CONSTRUCTOR_MSG = "Employee Parameterized Constructor: ";
const string CHECK_TITLE = "---------------------FluffShuffle Electronics------------------------";
const string PAY_TO = "Pay to the order of ";
const string AMOUNT_SPACE = "...........$";
const string BANK_NAME = "United Bank of East Orem";
const string CHECK_LINE = "----------------------------------------------------------------------";

//-------------------------------------Employee Class------------------------------------
//Employee constructor default.
Employee::Employee(void){
	_employeeNumber = 0;
	_name = "";
	_streetAddress = "";
	_phoneNumber = "";
	cout << DEFAULT_CONSTRUCTOR_MSG << endl;
}

Employee::Employee(int number, string name, string address, string phone)
{
	_employeeNumber = number;
	_name = name;
	_streetAddress = address;
	_phoneNumber = phone;
	cout << CONSTRUCTOR_MSG << endl;
}

Employee::~Employee()
{
	cout << DEFAULT_DESTRUCTOR_MSG << endl;
}

int Employee::GetNumber(void)
{
	return _employeeNumber;
}

void Employee::SetNumber(int number)
{
	_employeeNumber = number;
}

string Employee::GetName(void)
{
	return _name;
}

void Employee::SetName(string name)
{
	_name = name;
}

string Employee::GetAddress(void)
{
	return _streetAddress;
}

void Employee::SetAddress(string address)
{
	_streetAddress = address;
}

string Employee::GetPhoneNumber(void)
{
	return _phoneNumber;
}

void Employee::SetPhoneNumber(string phone)
{
	_phoneNumber = phone;
}

void Employee::ReadData(fstream& inFile)
{
	//read the data that is common for all employee objects
	if(inFile.is_open())
	{
		string temp = "";
		getline(inFile, temp);
		_employeeNumber = StringToValidInt(temp);
		getline(inFile, _name);
		getline(inFile, _streetAddress);
		getline(inFile, _phoneNumber);
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

void Employee::WriteData(fstream& outFile)
{
	//write the data that is common for all employee objects
	if(outFile.is_open())
	{
		outFile << _employeeNumber << endl;
		outFile << _name << endl;
		outFile << _streetAddress << endl;
		outFile << _phoneNumber << endl;
	}
	else
	{
		string error = FILE_NOT_OPEN_ERROR_MSG;
		throw FileException(error, 0);
	}
}

void Employee::PrintCheck()
{
	//print the check title
	cout << CHECK_TITLE << endl << endl;
	//format the output for fixed point and show two decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//print name and amount to pay
	cout << PAY_TO << GetName() << AMOUNT_SPACE << CalcPay() << endl << endl;
	//print the bank name
	cout << BANK_NAME << endl;
	//print a line across the console
	cout << CHECK_LINE << endl;
}
