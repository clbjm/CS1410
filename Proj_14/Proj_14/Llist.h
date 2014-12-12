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

#ifndef LLIST_H_
#define LLIST_H_

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>  //for 'typeid'
using namespace std;

class Node
{
	private:
		Node* _nextNode;
		Node* _prevNode;
		unsigned int _number;//unique

	public:

		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		Node();

		///----------------- Copy Constructor -----------------------
		/// Purpose: Facilitate the copying of a Node object
		/// Parameters: Node object to be copied
		///-------------------------- End ------------------------------
		Node(Node&);

		///----------------- Constructor -----------------------
		/// Purpose: To construct a Node object with the provided parameters
		/// Parameters: integer for capacity
		///-------------------------- End ------------------------------
		Node(int);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~Node();


		///-------------------- Getter Function---------------------
		/// Purpose: To get the pointer to this object
		/// Returns: pointer to this Node object
		///---------------------------End-------------------------------
		Node* GetNextNode() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the pointer to the next node object
		/// Parameters: reference to the pointer for the next node object
		/// Returns: none
		///---------------------------End-------------------------------
		void SetNextNode(Node*);

		///-------------------- pure virtual Getter Function---------------------
		/// Purpose: To get the name of the node object
		/// Returns: string name
		///---------------------------End-------------------------------
		virtual string& GetName() = 0;

		///-------------------- pure virtual Setter Function---------------------
		/// Purpose: To set the name of the node object
		/// Parameters: reference to the string name
		/// Returns: none
		///---------------------------End-------------------------------
		virtual void SetName(string&) = 0;

		///-------------------- Getter Function---------------------
		/// Purpose: To get the pointer to this object
		/// Returns: pointer to this Node object
		///---------------------------End-------------------------------
		Node* GetPrevNode() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the pointer to the next node object
		/// Parameters: reference to the pointer for the next node object
		/// Returns: none
		///---------------------------End-------------------------------
		void SetPrevNode(Node*);

		///-------------------- Getter Function---------------------
		/// Purpose: To get the number of units of the item represented by the node
		/// Returns: integer number of items
		///---------------------------End-------------------------------
		int GetNumber() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To the number of units of the item represented by the node
		/// Parameters: integer number of items
		/// Returns: none
		///---------------------------End-------------------------------
		void SetNumber(int number);

		///-------------------- ToString pure virtual function---------------------
		/// Purpose: Pure virtual function
		/// Parameters: none
		/// Returns: none
		///---------------------------End-------------------------------
		virtual string ToString() = 0;

		///--------------------Copy virtual Function---------------------------------------
		/// Purpose: Copies the object
		/// Parameters: Reference to a Node object
		/// Returns: none
		///---------------------------End--------------------------------------------------
		virtual void Copy(Node&);

		///--------------------Free Function-------------------------------------------------
		/// Purpose: Frees (Deletes the pointers) the memory associated with the object
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Free(void);
};


class Llist
{
	private:
		Node* _headNode;
		Node* _endNode;
		unsigned int _nodeCount;

	public:

		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		Llist();

		///----------------- Copy Constructor -----------------------
		/// Purpose: Facilitate the copying of a List object
		/// Parameters: List object to be copied
		///-------------------------- End ------------------------------
		//Llist(Llist&);

		///----------------- Constructor -----------------------
		/// Purpose: To construct a List object, setting its capacity to provided value
		/// Parameters: integer for capacity
		///-------------------------- End ------------------------------
		Llist(int);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~Llist();

		///-------------------- Push_Front Function-------------------------------------------------
		/// Purpose:adds the node pointed to by the pointer to the front of the Llist
		/// Parameters: Pointer to a Node
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Push_Front(Node*);

		///-------------------- Push_End Function-------------------------------------------------
		/// Purpose: and adds the node pointed to by the pointer to the end of the list.
		/// Parameters: Pointer to a Node
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Push_End(Node*);

		///-------------------- Pop_Front Function-------------------------------------------------
		/// Purpose: removes the first node from the list, and returns a pointer to this Node
		///			do not delete the Node in this function. Simply unlink and return it from the list
		/// Parameters: none
		/// Returns: a pointer to a Node
		///---------------------------End--------------------------------------------------
		Node* Pop_Front(void);		///-------------------- Pop_End Function-------------------------------------------------
		/// Purpose: removes the last node from the list, and returns a pointer to this Node. 
		///			Important, do not delete the node in this function. 
		///			Simply unlink and return it from the list.
		/// Parameters: none
		/// Returns: Pointer to a Node
		///---------------------------End--------------------------------------------------		Node* Pop_End(void);

		//-------------------- Getter Function---------------------
		/// Purpose: To get the pointer to the first node in the list
		/// Returns: node pointer
		///---------------------------End-------------------------------
		Node* GetFirst(void);

		//-------------------- Getter Function---------------------
		/// Purpose: To get the pointer to the last node in the list
		/// Returns: node pointer
		///---------------------------End-------------------------------
		Node* GetLast(void);

		///-------------------- FindNode Function-------------------------------------------------
		/// Purpose: finds a Node with its number as a parameter
		/// Parameters: int number of the node
		/// Returns: returns the address of the Node if it can be found or a NULL if the Node cannot be found.
		///---------------------------End--------------------------------------------------
		Node* FindNode(int);

		///-------------------- AddNode Function-------------------------------------------------
		/// Purpose: adds the Node, passed as a parameter, in front of the Node number, passed as a parameter.
		/// Parameters: Pointer to a node to add, int node number to add in front of
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void AddNode(Node*, int);

		///-------------------- RemoveNode Function-------------------------------------------------
		/// Purpose:  removes the Node with given number
		/// Parameters: int number of the node to be removed
		/// Returns:  returns the pointer to the removed Node.
		///---------------------------End--------------------------------------------------
		Node* RemoveNode(int);

		///--------------------DisplayList Function-------------------------------------------------
		/// Purpose: Display the list for the user
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void DisplayList(void);
		///--------------------assignment operator overloading Function--------------------
		/// Purpose: overloads the assignment operator
		/// Parameters: reference to a list object
		/// Returns: reference to a list object
		///---------------------------End--------------------------------------------------
		//Llist& operator = (Llist&);
		///--------------------assignment operator overloading Function Function-------------
		/// Purpose: overloads the assignment operator
		/// Parameters: pointer to a list object
		/// Returns: pointer to a list object
		///---------------------------End--------------------------------------------------
		//Llist* operator = (Llist*);
		///--------------------ClearList Function-------------------------------------------------
		/// Purpose: clears the list and sets _headNode and _rearNode to NULL.
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void ClearList(void);

		///-------------------- ToString function---------------------
		/// Purpose: returns the values of all member data of the Llist as a string
		/// Parameters: none
		/// Returns: all member data as a string
		///---------------------------End-------------------------------
		string ToString();
};



#endif /* LLIST_H_ */
