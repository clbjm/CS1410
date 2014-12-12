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
#ifndef SUPPLIES_H_
#define SUPPLIES_H_

#include "Llist.h"

class Supplies: public Node
{
	private:
		string _supplyName;
		string _supplyUnitMeasure;
		unsigned int _quantity;
		unsigned int _reorderQuantity;

	public:
		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		Supplies();

		///----------------- Constructor -----------------------
		/// Purpose: To construct a Supplies object with the provided parameters
		/// Parameters: string for name, string for unit of measure, int for quantity,
		///				int for reorder quantity, int for number
		///-------------------------- End ------------------------------
		Supplies(int, string, string, int, int);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~Supplies();

		//-------------------- Getter Function---------------------
		/// Purpose: To get the quantity
		/// Returns: integer quantity
		///---------------------------End-------------------------------
		unsigned int GetQuantity() const;

		///-------------------- Setter Function---------------------
		/// Purpose: set the quantity
		/// Parameters: integer quantity
		/// Returns: none
		///---------------------------End-------------------------------
		void SetQuantity(unsigned int quantity);

		///-------------------- Getter Function---------------------
		/// Purpose: To get the quantity
		/// Returns: integer quantity
		///---------------------------End-------------------------------
		unsigned int GetReorderQuantity() const;

		///-------------------- Setter Function---------------------
		/// Purpose: set the reorder quantity
		/// Parameters: integer reorder quantity
		/// Returns: none
		///---------------------------End-------------------------------
		void SetReorderQuantity(unsigned int reorderQuantity);

		///-------------------- Getter Function---------------------
		/// Purpose: To Get the item name
		/// Returns: string reference to item name
		///---------------------------End-------------------------------
		string& GetName();

		///-------------------- Setter Function---------------------
		/// Purpose: set the supply name
		/// Parameters: string reference to supply name
		/// Returns: none
		///---------------------------End-------------------------------
		void SetName(string& supplyName);

		///-------------------- Getter Function---------------------
		/// Purpose: To get the quantity
		/// Returns: integer quantity
		///---------------------------End-------------------------------
		const string& GetSupplyUnitMeasure() const;

		///-------------------- Setter Function---------------------
		/// Purpose: set the unit of measure
		/// Parameters:  string reference to unit of measure
		/// Returns: none
		///---------------------------End-------------------------------
		void SetSupplyUnitMeasure(const string& supplyUnitMeasure);

		///-------------------- ToString function---------------------
		/// Purpose: returns the values of all member data of the Supplies as a string
		/// Parameters: none
		/// Returns: string containing the member data
		///---------------------------End-------------------------------
		string ToString(void);

		///--------------------assignment operator overloading Function--------------------
		/// Purpose: overloads the assignment operator
		/// Parameters: reference to a Supplies object
		/// Returns: reference to a Supplies object
		///---------------------------End--------------------------------------------------
		Supplies& operator = (Supplies&);

		///--------------------Copy Function-------------------------------------------------
		/// Purpose: Copies the object
		/// Parameters: Reference to a Supplies object
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Copy(Supplies&);

		///----------------- Clone function -----------------------
		/// Purpose: Clone node object
		/// Returns: Copied node object
		///-------------------------- End ------------------------------
		Node* Clone();

};

#endif /* SUPPLIES_H_ */
