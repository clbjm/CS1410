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

#include "Proj_14.h"

// Driver for testing your Project #14
// Author: Dennis A. Fairclough/Roger deBry
// CS 1410
// Date last modified: December 5, 2013
// ----------------- .h file contents ----------------------

// the PrintList function
// Purpose: Prints out the contents for each Node in the List
// Parameter: A list object, by value
// Returns: none
void PrintList(Llist&);

// the PrintNode function
// Purpose: Prints out the contents for the 1st Node in the List
// Parameter: A list object, passed by value to test the copy constructor
//                   int is the _number of the node to print.
// Returns: none
void PrintNode(Llist&, int);

// the PrintNode function
// Purpose: Prints out the contents of Node in the passed by address
// Parameter: A Node object, by address
// Returns: none
void PrintNode(Node*);

// ----------------- .cpp file contents ----------------------

void ProjTestGrocery()
{
	//===============================================
	// 			PART ONE
	//===============================================
	cout << "\nPart I: Push_Front and Pop_Front\n";
	cout << "\n----------------------------------\n";
	Llist groceries;

	// test Push_Front function
	groceries.Push_Front(new Grocery(1, "gallon", "milk", 1));
	groceries.Push_Front(new Grocery(2, "loaves", "bread", 2));
	groceries.Push_Front(new Grocery(1, "dozen", "eggs", 3));
	groceries.Push_Front(new Grocery(1, "package", "bacon", 4));
	groceries.AddNode(new Supplies(10, "box", "pencils", 1, 5), 3);
	Node* _tempNode = groceries.RemoveNode(2);
	cout << "Removed Node -> " << _tempNode->ToString() << endl;
	PrintNode(_tempNode);
	delete _tempNode;
	cout << "\nThe original nodes in the List:\n";
	PrintList(groceries);
	cout << "\n----------------------------------\n";

	// test Push_Front function
	cout << "\nAdding to the front of the List:\n";
	cout << "\n----------------------------------\n";
	groceries.Push_Front(new Grocery(2, "lbs", "hamburger", 5));
	groceries.Push_Front(new Grocery(1, "dozen", "hamburger buns", 6));

	PrintList(groceries);
	cout << "\n----------------------------------\n";

	// test pop-front
	cout << "\nRemoving the first node from the list.\n";
	cout << "\n----------------------------------\n";
	Node* item = groceries.Pop_Front();
	cout << "\nPopped " << item->GetName() << " from the list.\n\n";
	PrintList(groceries);
	if (item != NULL)
		delete item;

	//====================================================
	//    	PART TWO: Uncomment this block to test part two
	//====================================================

	cout << "\n----------------------------------\n";
	cout << "\nPart Two: Push_End and Pop_End";

	//test Push_End
	groceries.Push_End(new Grocery(2, "cans", "orange juice", 10));
	groceries.Push_End(new Grocery(1, "lb", "swiss cheese", 11));

	cout << "\nAdding two nodes at the end\n";
	cout << "\n----------------------------------\n";
	PrintList(groceries);

	//test Pop_End
	cout << "\n----------------------------------\n";
	cout << "\nRemove last node from the list\n";
	cout << "\n----------------------------------\n";
	item = groceries.Pop_End();
	cout << "\nPopped " << item->GetName() << " from the list.\n\n";

	PrintList(groceries);
	if (item != NULL)
		delete item;
	//============================================
	//   			End of part two
	//============================================

	//=======================================================
	//   	PART THREE: uncomment this block to test part three
	//=======================================================

	//create a second list to test assignment
	cout << "\n\n--------------extra credit------------------\n";
	cout << "\n\n overloaded assignment operator\n";
	cout << "The hardware list ...\n";
	cout << "\n-------------------------------------------\n";
	Llist hardware;
	hardware.Push_End(new Grocery(2, "lbs", "nails", 7));
	hardware.Push_End(new Grocery(3, "gals", "white paint", 8));
	hardware.Push_End(new Grocery(1, "piece", "plywood", 9));
	PrintList(hardware);
	hardware = groceries;
	cout << "\n-------------------------------------------\n";
	cout << "\nafter assignment";
	cout << "\n-------------------------------------------\n";
	PrintList(hardware);

	cout << "\n-------------------------------------------\n";
	cout << "\nTest the copy constructor\n";
	cout << "\n-------------------------------------------\n";
	PrintList(hardware);

	// ==============================================
	// 			End of part 3
	// ==============================================

	cout << "\n-------------------------------------------\n";
	cout << "\nEnd of Test";
	cout << "\n-------------------------------------------\n";
	//supply.ClearList(); Error in provided driver code
	hardware.ClearList();
	system("PAUSE");
}
void ProjTestSupplies()
{
	//===============================================
	// 			PART ONE
	//===============================================
	cout << "\nPart I: Push_Front and Pop_Front\n";
	cout << "\n----------------------------------\n";
	Llist supply;

	// test Push_Front function
	supply.Push_Front(new Supplies(1, "box", "pencils", 1, 1));
	supply.Push_Front(new Supplies(2, "package", "rubber bands", 1, 2));
	supply.Push_Front(new Supplies(1, "dozen", "pens", 1, 3));
	supply.Push_Front(new Supplies(1, "package", "stickers", 1, 4));

	cout << "\nThe original nodes in the List:\n";
	PrintList(supply);
	cout << "\n----------------------------------\n";

	// test Push_Front function
	cout << "\nAdding to the front of the List:\n";
	cout << "\n----------------------------------\n";
	supply.Push_Front(new Supplies(2, "lbs", "paper clips", 1, 5));
	supply.Push_Front(new Supplies(1, "dozen", "wall pins", 1, 6));

	PrintList(supply);
	cout << "\n----------------------------------\n";

	// test pop-front
	cout << "\nRemoving the first node from the list.\n";
	cout << "\n----------------------------------\n";
	Node* item = supply.Pop_Front();
	cout << "\nPopped " << item->GetName() << " from the list.\n\n";
	PrintList(supply);
	if (item != NULL)
		delete item;

	//====================================================
	//    PART TWO: Uncomment this block to test part two
	//====================================================

	cout << "\n----------------------------------\n";
	cout << "\nPart Two: Push_End and Pop_End";

	//test Push_End
	supply.Push_End(new Supplies(2, "can", "spray glue", 1, 10));
	supply.Push_End(new Supplies(1, "lb", "parrot clips", 1, 11));

	cout << "\nAdding two nodes at the end\n";
	cout << "\n----------------------------------\n";
	PrintList(supply);

	//test Pop_End
	cout << "\n----------------------------------\n";
	cout << "\nRemove last node from the list\n";
	cout << "\n----------------------------------\n";
	item = supply.Pop_End();
	cout << "\nPopped " << item->GetName() << " from the list.\n\n";

	PrintList(supply);
	if (item != NULL)
		delete item;
	//============================================
	//   			End of part two
	//============================================

	//=======================================================
	//   	PART THREE: uncomment this block to test part three
	//=======================================================

	//create a second list to test assignment
	cout << "\n\n--------------extra credit------------------\n";
	cout << "\n\n overloaded assignment operator\n";
	cout << "The hardware list ...\n";
	cout << "\n-------------------------------------------\n";
	Llist hardware;
	hardware.Push_End(new Supplies(2, "lbs", "plastic pins", 1, 7));
	hardware.Push_End(new Supplies(3, "gals", "paper glue", 1, 8));
	hardware.Push_End(new Supplies(1, "piece", "plywood", 1, 9));
	PrintList(hardware);
	hardware = supply;
	cout << "\n-------------------------------------------\n";
	cout << "\nafter assignment";
	cout << "\n-------------------------------------------\n";
	PrintList(hardware);

	cout << "\n-------------------------------------------\n";
	cout << "\nTest the copy constructor\n";
	cout << "\n-------------------------------------------\n";
	PrintList(hardware);

	// ==============================================
	// 			End of part 3
	// ==============================================

	cout << "\n-------------------------------------------\n";
	cout << "\nEnd of Test";
	cout << "\n-------------------------------------------\n";
	supply.ClearList();
	hardware.ClearList();
	system("PAUSE");
	//return 0;
}


void PrintList(Llist& lst)
{
	cout <<  lst.ToString();
}

void PrintNode(Llist& lst, int n)
{
	Node* nPtr = lst.FindNode(n);
	cout << nPtr->ToString();
}

void PrintNode(Node* nPtr)
{
	cout << nPtr->ToString();
}

int main()
{
	ProjTestGrocery();
	ProjTestSupplies();
	return 0;
}
