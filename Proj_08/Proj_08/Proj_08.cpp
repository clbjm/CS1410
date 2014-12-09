//============================================================================
// Name:		Proj_08.h
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

#include "Proj_08.h"

const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double WORK_WEEK = 40.0;
const double OVERTIME_RATE = 1.5;

enum OPTIONS{ WRITE_FILE = 1, READ_FILE = 2, EXIT = 3 };
enum ORDER{ EMP_NUM = 0, NAME = 1, ADDRESS = 2, PHN_NUM = 3, HOURS = 4, WAGE = 5 };

const int EMPLOYEE_NUMBERS[] =			{ 1, 2, 3, 4};
const string EMPLOYEE_NAMES[] =			{ "H. Potter", "A. Dumbledore", "R. Weasley", "R. Hagrid" };
const string EMPLOYEE_ADDRESSES[] =		{ "Privet Drive", "Hogewarts", "The Burrow", "Hogwarts" };
const string EMPLOYEE_PHONE_NUMBERS[] = { "201-9090", "803-1230", "892-2000", "910-8765" };
const double EMPLOYEE_HOURS[] =			{ 40.0, 0, 40.0, 0};
const double EMPLOYEE_WAGES[] =			{ 12.00, 1200.00, 10.00, 1000 };


const string CHECK_TITLE = "---------------------FluffShuffle Electronics------------------------";
const string PAY_TO = "Pay to the order of ";
const string AMOUNT_SPACE = "...........$";
const string BANK_NAME = "United Bank of East Orem";
const string CHECK_LINE = "----------------------------------------------------------------------";
const string HOURS_WORKED = "Hours Worked: ";
const string HOURLY_WAGE = "Hourly Wage:  ";

const char COMMA_DELIMITER = ',';

const string FILE_CREATION_DONE_MSG = "File creation is complete.";
const string INVALID_NUMBER_MSG = "The number you entered was invalid.\n";

const string INSTRUCTION_MSG =	"This program has 3 options: \n"
								"Enter '1' to create a data file, or \n"
								"Enter '2' to read data from a file and print checks, or \n"
								"Enter '3' to exit program: ";
const string INVALID_INPUT_MSG = "You entered an invalid number, try again.";
const string FILE_CREATION_MSG = "The file has been created.";
const string EXIT_MSG = "Exiting...";
const string REPEAT_INPUT_MSG = "Please try again.";

// The main method
// Purpose: Entry point to the program
// Parameters: None
// Returns: 0
int main()
{
	TestEmployee();
	//Pause
	Pause();
	return 0;
}//End main()


bool TestEmployee()
{
	int choice = 0;
	bool valid = false;
	system("CLS");
	do
	{
		try
		{
			//Presents the user with a menu of three choices : 
			//1. Create a data file, 
			//2. Read data from a file and print checks and 
			//3. Exit program.
			choice = GetInputInt(INSTRUCTION_MSG);
			valid = true;
		}
		catch (IOException& e)
		{
			cout << e.GetMessage() << endl;
			cout << REPEAT_INPUT_MSG << endl << endl;
		}
	} while (!valid);


	switch (choice)
	{
		case WRITE_FILE:
			{
				//Option 1, Create 4 employee objects
				HourlyEmployee h1(EMPLOYEE_NUMBERS[0], EMPLOYEE_NAMES[0], EMPLOYEE_ADDRESSES[0],
					EMPLOYEE_PHONE_NUMBERS[0], EMPLOYEE_HOURS[0], EMPLOYEE_WAGES[0]);
				HourlyEmployee h2(EMPLOYEE_NUMBERS[2], EMPLOYEE_NAMES[2], EMPLOYEE_ADDRESSES[2],
					EMPLOYEE_PHONE_NUMBERS[2], EMPLOYEE_HOURS[2], EMPLOYEE_WAGES[2]);

				SalaryEmployee s1(EMPLOYEE_NUMBERS[1], EMPLOYEE_NAMES[1], EMPLOYEE_ADDRESSES[1],
					EMPLOYEE_PHONE_NUMBERS[1], EMPLOYEE_WAGES[1]);
				SalaryEmployee s2(EMPLOYEE_NUMBERS[3], EMPLOYEE_NAMES[3], EMPLOYEE_ADDRESSES[3],
					EMPLOYEE_PHONE_NUMBERS[3], EMPLOYEE_WAGES[3]);

				//Get a filename from the user, open the file, repeat if invalid.
				ofstream outFile = GetValidWriteFile();

				// Send messages to each of the four Employee objects to write themselves out to the file.
				h1.WriteData(outFile);
				h2.WriteData(outFile);
				s1.WriteData(outFile);
				s2.WriteData(outFile);

				// Close the file.
				outFile.close();
				// Print an message that the file creation is complete.
				cout << FILE_CREATION_DONE_MSG << endl << endl;
			}
			break;
		case READ_FILE:
			{
				// If the user selects the second option, your program should
				// Create four new Employee objects, using the default Employee constructor.
				HourlyEmployee h1;
				HourlyEmployee h2;
				SalaryEmployee s1;
				SalaryEmployee s2;

				//Ask the user for a filename, return a corresponding file
				ifstream inFile = GetValidReadFile();

				//read data from the file into the objects
				//check for errors in the file
				try
				{
					// Have each object read itself in from the file.
					h1.ReadData(inFile);
					h2.ReadData(inFile);
					s1.ReadData(inFile);
					s2.ReadData(inFile);
				}
				catch (FileException& e)
				{
					//print a message if there is an error in the file
					cout << e.GetMessage() << endl;
					cout << EXIT_MSG << endl << endl;
					Pause();
					// terminate the program
					exit(0);
				}

				// Call the PrintCheck() function for each of the three new objects, just as you did in the previous project.
				system("CLS");
				h1.PrintCheck();
				//Pause
				Pause();
				system("CLS");
				s1.PrintCheck();
				//Pause
				Pause();
				system("CLS");
				h2.PrintCheck();
				//Pause
				Pause();
				system("CLS");
				s2.PrintCheck();

				//close the file
				inFile.close();
			}
			break;
		case EXIT:
			//print exit message
			cout << EXIT_MSG << endl << endl;
			break;
		default:
			//print error message
			cout << INVALID_NUMBER_MSG << endl << endl;
			Pause();
			// start over
			return false;
			break;
	}
	return true;
}//end TestEmployee()