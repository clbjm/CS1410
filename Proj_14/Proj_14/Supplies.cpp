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
#include "Supplies.h"

const string DESTRUCTOR = " destructor.";
const string CONSTRUCTOR = " constructor.";
const string DEFAULT_CONSTRUCTOR = " default constructor.";
const string COPY_CONSTRUCTOR = " copy constructor.";

Supplies::Supplies(): Node()
{
	_supplyName = "";
	_supplyUnitMeasure = "";
	_quantity = 0;
	_reorderQuantity = 0;
	string classname = typeid(*this).name();
	//cout << classname << DEFAULT_CONSTRUCTOR << endl;
}

Supplies::Supplies(int quantity, string measure, string name, int reQuantity, int number) : Node(number)
{
	_supplyName = name;
	_supplyUnitMeasure = measure;
	_quantity = quantity;
	_reorderQuantity = reQuantity;
	string classname = typeid(*this).name();
	//cout << classname << CONSTRUCTOR << endl;
}

Supplies::~Supplies()
{
	string classname = typeid(*this).name();
	//cout << classname << DESTRUCTOR << endl;
}

unsigned int Supplies::GetQuantity() const
{
	return _quantity;
}

void Supplies::SetQuantity(unsigned int quantity)
{
	_quantity = quantity;
}

unsigned int Supplies::GetReorderQuantity() const
{
	return _reorderQuantity;
}

void Supplies::SetReorderQuantity(unsigned int reorderQuantity)
{
	_reorderQuantity = reorderQuantity;
}

string& Supplies::GetName()
{
	return _supplyName;
}

void Supplies::SetName(string& supplyName)
{
	_supplyName = supplyName;
}

const string& Supplies::GetSupplyUnitMeasure() const
{
	return _supplyUnitMeasure;
}

void Supplies::SetSupplyUnitMeasure(const string& supplyUnitMeasure)
{
	_supplyUnitMeasure = supplyUnitMeasure;
}

string Supplies::ToString(void)
{
	ostringstream outs;
	int number = Node::GetNumber();
	outs << number << " ";
	outs << _supplyName.c_str() << " ";
	outs << _supplyUnitMeasure.c_str() << " ";
	outs << _quantity << " ";
	outs << _reorderQuantity << endl;
	return outs.str();
}

Supplies& Supplies::operator =(Supplies& rho)
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

void Supplies::Copy(Supplies& supplies)
{
	_supplyName = supplies._supplyName;
	_supplyUnitMeasure = supplies._supplyUnitMeasure;
	_quantity = supplies._quantity;
	_reorderQuantity = supplies._reorderQuantity;
	Node::Copy(supplies);
}

Node* Supplies::Clone()
{
	Supplies* newNode = new Supplies(_quantity, _supplyUnitMeasure, _supplyName, _reorderQuantity , Node::GetNumber());
	return newNode;
}
