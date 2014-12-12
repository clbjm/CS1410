//============================================================================
// Name:		FileIO.cpp
// Purpose:		Class for Input/Output operations
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
#include "FileIO.h"

const string INVALID_MODE_MSG = "Invalid mode -> unknown Mode";
const string ERROR_WORD = "Error Word-> ";
const string ERROR_FREE = " Error free ";
const string GOOD_BIT = "good bit-> ";
const string BAD_BIT = "bad bit-> ";
const string FAIL_BIT = "fail bit-> ";
const string EOF_BIT = "eof bit-> ";
const string EOF_FOUND = "eof found ";

const string HOURLY_EMPLOYEE = "hourly";
const string SALARY_EMPLOYEE = "salary";
const string SALES_EMPLOYEE = "sales";

FileIO::FileIO()
{
	// TODO Auto-generated constructor stub
}

bool FileIO::OpenDB(string filename, int mode)
{
	switch (mode)
	{
		case 0:
			_ioFile.open(filename.c_str(), ios::in | ios::out | ios::ate);//ate = "at end"
			break;
		case 1:
			_ioFile.open(filename.c_str(), ios::in | ios::out | ios::trunc);//truncate
			break;
		default:
			string error = INVALID_MODE_MSG;
			throw IOException(error, 0);
			break;
	}
	string func = __FUNCTION__;
	CheckErrors(func);
	return true;
}

bool FileIO::ReadDB(Employee*& employee)//reference to pointer
{
	Employee* ePtr = NULL;
	string type = "";
	getline(_ioFile, type);//read the first line, get the type
	if (_ioFile.eof()) return false;
	//sort the types
	if (type == HOURLY_EMPLOYEE) ePtr = new Hourly();//Problem here is that this is not the same pointer!
	else if (type == SALARY_EMPLOYEE) ePtr = new Salary();
	else if (type == SALES_EMPLOYEE) ePtr = new Sales();
	else
	{
		//TODO handle error!
	}
	ePtr->ReadData(_ioFile);
	employee = ePtr;
	string func = __FUNCTION__;
	CheckErrors(func);
	return true;
}

bool FileIO::WriteDB(Employee* employee)
{
	employee->WriteData(_ioFile);// TODO throws IOException
	string func = __FUNCTION__;
	CheckErrors(func);
	return true;
}

bool FileIO::SeekDB(int mode)
{
	switch (mode)
	{
	case 0:
		_ioFile.seekp(0, ios::beg);//seekp(streamoff off, ios_base::seekdir way);
		break;
	case 1:
		_ioFile.seekp(0, ios::end);
		break;
	default:
		string error = INVALID_MODE_MSG;
		throw IOException(error, 0);
		break;
	}
	string func = __FUNCTION__;
	CheckErrors(func);
	return true;
}

bool FileIO::CloseDB()
{
	if (_ioFile.is_open())
	{
		_ioFile.close();
	}
	
	//string func = __FUNCTION__;
	//CheckErrors(func);
	return true;
}

bool FileIO::CheckErrors(string& msg)
{
	if (0 == _ioFile.rdstate())
	{
		string rdStg = msg + ERROR_FREE;
		cout << rdStg << endl;
		return true;
	}
	if (_ioFile.eof())
	{
		cout << EOF_FOUND << endl;
	}
	//print metadata about the errors
	cout << msg << ERROR_WORD << _ioFile.rdstate() << endl;
	cout << GOOD_BIT << _ioFile.good() << " " << _ioFile.goodbit << endl;
	cout << BAD_BIT << _ioFile.bad() << " " << _ioFile.badbit << endl;
	cout << FAIL_BIT << _ioFile.fail() << " " << _ioFile.failbit << endl;
	cout << EOF_BIT << _ioFile.eof() << " " << _ioFile.eofbit << endl;
	//throw a FileException
	throw FileException(msg, 0);
	//close and clear the file
	//_ioFile.clear();
	//_ioFile.close();
	return false;
}//End CheckErrors()
