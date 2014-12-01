//============================================================================
// Name:		Proj_05.cpp
// Purpose:		Test the employee and exception classes
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

#include "Proj_05.h"
#include "Employee.h"

const int EMPLOYEE_NUMBERS[] = { 37, 21, 15 };
const string EMPLOYEE_NAMES[] = { "Joe Brown", "Sam Jones", "Mary Smith" };
const string EMPLOYEE_ADDRESSES[] = { "123 Main St", "45 East State", "12 High Street" };
const string EMPLOYEE_PHONE_NUMBERS[] = { "123-6788", "661-9000", "401-8900" };
const double EMPLOYEE_HOURS[] = { 45.0, 30.0, 40.0 };
const double EMPLOYEE_WAGES[] = { 10.0, 12.0, 15.0 };

//enum CSV_ORDER { EMP_NUMBER, EMP_NAME, EMP_ADDRESS, EMP_PH_NUMBER, EMP_HOURS, EMP_WAGE };
enum EMPLOYEES { JOE, SAM, MARY };
enum USER_CHOICES { WRITE_EMPLOYEE_FILE = 1, READ_EMPLOYEE_FILE = 2, EXIT = 3 };

const string FILE_CREATION_DONE_MSG = "File creation is complete.";
const string EXIT_MSG = "Closing the program.";
const string INVALID_NUMBER_MSG = "The number you entered was invalid.\n";
const string REPEAT_INPUT_MSG = "Please try again.";

const string INSTRUCTION_MSG =	"Enter '1' to create a data file \n"
								"Enter '2' to read data from a file and print checks \n"
								"Enter '3' to exit program.\n";


// The main method
// Purpose: Entry point to the program
// Parameters: None
// Returns: 0
int main()
{
	bool success = false;
	do
	{
		success = TestEmployee();
	} 
	while (!success);//repeat if failed
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
			//Presents the user with a menu of three choices : 1. Create a data file, 2. Read data from a file and print checks and 3) Exit program.
			choice = GetInputInt(INSTRUCTION_MSG);
			valid = true;
		}
		catch (IOException& e)
		{
			cout << e.GetMessage() << endl;
			cout << REPEAT_INPUT_MSG << endl << endl;
		}
	} 
	while (!valid);


	switch (choice)
	{
		case WRITE_EMPLOYEE_FILE:
			{
				// If the user selects the first option, your program should
				// Create three employee objects
				Employee joe(EMPLOYEE_NUMBERS[JOE], EMPLOYEE_NAMES[JOE], EMPLOYEE_ADDRESSES[JOE],
					EMPLOYEE_PHONE_NUMBERS[JOE], EMPLOYEE_HOURS[JOE], EMPLOYEE_WAGES[JOE]);
				Employee sam(EMPLOYEE_NUMBERS[SAM], EMPLOYEE_NAMES[SAM], EMPLOYEE_ADDRESSES[SAM],
					EMPLOYEE_PHONE_NUMBERS[SAM], EMPLOYEE_HOURS[SAM], EMPLOYEE_WAGES[SAM]);
				Employee mary(EMPLOYEE_NUMBERS[MARY], EMPLOYEE_NAMES[MARY], EMPLOYEE_ADDRESSES[MARY],
					EMPLOYEE_PHONE_NUMBERS[MARY], EMPLOYEE_HOURS[MARY], EMPLOYEE_WAGES[MARY]);

				// Ask the user for a filename, return a valid corresponding file, repeat if needed.
				ofstream outFile = GetValidWriteFile();

				// Send messages to each of the three Employee objects to write themselves out to the file.
				joe.WriteData(outFile);
				sam.WriteData(outFile);
				mary.WriteData(outFile);
				// Close the file.
				outFile.close();
				// Print an message that the file creation is complete.
				cout << FILE_CREATION_DONE_MSG << endl << endl;
			}
			break;
		case READ_EMPLOYEE_FILE:
			{
				// If the user selects the second option, your program should
				// Create three new Employee objects, using the default Employee constructor.
				Employee emp1;
				Employee emp2;
				Employee emp3;

				//Ask the user for a filename, return a corresponding file
				ifstream inFile = GetValidReadFile();

				//read data from the file into the objects
				//check for errors in the file
				try
				{
					// Have each object read itself in from the file.
					emp1.ReadData(inFile);
					emp2.ReadData(inFile);
					emp3.ReadData(inFile);
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
				PrintCheck(emp1);
				//Pause
				Pause();
				system("CLS");
				PrintCheck(emp2);
				//Pause
				Pause();
				system("CLS");
				PrintCheck(emp3);
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