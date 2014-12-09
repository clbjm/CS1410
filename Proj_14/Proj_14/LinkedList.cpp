//============================================================================
// Project Prolog
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

#include "LinkedList.h"

//-----------------------------------------Node implementation-------------------------------------------

Node::Node()
{
		_nextNode = NULL;
		_prevNode = NULL;
		_number = 0;
		_description = "";
		_unitOfMeasure = "";

}

Node::Node(Node&)
{

}

Node::Node(int number, string description, string unitOfMeasure)
{
	_nextNode = NULL;
	_prevNode = NULL;
	_number = number;
	_description = description;
	_unitOfMeasure = unitOfMeasure;
}

Node::~Node()
{
}

const string& Node::GetDescription() const
{
	return _description;
}

void Node::SetDescription(const string& description)
{
}

const Node*& Node::GetNextNode() const
{
	return _nextNode;
}

void Node::SetNextNode(const Node*& nextPtr)
{
	_nextNode = nextPtr;
}

const Node*& Node::GetPrevNode() const
{
	return _prevNode;
}

void Node::SetPrevNode(const Node*& prevPtr)
{
	_prevNode = prevPtr;
}

int Node::GetNumber() const
{
	return _number;
}

void Node::SetNumber(int number)
{
}

const string& Node::GetUnitOfMeasure() const
{
	return _unitOfMeasure;
}

void Node::SetUnitOfMeasure(const string& unitOfMeasure)
{
}





//-----------------------------------------List implementation-------------------------------------------

List::List()
{
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = 0;
}

List::List(List&)
{
}

List::List(int nodeCount)
{
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = nodeCount;
}

List::~List()
{
}

Node* List::GetFirst(void)
{
	return _headNode;
}

Node* List::GetLast(void)
{
	return _endNode;
}

void List::Push_Front(Node*)
{
}

void List::Pop_Front(void)
{
}

void List::Push_End(Node*)
{
}

void List::Pop_End(void)
{
}

Node* List::FindNode(int int1)
{
}

void List::AddNode(Node&, int int1)
{
}

Node* List::RemoveNode(int int1)
{
}

void List::ClearList(void)
{
}

void List::DisplayList(void)
{
}

List& List::operator = (List&)
{
}

List* List::operator = (List*)
{
}


