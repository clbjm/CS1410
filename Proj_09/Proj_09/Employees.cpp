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

#include "Employees.h"

const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double BENEFIT_RATE = 0.0524;
const double WORK_WEEK = 40.0;
const double OVERTIME_RATE = 1.5;

const string EXCEPTION_MSG = "exception thrown: ";

enum ORDER{ EMP_NUM = 0, NAME = 1, ADDRESS = 2, PHN_NUM = 3, HOURS = 4, WAGE = 5 };

const string CHECK_TITLE = "---------------------FluffShuffle Electronics------------------------";
const string PAY_TO = "Pay to the order of ";
const string AMOUNT_SPACE = "...........$";
const string BANK_NAME = "United Bank of East Orem";
const string CHECK_LINE = "----------------------------------------------------------------------";
const string HOURS_WORKED = "Hours Worked: ";
const string HOURLY_WAGE = "Hourly Wage:  ";
const string SALARY_WAGE = "Weekly Salary: ";

const char COMMA_DELIMITER = ',';

const string HOURLY_DEFAULT_CONSTRUCTOR_MSG = "HourlyEmployee default Constructor";
const string HOURLY_CONSTRUCTOR_MSG = "HourlyEmployee Parameterized Constructor: ";
const string SALARY_DEFAULT_CONSTRUCTOR_MSG = "SalaryEmployee default Constructor.";
const string SALARY_CONSTRUCTOR_MSG = "SalaryEmployee Parameterized Constructor: ";
const string HOURLY_EMPLOYEE = "hourly";
const string SALARY_EMPLOYEE = "salary";


//-------------------------------------Employee Class------------------------------------
//Employee constructor default.
Employee::Employee(void){
	_employeeNumber = 0;
	_name = "";
	_streetAddress = "";
	_phoneNumber = "";
}

Employee::Employee(int number, string name, string address, string phone)
{
	_employeeNumber = number;
	_name = name;
	_streetAddress = address;
	_phoneNumber = phone;
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

void Employee::WriteData(ofstream& outFile)
{
		outFile << _employeeNumber << endl;
		outFile << _name << endl;
		outFile << _streetAddress << endl;
		outFile << _phoneNumber << endl;
}

void Employee::ReadData(ifstream& inFile)
{
	string temp = "";
	getline(inFile, temp);
	_employeeNumber = StringToValidInt(temp);
	getline(inFile, _name);
	getline(inFile, _streetAddress);
	getline(inFile, _phoneNumber);
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
	cout << PAY_TO << _name << AMOUNT_SPACE << CalcPay() << endl << endl;
	//print the bank name
	cout << BANK_NAME << endl;
	//print a line across the console
	cout << CHECK_LINE << endl;
}


//-------------------------------------HourlyEmployee Class------------------------------------
HourlyEmployee::HourlyEmployee() : Employee()
{
	_hoursWorked = 0.0;
	_hourlyWage = 0.0;
	cout << HOURLY_DEFAULT_CONSTRUCTOR_MSG << endl;
}

HourlyEmployee::HourlyEmployee(int number, string name, string address, string phone, double hours, double wage) : Employee(number, name, address, phone)
{
	_hoursWorked = hours;
	_hourlyWage = wage;
	cout << HOURLY_CONSTRUCTOR_MSG << name << endl;
}

//----------------------Getters & Setters-----------------------
double HourlyEmployee::GetHoursWorked(void)
{
	return _hoursWorked;
}

void HourlyEmployee::SetHoursWorked(double hours)
{
	_hoursWorked = hours;
}

double HourlyEmployee::GetHourlyWage(void)
{
	return _hourlyWage;
}

void HourlyEmployee::SetHourlyWage(double wage)
{
	_hourlyWage = wage;
}

//-----------------------------member functions -----------------------

void HourlyEmployee::ReadData(ifstream& inFile)
{
	if (inFile.is_open())
	{
		try
		{
			string temp = "";
			//read the remaining data into the derived class
			getline(inFile, temp);
			_hoursWorked = StringToValidDouble(temp);//double
			getline(inFile, temp);
			_hourlyWage = StringToValidDouble(temp);//double
			Employee::ReadData(inFile);
		}
		catch (FileException& e)
		{
			cout << EXCEPTION_MSG << e.GetMessage() << endl;
		}
	}
	else
	{
		//TODO throw Exception;
	}
}

void HourlyEmployee::WriteData(ofstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << HOURLY_EMPLOYEE << endl;
		outFile << _hoursWorked << endl;
		outFile << _hourlyWage << endl;
		Employee::WriteData(outFile);
	}
	else
	{
		//TODO throw Exception;
	}
}

double HourlyEmployee::CalcPay()
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

void HourlyEmployee::PrintCheck()
{	
	Employee::PrintCheck();
	//print the hours worked
	cout << HOURS_WORKED << _hoursWorked << endl;
	//print the hourly wage
	cout << HOURLY_WAGE << _hourlyWage << endl;
}//end PrintCheck()




//-------------------------------------SalaryEmployee Class------------------------------------
SalaryEmployee::SalaryEmployee(void) : Employee()
{
	_weeklySalary = 0.0;
	cout << SALARY_DEFAULT_CONSTRUCTOR_MSG << endl;
}

SalaryEmployee::SalaryEmployee(int number, string name, string address, string phone, double salary) : Employee(number, name, address, phone)
{
	_weeklySalary = salary;
	cout << SALARY_CONSTRUCTOR_MSG << name << endl;
}

//-----------------------Getters & Setters----------------------
double SalaryEmployee::GetWeeklySalary()
{
	return _weeklySalary;
}

void SalaryEmployee::SetWeeklySalary(double weeklySalary)
{
	_weeklySalary = weeklySalary;
}

//-----------------------------member functions -----------------------

void SalaryEmployee::ReadData(ifstream& inFile)
{
	if (inFile.is_open())
	{
		try
		{
			string temp = "";
			//read the remaining data into the derived class
			getline(inFile, temp);
			_weeklySalary = StringToValidDouble(temp);//double
			Employee::ReadData(inFile);
		}
		catch (FileException& e)
		{
			cout << EXCEPTION_MSG << e.GetMessage() << endl;
		}
	}
	else
	{
		//TODO throw Exception;
	}
}

void SalaryEmployee::WriteData(ofstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << SALARY_EMPLOYEE << endl;
		outFile << _weeklySalary << endl;
		Employee::WriteData(outFile);
	}
	else
	{
		//TODO throw Exception;
	}
}

double SalaryEmployee::CalcPay()
{
	//gross is weekly salary
	double gross = _weeklySalary;
	//calculate the state tax
	double stateTax = gross * STATE_RATE;
	//calculate the federal tax
	double fedTax = gross * FEDERAL_RATE;
	//calculate the benefit
	double benefit = gross * BENEFIT_RATE;
	//return the gross pay after tax is deducted
	return gross - (stateTax + fedTax + benefit);
}


void SalaryEmployee::PrintCheck()
{
	//print the standard employee info
	Employee::PrintCheck();
	//print the hourly wage
	cout << SALARY_WAGE << _weeklySalary << endl;
}//end PrintCheck()