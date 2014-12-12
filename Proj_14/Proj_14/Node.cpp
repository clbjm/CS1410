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
#ifndef NODE_H_
#define NODE_H_

#include "Llist.h"

const string DESTRUCTOR = " destructor.";
const string CONSTRUCTOR = " constructor.";
const string DEFAULT_CONSTRUCTOR = " default constructor.";
const string COPY_CONSTRUCTOR = " copy constructor.";

//---------------------------------------- - Node implementation------------------------------------------ -

Node::Node()
{
	_nextNode = NULL;
	_prevNode = NULL;
	_number = 0;
	string classname = typeid(*this).name();
	cout << classname << DEFAULT_CONSTRUCTOR << endl;
}

Node::Node(Node&)
{
	//Copy constructor
}

Node::Node(int number)
{
	_nextNode = NULL;
	_prevNode = NULL;
	_number = number;
	string classname = typeid(*this).name();
	cout << classname << CONSTRUCTOR << endl;
}

Node::~Node()
{
	string classname = typeid(*this).name();
	cout << classname << DESTRUCTOR << endl;
}

Node* Node::GetNextNode() const
{
	return _nextNode;
}

void Node::SetNextNode(Node* nextPtr)
{
	_nextNode = nextPtr;
}

Node* Node::GetPrevNode() const
{
	return _prevNode;
}

void Node::SetPrevNode(Node* prevPtr)
{
	_prevNode = prevPtr;
}

int Node::GetNumber() const
{
	return _number;
}

void Node::SetNumber(int number)
{
	_number = number;
}

void Node::Copy(Node& node)
{
	_nextNode = node._nextNode;
	_prevNode = node._prevNode;
	_number = node._number;
}

//-----------------------------------------End Node implementation-------------------------------------------

#endif /* NODE_H_ */