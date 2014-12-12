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



//-----------------------------------------Node implementation-------------------------------------------

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
	Free();
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

void Node::Free(void)
{
	delete _nextNode;
	_nextNode = NULL;
	delete _prevNode;
	_prevNode = NULL;
}

//-----------------------------------------End Node implementation-------------------------------------------




//-----------------------------------------Llist implementation-------------------------------------------

Llist::Llist()
{
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = 0;
	string classname = typeid(*this).name();
	cout << classname << DEFAULT_CONSTRUCTOR << endl;
}

//Llist::Llist(Llist& lst)
//{
	/*
	//--- Test for empty list ------------
	if (lst._headNode == NULL)
		return;
	//--- Get Current List object initialized ------------
	//deallocate the current linked list
	delete this->_headNode;
	//this->_head = this->_end = NULL;
	//initialize _nodeCount
	_nodeCount = 0;
	//set _head & _end to first Node in lst
	this->_headNode = this->_endNode = new Node(lst._headNode->GetNumber());  //First Node
	//Node* tempPtr = lst._head;
	//nCount, used to check that object reference count _nodeCount is working
	_nodeCount++;
	Node* tempNodePtr = NULL;
	Node* nodePtr = lst._headNode->GetNextNode(); //Second node
	while (nodePtr != NULL)
	{
		tempNodePtr = new Node(nodePtr->GetNumber());
		tempNodePtr->SetNextNode(this->_headNode);
		this->_headNode = tempNodePtr;
		nodePtr = nodePtr->GetNextNode();
		_nodeCount++;
	}
	*/
	//print out the copy constructor message
//	string classname = typeid(*this).name();
//	cout << classname << COPY_CONSTRUCTOR << endl;
//}

Llist::Llist(int nodeCount)
{
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = nodeCount;
	string classname = typeid(*this).name();
	cout << classname << CONSTRUCTOR << endl;
}

Llist::~Llist()
{
	string classname = typeid(*this).name();
	cout << classname << DESTRUCTOR << endl;
}

Node* Llist::GetFirst(void)
{
	return _headNode;
}

Node* Llist::GetLast(void)
{
	return _endNode;
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
	if (_headNode == NULL)
	{
		//_headNode = nPtr;
		//_endNode = nPtr;
		return NULL;
	}
	else
	{
		//remove the first node from the list,
		_headNode = _headNode->GetNextNode();
		_nodeCount--;
	}
	//return a pointer to this Node.
	return _headNode;
	//do not delete the Node in this function.
	//Simply unlink and return it from the list.
}

Node* Llist::Pop_End(void)
{
	if (_endNode == NULL)
	{
		//_headNode = nPtr;
		//_endNode = nPtr;
		return NULL;
	}
	else
	{
		//remove the last node from the list,
		_endNode = _endNode->GetPrevNode();
		_nodeCount--;
		//return a pointer to this Node.
	}
	return _endNode;
	//do not delete the Node in this function. TODO how do i delete it?
	//Simply unlink and return it from the list.
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
		node->SetPrevNode(backPtr->GetPrevNode());
		node->SetNextNode(backPtr);
		backPtr->SetPrevNode(node);
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
		//prevNode->ToString();
		Node* nextNode = nPtr->GetNextNode();
		//nextNode->ToString();
		if (nextNode == NULL) cout << "nextNode == NULL" << endl;
		if (prevNode == NULL) cout << "prevNode == NULL" << endl;
		cin.get();
		prevNode->SetNextNode(nextNode);
		nextNode->SetPrevNode(prevNode);
	}
	//decrement node count
	_nodeCount--;
	/// return the pointer to the removed Node.
	return nPtr;
}

void Llist::ClearList(void)
{
	//clears the list and sets _headNode and _rearNode to NULL.
	Node* nodePtr = _headNode;
	Node* nextPtr = _headNode->GetNextNode();
	while (nodePtr != NULL)
	{
		//free the memory related to the node
		nodePtr->Free();
		nodePtr = nextPtr;
		nextPtr = nodePtr->GetNextNode();
		_nodeCount--;
	}
	_headNode = NULL;
	_endNode = NULL;
	_nodeCount = 0;
}

void Llist::DisplayList(void)
{
}

/*
Llist& Llist::operator = (Llist&)
{
}
*/
string Llist::ToString()
{
	//returns the values of all member data of the Llist as a string.
	ostringstream outs;
	string classname = typeid(*this).name();
	outs << classname.c_str() << endl;
	Node* nodePtr = _headNode;
	while (nodePtr != NULL)
	{
		//add the ToString Results of each node to the string
		outs << nodePtr->ToString();
		nodePtr->Free();
		nodePtr = nodePtr->GetNextNode();
	}
	return outs.str();
}

//-----------------------------------------End Llist implementation-------------------------------------------

