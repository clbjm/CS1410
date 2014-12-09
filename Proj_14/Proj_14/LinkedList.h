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


#include <iostream>
#include <string>
using namespace std;



class Node
{
	private:
		Node* _nextNode;
		Node* _prevNode;
		unsigned int   _number;
		//description of the item
		string _description;
		string _unitOfMeasure;

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
		Node(int, string, string);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~Node();

		///-------------------- Getter Function---------------------
		/// Purpose: To Get the description of the node object
		/// Returns: string reference to description
		///---------------------------End-------------------------------
		const string& GetDescription() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the description of the node object
		/// Parameters: string reference for description
		/// Returns: none
		///---------------------------End-------------------------------
		void SetDescription(const string& description);

		///-------------------- Getter Function---------------------
		/// Purpose: To get the pointer to this object
		/// Returns: pointer to this Node object
		///---------------------------End-------------------------------
		const Node*& GetNextNode() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the pointer to the next node object
		/// Parameters: reference to the pointer for the next node object
		/// Returns: none
		///---------------------------End-------------------------------
		void SetNextNode(const Node*&);

		///-------------------- Getter Function---------------------
		/// Purpose: To get the pointer to this object
		/// Returns: pointer to this Node object
		///---------------------------End-------------------------------
		const Node*& GetPrevNode() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the pointer to the next node object
		/// Parameters: reference to the pointer for the next node object
		/// Returns: none
		///---------------------------End-------------------------------
		void SetPrevNode(const Node*&);

		//-------------------- Getter Function---------------------
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

		//-------------------- Getter Function---------------------
		/// Purpose: To get the unit of measure (for description:'bread' unit might be 'loaves'
		/// Returns: string reference to unit of measure
		///---------------------------End-------------------------------
		const string& GetUnitOfMeasure() const;

		///-------------------- Setter Function---------------------
		/// Purpose: To set the unit of measure (for description:'bread' unit might be 'loaves'
		/// Parameters: string reference to unit of measure
		/// Returns: none
		///---------------------------End-------------------------------
		void SetUnitOfMeasure(const string& unitOfMeasure);

		///-------------------- ToString pure virtual function---------------------
		/// Purpose: Pure virtual function
		/// Parameters: none
		/// Returns: none
		///---------------------------End-------------------------------
		string ToString() = 0;
};

class List
{
	private:
		Node* _headNode;
		Node* _endNode;
		unsigned int   _nodeCount;

	public:

		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		List();

		///----------------- Copy Constructor -----------------------
		/// Purpose: Facilitate the copying of a List object
		/// Parameters: List object to be copied
		///-------------------------- End ------------------------------
		List(List&);

		///----------------- Constructor -----------------------
		/// Purpose: To construct a List object, setting its capacity to provided value
		/// Parameters: integer for capacity
		///-------------------------- End ------------------------------
		List(int);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~List();

		///-------------------- Push_Front Function-------------------------------------------------
		/// Purpose:
		/// Parameters:
		/// Returns:
		///---------------------------End--------------------------------------------------
		void Push_Front(Node*);

		///-------------------- Pop_Front Function-------------------------------------------------
		/// Purpose:
		/// Parameters:
		/// Returns:
		///---------------------------End--------------------------------------------------
		void Pop_Front(void);
		///-------------------- Push_End Function-------------------------------------------------
		/// Purpose:
		/// Parameters:
		/// Returns:
		///---------------------------End--------------------------------------------------
		void Push_End(Node*);
		///-------------------- Pop_End Function-------------------------------------------------
		/// Purpose:
		/// Parameters:
		/// Returns:
		///---------------------------End--------------------------------------------------		void Pop_End(void);

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
		/// Purpose:
		/// Parameters:
		/// Returns:
		///---------------------------End--------------------------------------------------
		Node* FindNode(int);

		///-------------------- AddNode Function-------------------------------------------------
		/// Purpose:
		/// Parameters:
		/// Returns:
		///---------------------------End--------------------------------------------------
		void AddNode(Node&, int);

		///-------------------- RemoveNode Function-------------------------------------------------
		/// Purpose:  removes the Node with given number, as the parameter and returns the pointer to the removed Node.
		/// Parameters:
		/// Returns:
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
		List& operator = (List&);
		///--------------------assignment operator overloading Function Function-------------
		/// Purpose: overloads the assignment operator
		/// Parameters: pointer to a list object
		/// Returns: pointer to a list object
		///---------------------------End--------------------------------------------------
		List* operator = (List*);
		///--------------------ClearList Function-------------------------------------------------
		/// Purpose: delete the items in the list
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void ClearList(void);
};
