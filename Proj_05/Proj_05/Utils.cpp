//============================================================================
// Name:		Utils.cpp
// Purpose:		Utilities for validating input
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

#include "Utils.h"


const char DECIMAL_POINT = '.';
const char PLUS_SIGN = '+';
const char MINUS_SIGN = '-';
const string DIGITS = "0123456789";

const string INVALID_NUMBER_MSG = "The number you entered was invalid.\n";
const string INT_ERR_MSG = "That input could not be converted to an integer, please try again.";
const string EOF_MSG = "End of file character read";
const string INVALID_CHAR_MSG = "Invalid character";
const string INVALID_INPUT_MSG = "Invalid input";
const string EMPTY_STRING_MSG = "Empty string";
const string FILE_FAIL_MSG = "Bad File or File Fail";

const string REPEAT_INPUT_MSG = "Please try again.";
const string RETRY_MSG = ", try again.";
const string PAUSE_MSG = "Press [ Enter ] to continue...";
const string EXIT_MSG = "Exit requested, closing the program.";

const string FILE_NAME_PROMPT = "Please enter a valid file name.";
const string FILE_INSTRUCTION_PROMPT =	"Enter '1' to create a data file \n"
										"Enter '2' to read data from a file and print checks \n"
										"Enter '3' to exit program.\n";
const string INVALID_FILE_NAME_PROMPT =	"The File name you entered was invalid.\n"
										"Enter '1' to try again \n"
										"Enter '2' to exit the program. \n";
enum BAD_FILE_NAME_USER_CHOICES { RETRY = 1, EXIT = 2};

int GetInputInt(string prompt)
{
	string temp = "";
	int number = 0;
	bool validInput = false;
	do
	{
		cin.clear();
		//Prompt the user to enter a value.
		cout << prompt;
		//place the value in string temp
		getline(cin, temp);

		try
		{
			number = StringToValidInt(temp);
			validInput = true;
		}
		catch (IOException& e)
		{
			//if there is an exception, print the error and repeat the prompt
			cout << e.GetMessage() << RETRY_MSG << endl;
			validInput = false;
		}

	} while (!validInput);//end while loop if the input is valid
	return number;
} // End GetInputInt(string prompt)


int StringToValidInt(string& numStr)
{
	int number = 0;
	//if the string is empty,
	if (numStr.empty()){
		string error = EMPTY_STRING_MSG;
		throw IOException(error, 0);
	}
	//check to see if CTRL-Z has been pressed
	else if (cin.eof())
	{
		string error = EOF_MSG;
		throw IOException(error, 0);
	}
	// Decimal point, '+' or '-' or any digit are all valid first characters
	else if ((numStr[0] == PLUS_SIGN) || (numStr[0] == MINUS_SIGN) || IsDigit(numStr[0]) || isspace(numStr[0]))
	{
		//check all the characters after the first for validity
		for (unsigned int i = 1; i < numStr.length(); i++)
		{
			//if the character is not a valid digit and is also not a decimal point
			//or there is more than one decimal point
			if (!IsDigit(numStr[i]))
			{
				//input is invalid
				string error = INVALID_INPUT_MSG;
				throw IOException(error, 0);
			}
		}
	}
	else
	{
		//input is invalid
		string error = INVALID_INPUT_MSG;
		throw IOException(error, 0);
	}

	//convert the validated numStr string to integer
	//return as integer
	number = atoi(numStr.c_str());
	return number;
}


double StringToValidDouble(string& numStr)
{
	double number = 0;
	int radixPointCount = 0;
	//if the string is empty,
	if (numStr.empty()){
		string error = EMPTY_STRING_MSG;
		throw IOException(error, 0);
	}
	//check to see if CTRL-Z has been pressed
	else if (cin.eof())
	{
		string error = EOF_MSG;
		throw IOException(error, 0);
	}
	// Decimal point, '+' or '-' or any digit are all valid first characters
	else if ((numStr[0] == PLUS_SIGN) || (numStr[0] == MINUS_SIGN) || (numStr[0] == DECIMAL_POINT) || IsDigit(numStr[0]) || isspace(numStr[0]))
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
				string error = INVALID_INPUT_MSG;
				error.append(1, numStr[i]);
				throw IOException(error, 0);
			}
		}
	}
	else
	{
		//First character is invalid for double
		string error = INVALID_INPUT_MSG;
		throw IOException(error, 0);
	}

	//convert the validated str string to floating point number
	//store as double
	number = atof(numStr.c_str());
	return number;
}

double StreamToValidDouble(ifstream& file)
{
	string temp = "";
	double number = 0;
	//get the line from the text file. (Just like with cin)
	getline(file, temp);

	//test if the file is at the end
	if (file.eof())
	{
		string error = EOF_MSG;
		throw FileException(error, 0);
		return 0.0;
	}
	//test if input is bad, or failed
	else if (file.bad() || file.fail())
	{
		string error = FILE_FAIL_MSG;
		throw FileException(error, 0);
	}

	number = StringToValidDouble(temp);
	return number;
} // End StreamToValidDouble()

int StreamToValidInt(ifstream& file)
{
	string temp = "";
	int number = 0;
	//get the line from the text file. (Just like with cin)
	getline(file, temp);

	//test if the file is at the end
	if (file.eof())
	{
		string error = EOF_MSG;
		throw FileException(error, 0);
	}
	//test if input is bad, or failed
	else if (file.bad() || file.fail())
	{
		string error = FILE_FAIL_MSG;
		throw FileException(error, 0);
	}
	//convert the validated temp string to integer
	//store as int
	number = StringToValidInt(temp);
	return number;
} // End StreamToValidInt()

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
	//disallow \ / < > | " : ? *
	string temp = "";
	cin.clear();
	//Prompt the user to enter a value.
	cout << prompt << endl;
	//place the value in string temp
	getline(cin, temp);

	//TODO validate the file name

	return temp;
}

ifstream GetValidReadFile()
{
	ifstream file;
	bool fileValid = false;
	do
	{
		// get a file name from the user 
		string fileName = GetInputFileName(FILE_NAME_PROMPT);
		//open the file
		file.open(fileName.c_str());
		//test the state of the stream to verify that the file name is valid
		if (file.bad() || file.fail())
		{
			//close the file, TODO is this needed?
			file.close();
			//Give the user the option to quit or try again
			BadFileNameChoice();
		}
		else
		{
			//if the file is valid and open, set fileValid to true.
			return file;
			fileValid = true;
		}
	} while (!fileValid);
	return file;
}


ofstream GetValidWriteFile()
{
	ofstream file;
	bool fileValid = false;
	do
	{
		// get a file name from the user 
		string fileName = GetInputFileName(FILE_NAME_PROMPT);
		//open the file
		file.open(fileName.c_str());
		//test the state of the stream to verify that the file name is valid
		if (file.bad() || file.fail())
		{
			//close the file, TODO is this needed?
			file.close();
			//Give the user the option to quit or try again
			BadFileNameChoice();
		}
		else
		{
			//if the file is valid and open, set fileValid to true.
			return file;
			fileValid = true;
		}
	} while (!fileValid);
	return file;
}


void BadFileNameChoice()
{
	//Give the user the option to quit or try again
	int choice = GetInputInt(INVALID_FILE_NAME_PROMPT);
	switch (choice)
	{
	case RETRY:
		//the user chose to try again.
		break;
	case EXIT:
		//The user chose to exit the program
		cout << EXIT_MSG << endl << endl;
		//pause before exiting
		Pause();
		exit(0);
		break;
	default:
		//the user chose a number other than 1 or 0
		//print error message
		cout << INVALID_NUMBER_MSG << endl << endl;
		break;
	}
}


void Pause(void)
{
	cout << endl << PAUSE_MSG << endl;
	cin.get();
}

