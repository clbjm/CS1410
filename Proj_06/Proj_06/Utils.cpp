//============================================================================
// Name        : Utils.cpp
// Author      : Kevin S. O'Day
// Version     : 1.0
// Project	   : Proj_05
// Purpose	   : Utilities for validating input
// Date        : October 2014
// Date        : 10/27/14 9:59 AM
//============================================================================

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include "Utils.h"
#include "IOException.h"

const string INT_ERR_MSG = "That input could not be converted to an integer, please try again.";
const char DECIMAL_POINT = '.';
const char PLUS_SIGN = '+';
const char MINUS_SIGN = '-';
const string DIGITS = "0123456789";

const string ERROR_EOF = "End of file character read";
const string ERROR_STRING_EMPTY = "Empty string";
const string ERROR_STRING_INVALID = "Invalid string";
const string ERROR_INTEGER_INVALID = "Invalid input integer";
const string ERROR_LINE_EMPTY = "Empty Line";
const string ERROR_DOUBLE_INVALID = "invalid input double: ";
const string ERROR_INPUT_INVALID = "invalid input";
const string ERROR_FILE_FAIL = "File bad or File fail";

int GetInputInt(string prompt)
{
	string temp = "";
	int number = 0;
	bool validInput;
	do{
		validInput = true;
		//clear the console
		//system("CLR");
		//Prompt the user to enter a value.
		cout << prompt;
		//place the value in string temp
		getline(cin, temp);

		//check to see if CTRL-Z has been pressed
		if (cin.eof()){
			throw IOException(ERROR_EOF, DEFAULT);
			cin.clear();
			return 0;
		}
		number = ValidateInt(temp);
		return number;
	} while (true);//end while loop

	//only if there is an error TODO exception!
	//return -1;
} // End GetInputInt(string prompt)


int ValidateInt(string& numStr)
{
	int number = 0;
	//if the string is empty,
	if (numStr.empty()){
		throw IOException(ERROR_STRING_EMPTY, DEFAULT);
	}
	// Decimal point, '+' or '-' or any digit are all valid first characters
	if ((numStr[0] == PLUS_SIGN) || (numStr[0] == MINUS_SIGN) || IsDigit(numStr[0]) || isspace(numStr[0]))
	{
		//check all the characters after the first for validity
		for (unsigned int i = 1; i < numStr.length(); i++)
		{
			//if the character is not a valid digit and is also not a decimal point
			//or there is more than one decimal point
			if (!IsDigit(numStr[i]))
			{
				//input is invalid
				throw IOException(ERROR_STRING_INVALID, DEFAULT);
			}
		}
	}
	else
	{
		//input is invalid
		throw IOException(ERROR_INTEGER_INVALID, DEFAULT);
	}

	//convert the validated numStr string to integer
	//return as integer
	number = atoi(numStr.c_str());
	return number;
}

double ValidateDouble(string& numStr)
{
	double number = 0;
	int radixPointCount = 0;
	//if the line is empty,
	if (numStr.empty()){
		throw IOException(ERROR_LINE_EMPTY, 0);
	}
	// Decimal point, '+' or '-' or any digit are all valid first characters
	if ((numStr[0] == PLUS_SIGN) || (numStr[0] == MINUS_SIGN) || (numStr[0] == DECIMAL_POINT) || IsDigit(numStr[0]) || isspace(numStr[0]))
	{
		//test to see if the first character is a decimal
		if (numStr[0] == DECIMAL_POINT)
		{
			radixPointCount++;
		}
		//check all the characters after the first for validity
		for (unsigned int i = 1; i < numStr.length(); i++)
		{
			//test to see if the character is a decimal
			if (numStr[i] == DECIMAL_POINT)
			{
				radixPointCount++;
			}

			//if the character is not a valid digit and is also not a decimal point
			//or there is more than one decimal point
			if ((!IsDigit(numStr[i]) && !(numStr[i] == DECIMAL_POINT)) || radixPointCount > 1)
			{
				//input is invalid
				string error = ERROR_DOUBLE_INVALID;
				error.append(1, numStr[i]);
				throw IOException(error, DEFAULT);
			}
		}
	}
	else
	{
		//input is invalid
		throw IOException(ERROR_INPUT_INVALID, DEFAULT);
	}

	//convert the validated str string to floating point number
	//store as double
	number = atof(numStr.c_str());
	return number;
}

double GetInputDouble(ifstream& file)
{
	string temp = "";
	double number = 0;
	//get the line from the text file. (Just like with cin)
	getline(file, temp);

	//test if the file is at the end
	if (file.eof())
	{
		throw IOException(ERROR_EOF, DEFAULT);
		return 0.0;
	}
	//test if input is bad, or failed
	else if (file.bad() || file.fail())
	{
		throw IOException(ERROR_FILE_FAIL, DEFAULT);
	}

	number = ValidateDouble(temp);
	return number;
} // End GetValidInputDouble()

int GetInputInt(ifstream& file)
{
	string temp = "";
	int number = 0;
	//get the line from the text file. (Just like with cin)
	getline(file, temp);

	//test if the file is at the end
	if (file.eof())
	{
		throw IOException(ERROR_EOF, DEFAULT);
	}
	//test if input is bad, or failed
	else if (file.bad() || file.fail())
	{
		throw IOException(ERROR_FILE_FAIL, DEFAULT);
	}
	//convert the validated temp string to integer
	//store as int
	number = ValidateInt(temp);
	return number;
} // End GetValidInputInt()

bool IsDigit(char c)
{
	//verify that the given character is a valid digit
	for (unsigned int i = 0; i < DIGITS.length(); i++)
	{
		if (c == DIGITS[i])
		{
			return true;
		}
	}
	return false;
}//End IsDigit()


void SplitString(string& str, char delimiter, vector<string>& cells)
{
	stringstream strStream(str);
	while (strStream.good())
	{
		string cell;
		getline(strStream, cell, delimiter);
		cells.push_back(cell);
	}
}


string GetInputFileName(string prompt)
{
	string temp = "";
	bool validFileName = true;
	do{
		cin.clear();

		//Prompt the user to enter a value.
		cout << prompt;
		//place the value in string temp
		getline(cin, temp);

		//check to see if CTRL-Z has been pressed
		if (cin.eof()){
			throw IOException(ERROR_EOF, EXIT);
			cin.clear();
			return 0;
		}

		validFileName = ValidateFileName(temp);

	} while (!validFileName);//end while loop
	return temp;
}

//TODO improve this to make it functinoal
bool ValidateFileName(string fileName)
{
	//if the input is valid
	return true;
}