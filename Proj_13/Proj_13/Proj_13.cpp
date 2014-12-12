//============================================================================
// Name:		Proj_13.h
// Purpose:		Test Employee Inheritance
// Version:		1.0
// Author:		Kevin S. O'Day
// Course:		CS 1410 Section 002
// Instructor:	Dennis Fairclough
// Project:		Proj_13
// Date:		November 2014
// Date:		11/26/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------------

#include "Proj_13.h"

const double FEDERAL_RATE = 0.2;
const double STATE_RATE = 0.075;
const double WORK_WEEK = 40.0;
const double OVERTIME_RATE = 1.5;

enum OPTIONS{ CREATE = 'C', OPEN = 'O', SAVE = 'S', RESTORE = 'R', SEEK = 'E', PRINT = 'P', EXIT = 'Q' };
enum SEEK_MODE{BEGINNING = 0, END = 1};
const string FILE_CREATION_DONE_MSG = "File creation is complete.";
const string FILE_OPEN_DONE_MSG = "File opening is complete.";

const string INSTRUCTION_MSG =	"Select one of the following menu items \n\n"
								"C)reate a new database file. \n"
								"O)pen an existing database file. \n"
								"Q)uit program. \n\n"
								"Selected menu item: ";

const string INSTRUCTION_MSG2 = "Select one of the following menu items \n\n"
								"S)ave database. \n"
								"R)estore database. \n"
								"Q)uit program. \n\n"
								"Selected menu item: ";

const string INSTRUCTION_MSG3 = "Select one of the following menu items \n\n"
								"sE)ek to the beginning of the database. \n"
								"Q)uit program. \n\n"
								"Selected menu item: ";

const string INSTRUCTION_MSG4 = "Select one of the following menu items \n\n"
								"P)rint employee paychecks. \n"
								"Q)uit program. \n\n"
								"Selected menu item: ";

const string INVALID_INPUT_MSG = "\nYou entered an invalid character, try again.";
const string INVALID_FILE_DATA_MSG = "\nunexpected data in file, program is terminating...";
const string FILE_CREATION_MSG = "\nThe file has been created.";
const string FILE_SEEK_DONE_MSG = "\nThe pointer is returned to the start of the file.";
const string EXIT_MSG = "\nExiting...";
const string PRINT_FINISH_MSG = "\nFinished printing checks, restarting...";

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


void TestEmployee()
{
	bool valid = false;
	//system("CLS");
	FileIO* fileIO = new FileIO();
	MenuOne(fileIO);


}//end TestEmployee()

void MenuOne(FileIO* fileIO)
{
	int choice;
	do
	{
		system("CLS");
		cin.clear();
		//Prompt the user to enter a character.
		choice = GetInputChar(INSTRUCTION_MSG);
		switch (choice)
		{
			case CREATE:
			{
				// get a filename from the user
				string filename = GetInputFileName();
				//If file exists it opens and truncates it, else creates new file
				try
				{
					bool status = fileIO->OpenDB(filename, 1);
					// Print an message that the file creation is complete.
					cout << FILE_CREATION_DONE_MSG << endl << endl;
				}
				catch (FileException& e)
				{
					cout << e.GetMessage() << endl;
				}
			}
				//display the second menu
				MenuTwo(fileIO);
				cout << EXIT_MSG << endl << endl;
				Pause();
				break;
			case OPEN:
			{
				// If the user selects the second option, your program should
				// get a filename from the user
				string filename = GetInputFileName();
				//try to open the file
				try
				{
					//Open an existing file
					fileIO->OpenDB(filename, 0);
					//Position the file pointer at the front of the file
					fileIO->SeekDB(BEGINNING);
					// Print an message that the file is open
					cout << FILE_OPEN_DONE_MSG << endl << endl;
				}
				catch (FileException& e)
				{
					cout << e.GetMessage() << endl;
				}
			}
				//display the second menu
				MenuTwo(fileIO);
				break;
			case EXIT:
				//close the open database.
				fileIO->CloseDB();
				//delete the FileIO object
				delete fileIO;
				fileIO = NULL;
				//print exit message
				cout << EXIT_MSG << endl << endl;
				Pause();
				//exit the program
				exit(0);
				break;
			default:
				//print error message
				cout << INVALID_INPUT_MSG << endl << endl;
				Pause();
				// start over
				break;
		}
	} while (true);
}

void MenuTwo(FileIO* fileIO)
{
	bool valid = false;
	int choice;
	do
	{
		system("CLS");
		cin.clear();
		//Prompt the user to enter a character.
		choice = GetInputChar(INSTRUCTION_MSG2);
		switch (choice)
		{
			case SAVE:
			{
				//
				Employee* h1 = new Hourly(1, "Harry Potter", "Privet Drive", "304-201-9090", 40.00, 12.00);
				Employee* s1 = new Salary(2, "Albert Dumbledore", "Hogewarts", "404-803-1230", 1200.50);
				Employee* sa1 = new Sales(4, "Rotten Hagrid", "Hogwarts", "505-910-8765", 1000, 0.09, 100000.00);
				Employee* h2 = new Hourly(3, "Rogue Weasley", "The Burrow", "304-892-2000", 45.50, 10.00);
				Employee* s2 = new Salary(4, "Rotten Hagrid", "Hogwarts", "601-910-8765", 1000.00);
				Employee* h3 = new Hourly(1, "Doc Dwarf", "Tree Root Drive", "505-301-9090", 40.00, 14.00);
				Employee* sa2 = new Sales(4, "Sleepy Dwarf", "Hogwarts", "505-910-8765", 1500.00, 0.07, 150000.00);
				Employee* s3 = new Salary(2, "Happy Dwarf", "Hogewarts", "505-803-1230", 1200);
				Employee* h4 = new Hourly(3, "Grumpy Dwarf", "Tree Limb Drive", "505-892-2000", 50.75, 10.00);
				//Sales sa3(4, "Dopey Dwarf", "Hogwarts", "910-8765", 1000); //these parameters don't match the type

				//Create a vector for employee pointers and add all the employees to it
				MyVector<Employee*> employeeDB;
				employeeDB.Push_Back(h1);
				employeeDB.Push_Back(s1);
				employeeDB.Push_Back(sa1);
				employeeDB.Push_Back(h2);
				employeeDB.Push_Back(s2);
				employeeDB.Push_Back(h3);
				employeeDB.Push_Back(sa2);
				employeeDB.Push_Back(s3);
				employeeDB.Push_Back(h4);

				//The four Hourly, three Salary and two Sales employee objects listed above will be written to the file
				try
				{
					for (int i = 0; i < employeeDB.Size(); i++)
					{
						fileIO->WriteDB(employeeDB[i]);
					}
					//the file pointer will be moved to the front of the file.
					//Position the file pointer at the front of the file
					fileIO->SeekDB(BEGINNING);
				}
				catch (FileException& e)
				{
					cout << e.GetMessage() << endl;
				}
				// Print an message that the file creation is complete.
				cout << FILE_CREATION_DONE_MSG << endl << endl;
			}
				MenuThree(fileIO);
				valid = true;
				break;
			case RESTORE:
			{
				// If the user selects the second option, your program should
				//create a vector of employee pointers
				MyVector<Employee*> employeeDB;
				// the file should already be open
				try
				{
					//restore the objects from the file
					//Position the file pointer at the front of the file
					//fileIO->SeekDB(BEGINNING);

					string type;
					int count = 0;
					// Have each object read itself in from the file.
					bool more = true;
					do
					{
						Employee* ePtr = NULL;
						more = fileIO->ReadDB(ePtr);
						//add the employee pointer to the vector
						if (more) employeeDB.Push_Back(ePtr);
					} while (more);
				}
				catch (FileException& e)
				{
					cout << e.GetMessage() << endl;
				}
				//option to print database
				MenuFour(fileIO, &employeeDB);
			}
				valid = true;
				break;
			case EXIT:
				//close the open database.
				fileIO->CloseDB();
				//delete the FileIO object
				delete fileIO;
				fileIO = NULL;
				//print exit message
				cout << EXIT_MSG << endl << endl;
				exit(0);
				break;
			default:
				//print error message
				cout << INVALID_INPUT_MSG << endl << endl;
				Pause();
				// start over
				valid = false;
				break;
		}
	} while (!valid);
}

void MenuThree(FileIO* fileIO)
{
	bool valid = false;
	int choice;
	do
	{
		system("CLS");
		cin.clear();
		//Prompt the user to enter a character.
		choice = GetInputChar(INSTRUCTION_MSG3);
		switch (choice)
		{
			case SEEK:
			{
				//“Will seek the proper file pointer in the open file.”
				try
				{
					//Position the file pointer at the front of the file
					fileIO->SeekDB(BEGINNING);
					cout << FILE_SEEK_DONE_MSG << endl << endl;
				}
				catch (FileException& e)
				{
					cout << e.GetMessage() << endl;
				}
			}
				valid = true;
				break;
			case EXIT:
				//close the open database.
				fileIO->CloseDB();
				//delete the FileIO object
				delete fileIO;
				fileIO = NULL;
				//print exit message
				cout << EXIT_MSG << endl << endl;
				Pause();
				//exit the program
				exit(0);
				break;
			default:
				//print error message
				cout << INVALID_INPUT_MSG << endl << endl;
				Pause();
				// start over
				valid = false;
				break;
		}
	} while (!valid);
}

void MenuFour(FileIO* fileIO, MyVector<Employee*>* employeeDB)
{
	bool valid = false;
	int choice;
	do
	{
		system("CLS");
		cin.clear();
		//Prompt the user to enter a character.
		choice = GetInputChar(INSTRUCTION_MSG4);
		cout << (char)choice << endl;
		switch (choice)
		{
			case PRINT:
			{
				//Print employee checks
				try
				{
					// If the user selects the print option, your program should
					//Position the file pointer at the front of the file
					// Call the PrintCheck() function for each of the new objects.
					for (int i = 0; i < employeeDB->Size(); i++)
					{
						system("CLS");
						Employee* ePtr = employeeDB->ValueAt(i);
						ePtr->PrintCheck();
						//Pause
						Pause();
					}

					// delete the objects and clear the array
					employeeDB->Clear();

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
				//TODO return to the main menu when finished
			}
				valid = true;
				cout << PRINT_FINISH_MSG << endl << endl;
				Pause();
				break;
			case EXIT:
				//close the open database.
				fileIO->CloseDB();
				//delete the FileIO object
				delete fileIO;
				fileIO = NULL;
				//print exit message
				cout << EXIT_MSG << endl << endl;
				Pause();
				//exit the program
				exit(0);
				break;
			default:
				//print error message
				cout << INVALID_INPUT_MSG << endl << endl;
				Pause();
				// start over
				valid = false;
				break;
		}
	} while (!valid);
}
