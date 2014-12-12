//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Proj_14
// Purpose: Linked Lists
// Date: December 2014
// Date: 12/09/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------
#ifndef GROCERY_H_
#define GROCERY_H_

#include "Llist.h"

/*
 *
 */
class Grocery: public Node
{

	private:
		string _itemName;
		string _itemUnitMeasure;
		unsigned int _numberUnits;
	public:

		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		Grocery();

		///----------------- Constructor -----------------------
		/// Purpose: To construct a Grocery object with the provided parameters
		/// Parameters: string for name, string for unit of measure,
		///				int for quantity,  int for number
		///-------------------------- End ------------------------------
		Grocery(int, string, string, int);


		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		~Grocery();

		///-------------------- Getter Function---------------------
		/// Purpose: To Get the item name
		/// Returns: string reference to item name
		///---------------------------End-------------------------------
		string& GetName();

		///-------------------- Setter Function---------------------
		/// Purpose: To set the item name
		/// Parameters: string reference for item name
		/// Returns: none
		///---------------------------End-------------------------------
		void SetName(string& itemName);

		///-------------------- Getter Function---------------------
		/// Purpose: To Get the item unit of measure
		/// Returns: string reference to item unit of measure
		///---------------------------End-------------------------------
		const string& GetItemUnitMeasure() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the items unit of measure
		/// Parameters: string reference for unit of measure
		/// Returns: none
		///---------------------------End-------------------------------
		void SetItemUnitMeasure(const string& itemUnitMeasure);

		///-------------------- Getter Function---------------------
		/// Purpose: To Get the number of units
		/// Returns: integer number of units
		///---------------------------End-------------------------------
		unsigned int GetNumberUnits() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the number of units
		/// Parameters: int number of units
		/// Returns: none
		///---------------------------End-------------------------------
		void SetNumberUnits(unsigned int numberUnits);

		///-------------------- ToString function---------------------
		/// Purpose: returns the values of all member data of the Grocery as a string
		/// Parameters: none
		/// Returns: string containing the member data
		///---------------------------End-------------------------------
		string ToString(void);

		///--------------------assignment operator overloading Function--------------------
		/// Purpose: overloads the assignment operator
		/// Parameters: reference to a Grocery object
		/// Returns: reference to a Grocery object
		///---------------------------End--------------------------------------------------
		Grocery& operator = (Grocery&);

		///--------------------Copy Function-------------------------------------------------
		/// Purpose: Copies the object
		/// Parameters: Reference to a Node object
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Copy(Grocery&);

};

#endif /* GROCERY_H_ */
