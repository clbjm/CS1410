//============================================================================
// File Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Proj_12
// Purpose: Demonstrate understanding of dynamic storage & memorty management.
// Date: December 2014 
// Date: 12/09/14 9:59 AM
//============================================================================
// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying 
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.
//----------------------------------------------------------------------

#include "MyVector.h"

const int DEFAULT_CAPACITY = 2;
const int GROW_SIZE = 2;


MyVector::MyVector()
{
	//A default constructor that creates an vector with a default capacity of 2
	_pData = new int[DEFAULT_CAPACITY]{NULL};
	_capacity = DEFAULT_CAPACITY;
	_size = 0;
}

MyVector::MyVector(MyVector& vector)
{
	//copy constructor 
	//free the memory in this object
	Free();
	//copy everything (including the dynamically allocated memory) in the vector object
	Copy(vector);
}

MyVector::MyVector(int n)
{
	//A parameterized constructor that creates a vector of capacity n
	_pData = new int[n];
	_capacity = n;
	_size = 0;
}

//A destructor that deletes any dynamically allocated storage.
//Note that you program should not have any memory leaks.
MyVector::~MyVector()
{
	//free up all the dynamically allocated memory.
	Free();
}

int MyVector::Size() const
{
	//returns the size of your vector.
	return _size;
}
int MyVector::Capacity() const
{
	//returns the capacity of the vector.
	return _capacity;
}
void MyVector::Clear()
{
	//deletes all of the elements from the vector and resets its size to zero and its capacity to two.
	// Free the memory on the heap
	Free();
	//create a new array with default capacity
	_pData = new int[DEFAULT_CAPACITY];
	_capacity = DEFAULT_CAPACITY;
	_size = 0;
}

void MyVector::Push_Back(int n)
{

	//check to be sure that there is room in the array for the new value
	if (_capacity > _size)
	{
		//add the number to the array
		_pData[_size] = n;
		//increment size and 
		_size++;
	}
	else
	{
		//create a new array on the heap,twice the capacity of _pData
		int* newArray = new int[_capacity * GROW_SIZE]{NULL};

		//copy all of _pData into new Array
		for (int count = _capacity; count > 0; count--)
		{
			newArray[count - 1] = _pData[count - 1];
		}

		// Free the memory on the heap
		Free();
		//change _pData to newArray
		_pData = newArray;
		_capacity *= GROW_SIZE;
		//add the number to the array
		_pData[_size] = n;
		//increment size and 
		_size++;
	}
}

int MyVector::ValueAt(int n) const
{
	//returns the value of the element at position n in the vector. 
	//If the index n is greater than the size( ) of the vector, 
	//this function should throw an exception.

	//check to see if the given index is outside the range of the array
	if (n > _size - 1) throw n;

	//if its in range, return the value at the given index
	return _pData[n];
}


void MyVector::Copy(MyVector& vector)
{
	this->_capacity = vector._capacity;
	this->_size = vector._size;
	// make a new copy of the array on the heap
	this->_pData = new int[_capacity]{NULL};
	//copy all of vector._pData into new Array
	for (int count = _capacity; count > 0; count--)
	{
		this->_pData[count - 1] = vector._pData[count - 1];
	}
}

void MyVector::Free(void)
{
	// free up all the dynamically allocated memory
	//loop through all the addresses in _pData and set each to NULL
	//for (_capacity; _capacity > 0; _capacity--)
	//{
	//	_pData[_capacity - 1] = NULL;
	//}
	//delete the array
	delete[] _pData;
	//pointers should be set to NULL after calling delete to return storage to the heap
	_pData = NULL;
}

MyVector& MyVector::operator = (MyVector& rho)
{
	// check to see if this object is equal to the right hand object
	if (this != &rho)
	{
		//free the memory in this object
		Free();
		//copy everything (including the dynamically allocated memory) in the rho object
		Copy(rho);
	}
	//Return a reference to this object.
	return *this;
}


//-------------------------Stand Alone Functions ----------------------------------

ostream& operator<<(ostream& out, const MyVector& rho)
{
	int capacity = rho.Capacity();
	out << "capacity = " << capacity << endl;
	int size = rho.Size();
	out << "size = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		out << "element " << i << " = " << rho.ValueAt(i) << endl;
	}
	return out;
}

