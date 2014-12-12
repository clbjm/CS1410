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

#include "Llist.h"

const string DESTRUCTOR = " destructor.";
const string CONSTRUCTOR = " constructor.";
const string DEFAULT_CONSTRUCTOR = " default constructor.";
const string COPY_CONSTRUCTOR = " copy constructor.";

//-----------------------------------------Llist implementation-------------------------------------------

Llist::Llist()
{
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = 0;
	string classname = typeid(*this).name();
	cout << classname << DEFAULT_CONSTRUCTOR << endl;
}

Llist::Llist(Llist& lst)
{
	//--- Test for empty list ------------
	if (lst._headNode == NULL)
		return;

	// check to see if this object is equal to the right hand object
	if (this != &lst)
	{
		ClearList();
		Node* oldNode = lst.GetFirst();
		//clone the old head node
		_headNode = oldNode->Clone();
		//get the next old node
		oldNode = oldNode->GetNextNode();
		//clone the next old node
		Node* newNode = oldNode->Clone();
		//set Next Node for head node
		_headNode->SetNextNode(newNode);
		//set prev node for next node to the new _headNode
		newNode->SetPrevNode(_headNode);
		//get the pointer to the next node in the old list
		oldNode = oldNode->GetNextNode();
		while (oldNode != NULL)
		{
			//clone the old Node
			Node* nextNode = oldNode->Clone();
			//set the next node of newNode
			newNode->SetNextNode(nextNode);
			//set the prev node of nextNode to newNode
			nextNode->SetPrevNode(newNode);
			//point newNode to nextNode						//TODO check this
			newNode = nextNode;
			//get the pointer to the next node in the old list
			oldNode = oldNode->GetNextNode();
		}
		_endNode = newNode;
		_nodeCount = lst.GetCount();
	}
	//print out the copy constructor message
	string classname = typeid(*this).name();
	cout << classname << COPY_CONSTRUCTOR << endl;
}

Llist::Llist(int nodeCount)
{
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = nodeCount;
	string classname = typeid(*this).name();
	//cout << classname << CONSTRUCTOR << endl;
}

Llist::~Llist()
{
	string classname = typeid(*this).name();
	//cout << classname << DESTRUCTOR << endl;
}

Node* Llist::GetFirst(void)
{
	return _headNode;
}

Node* Llist::GetLast(void)
{
	return _endNode;
}

unsigned int Llist::GetCount(void)
{
	return _nodeCount;
}

void Llist::SetLast(Node* endNode)
{
	endNode->SetNextNode(NULL);
	_endNode = endNode;
}

void Llist::SetFirst(Node* headNode)
{
	headNode->SetPrevNode(NULL);
	_headNode = headNode;
}

void Llist::SetCount(unsigned int nodeCount)
{
	_nodeCount = nodeCount;
}

void Llist::Push_Front(Node* nPtr)
{
	if (_headNode == NULL)
	{
		_headNode = nPtr;
		_endNode = nPtr;
	}
	else
	{
		nPtr->SetNextNode(_headNode);//the new nextNode is the old headNode
		_headNode->SetPrevNode(nPtr);//prevNode of the old headNode is the new node
		_headNode = nPtr;//the new headNode is the new node
	}
	_nodeCount++;
}

void Llist::Push_End(Node* nPtr)
{
	if (_endNode == NULL && _headNode == NULL)
	{
		_endNode = nPtr;
		_headNode = nPtr;
	}
	else
	{
		_endNode->SetNextNode(nPtr);// the new node is the old endNodes next node
		nPtr->SetPrevNode(_endNode);// the prevNode of the new node is the old endNode
		_endNode = nPtr;//the new endNode is the new node
		_endNode->SetNextNode(NULL);//there should be no nextNode in endNode
	}
	_nodeCount++;
}


Node* Llist::Pop_Front(void)
{
	Node* out;
	if (_headNode == NULL)
	{
		//_headNode = nPtr;
		//_endNode = nPtr;
		return NULL;
	}
	else
	{
		out = _headNode;
		//remove the first node from the list,
		_headNode = _headNode->GetNextNode();
		_nodeCount--;
	}
	//return a pointer to this Node.
	return out;
	//do not delete the Node in this function.
	//Simply unlink and return it from the list.
}


Node* Llist::Pop_End(void)
{
	Node* out;
	if (_endNode == NULL)
	{
		//_headNode = nPtr;
		//_endNode = nPtr;
		return NULL;
	}
	else
	{
		out = _endNode;
		//remove the last node from the list,
		_endNode = _endNode->GetPrevNode();
		_endNode->SetNextNode(NULL);
		_nodeCount--;
		//return a pointer to this Node.
	}
	return out;
}

Node* Llist::FindNode(int int1)
{
	Node* nPtr;
	nPtr = _headNode;
	//loop through each node until you find the one with the matching number
	for(unsigned int i = 0; i < _nodeCount; i++)
	{
		if(nPtr == NULL) return NULL;
		else if(nPtr->GetNumber() == int1)return nPtr;
		else nPtr = nPtr->GetNextNode();
	}
	return NULL;
}

void Llist::AddNode(Node* node, int int1)
{
	//adds the Node, passed as a parameter, in front of the Node number, passed as a parameter.
	Node* backPtr = FindNode(int1);
	if(backPtr != NULL)
	{
		//set _prevNode
		Node* prev = backPtr->GetPrevNode();
		node->SetPrevNode(prev);
		node->SetNextNode(backPtr);

		backPtr->SetPrevNode(node);
		prev->SetNextNode(node);
	}
	//increment node count
	_nodeCount++;
}

Node* Llist::RemoveNode(int int1)
{
	/// remove the Node with given number
	Node* nPtr = FindNode(int1);
	if(nPtr != NULL)
	{
		Node* prevNode = nPtr->GetPrevNode();
		Node* nextNode = nPtr->GetNextNode();
		prevNode->SetNextNode(nextNode);
		nextNode->SetPrevNode(prevNode);
	}
	//decrement node count
	_nodeCount--;
	/// return the pointer to the removed Node.
	return nPtr;
}


Llist& Llist::operator = (Llist& rho)
{
	if (rho.GetFirst() == NULL)
	{
		ClearList();
		return *this;
	}
	// check to see if this object is equal to the right hand object
	if (this != &rho)
	{
		ClearList();

		Node* oldNode = rho.GetFirst();
		//clone the old head node
		_headNode = oldNode->Clone();
		//get the next old node
		oldNode = oldNode->GetNextNode();
		//clone the next old node
		Node* newNode = oldNode->Clone();
		//set Next Node for head node
		_headNode->SetNextNode(newNode);
		//set prev node for next node to the new _headNode
		newNode->SetPrevNode(_headNode);
		//get the pointer to the next node in the old list
		oldNode = oldNode->GetNextNode();
		while (oldNode != NULL)
		{
			//clone the old Node
			Node* nextNode = oldNode->Clone();
			//set the next node of newNode
			newNode->SetNextNode(nextNode);
			//set the prev node of nextNode to newNode
			nextNode->SetPrevNode(newNode);
			//point newNode to nextNode						//TODO check this
			newNode = nextNode;
			//get the pointer to the next node in the old list
			oldNode = oldNode->GetNextNode();
		}
		_endNode = newNode;
		_nodeCount = rho.GetCount();
	}
	//Return a reference to this object.
	return *this;
}

string Llist::ToString()
{
	//returns the values of all member data of the Llist as a string.
	ostringstream outs;
	Node* nodePtr = _headNode;
	while (nodePtr != NULL)
	{
		//add the ToString Results of each node to the string
		outs << nodePtr->ToString();
		nodePtr = nodePtr->GetNextNode();
	}
	return outs.str();
}

Llist* Llist::Clone()
{
	//clone this list object, return a pointer to the clone
	Node* oldNode = _headNode;
	//clone the old head node
	Node* newHead = oldNode->Clone();
	//get the next old node
	oldNode = oldNode->GetNextNode();
	//clone the next old node
	Node* newNode = oldNode->Clone();
	//set Next Node for head new head node
	newHead->SetNextNode(newNode);
	//set prev node for next node to the new _headNode
	newNode->SetPrevNode(newHead);
	//get the pointer to the next node in the old list
	oldNode = oldNode->GetNextNode();
	//copy the rest of the list
	while (oldNode != NULL)
	{
		//clone the old Node
		Node* nextNode = oldNode->Clone();
		//set the next node of newNode
		newNode->SetNextNode(nextNode);
		//set the prev node of nextNode to newNode
		nextNode->SetPrevNode(newNode);
		//point newNode to nextNode						//TODO check this
		newNode = nextNode;
		//get the pointer to the next node in the old list
		oldNode = oldNode->GetNextNode();
	}
	Node* newEnd = newNode;

	Llist* newList = new Llist(_nodeCount);
	newList->SetFirst(newHead);
	newList->SetLast(newEnd);
	//Return a reference to the new Llist
	return newList;
}


void Llist::ClearList(void)
{
	//clears the list and sets _headNode and _rearNode to NULL.
	Node* current = _headNode;
	Node* temp;
	int i = 0;
	while (current != NULL)
	{
		temp = current;
		//cout << i++ << " " << current << " " << typeid(current).name() << endl;
		current = current->GetNextNode();
		delete temp;
	}
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = 0;
}

//-----------------------------------------End Llist implementation-------------------------------------------

