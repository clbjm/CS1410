//============================================================================
// Name:		Employee.cpp
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

#include "Employee.h"

const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double WORK_WEEK = 40.0;
const double OVERTIME_RATE = 1.5;

const string CHECK_TITLE = "---------------------FluffShuffle Electronics------------------------";
const string PAY_TO = "Pay to the order of ";
const string AMOUNT_SPACE = "...........$";
const string BANK_NAME = "United Bank of East Orem";
const string CHECK_LINE = "----------------------------------------------------------------------";
const string HOURS_WORKED = "Hours Worked: ";
const string HOURLY_WAGE = "Hourly Wage:  ";

const char COMMA_DELIMITER = ',';
const string EXCEPTION_MSG = "Exception thrown: ";
const string BAD_DATA_MSG = "Bad data or end of file reached.";
const string FILE_END_MSG = "No more data in the file.";
enum CSV_ORDER { EMP_NUMBER, EMP_NAME, EMP_ADDRESS, EMP_PH_NUMBER, EMP_HOURS, EMP_WAGE };



bool exitRequested = false;

//Employee constructor default.
Employee::Employee(void){
	_employeeNumber = 0;
	_name = "";
	_streetAddress = "";
	_phoneNumber = "";
	_hoursWorked = 0.0;
	_hourlyWage = 0.0;
}

Employee::Employee(int number, string name, string address, string phone, double hours, double wage)
{
	_employeeNumber = number;
	_name = name;
	_streetAddress = address;
	_phoneNumber = phone;
	_hoursWorked = hours;
	_hourlyWage = wage;
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

double Employee::GetHoursWorked(void)
{
	return _hoursWorked;
}

void Employee::SetHoursWorked(double hours)
{
	_hoursWorked = hours;
}

double Employee::GetHourlyWage(void)
{
	return _hourlyWage;
}

void Employee::SetHourlyWage(double wage)
{
	_hourlyWage = wage;
}


double Employee::CalcPay()
{
	double gross = 0.0;
	//check to see if there is overtime
	if (_hoursWorked > WORK_WEEK)
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

void Employee::ReadData(ifstream& inFile)
{
	if (inFile.is_open())
	{
		try
		{
			string CSVRow = "";
			//get the entire line from the file (it's comma separated) 
			getline(inFile, CSVRow);
			vector <string> cells;
			//split the row into cells delimited by comma, store in a vector
			SplitString(CSVRow, COMMA_DELIMITER, cells);//MAGIC
			//read the object from the file
			_employeeNumber = StringToValidInt(cells[EMP_NUMBER]);
			_name = cells[EMP_NAME];
			_streetAddress = cells[EMP_ADDRESS];
			_phoneNumber = cells[EMP_PH_NUMBER];
			_hoursWorked = StringToValidDouble(cells[EMP_HOURS]);//double
			_hourlyWage = StringToValidDouble(cells[EMP_WAGE]);//double
		}
		catch (IOException& e)
		{
			//exception is thrown if data in file is bad
			//display the exception
			cout << e.GetMessage() << endl;
			//throw a file exception indicating that there is something wrong with the file data
			string error = BAD_DATA_MSG;
			throw FileException(error, 0);
		}
	}
	else
	{
		//TODO throw Exception;
	}
}

void Employee::WriteData(ofstream& outFile)
{
	if (outFile.is_open())
	{
		//write the object to the file as comma separated values csv
		string CSVRow = ToString();
		outFile << CSVRow << endl;
	}
	else
	{
		//TODO throw Exception;
	}
}

string Employee::ToString(void)
{
	ostringstream os;
	//add each variable followed by a tab character
	os << _employeeNumber << COMMA_DELIMITER;
	os << _name.c_str() << COMMA_DELIMITER;
	os << _streetAddress.c_str() << COMMA_DELIMITER;
	os << _phoneNumber.c_str() << COMMA_DELIMITER;
	os << _hoursWorked << COMMA_DELIMITER;
	os << _hourlyWage;
	string temp = os.str();
	return temp;
}

void PrintCheck(Employee &employee)
{
	//print the check title
	cout << CHECK_TITLE << endl << endl;
	//format the output for fixed point and show two decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//print name and amount to pay
	cout << PAY_TO << employee.GetName() << AMOUNT_SPACE << employee.CalcPay() << endl << endl;
	//print the bank name
	cout << BANK_NAME << endl;
	//print a line across the console
	cout << CHECK_LINE << endl;
	//print the hours worked
	cout << HOURS_WORKED << employee.GetHoursWorked() << endl;
	//print the hourly wage
	cout << HOURLY_WAGE << employee.GetHourlyWage() << endl;
}//end PrintCheck()
