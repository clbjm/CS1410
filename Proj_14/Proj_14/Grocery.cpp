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
#include "Grocery.h"

const string DESTRUCTOR = " destructor.";
const string CONSTRUCTOR = " constructor.";
const string DEFAULT_CONSTRUCTOR = " default constructor.";
const string COPY_CONSTRUCTOR = " copy constructor.";

Grocery::Grocery(): Node()
{
	_itemName = "";
	_itemUnitMeasure = "";
	_numberUnits = 0;
	string classname = typeid(*this).name();
	//cout << classname << DEFAULT_CONSTRUCTOR << endl;
}

Grocery::Grocery( int numUnits, string unitMeasure, string name, int number) : Node(number)
{
	_itemName = name;
	_itemUnitMeasure = unitMeasure;
	_numberUnits = numUnits;
	string classname = typeid(*this).name();
	//cout << classname << CONSTRUCTOR << endl;
}

Grocery::~Grocery()
{
	//free up all the dynamically allocated memory.
	//Free();
	string classname = typeid(*this).name();
	//cout << classname << DESTRUCTOR << endl;
}

string& Grocery::GetName()
{
	return _itemName;
}

void Grocery::SetName(string& itemName)
{
	_itemName = itemName;
}

const string& Grocery::GetItemUnitMeasure() const
{
	return _itemUnitMeasure;
}

void Grocery::SetItemUnitMeasure(const string& itemUnitMeasure)
{
	_itemUnitMeasure = itemUnitMeasure;
}

unsigned int Grocery::GetNumberUnits() const
{
	return _numberUnits;
}

void Grocery::SetNumberUnits(unsigned int numberUnits)
{
	_numberUnits = numberUnits;
}

string Grocery::ToString(void)
{
	ostringstream outs;
	int number = Node::GetNumber();
	outs << number << " ";
	outs << _itemName.c_str() << " ";
	outs << _itemUnitMeasure.c_str() << " ";
	outs << _numberUnits << endl;
	return outs.str();
}

Grocery& Grocery::operator = (Grocery& rho)
{
	// check to see if this object is equal to the right hand object
	if (this != &rho)
	{
		//copy everything (including the dynamically allocated memory) in the rho object
		Copy(rho);
	}
	//Return a reference to this object.
	return *this;
}

void Grocery::Copy(Grocery& grocery)
{
	_itemName = grocery._itemName;
	_itemUnitMeasure = grocery._itemUnitMeasure;
	_numberUnits = grocery._numberUnits;
	Node::Copy(grocery);
}

Node* Grocery::Clone()
{
	Grocery* newNode = new Grocery(_numberUnits, _itemUnitMeasure, _itemName, Node::GetNumber());
	return newNode;
}

