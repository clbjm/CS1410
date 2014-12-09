//============================================================================
// Project Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Proj_13
// Purpose: Templatized vector
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

const int DEFAULT_CAPACITY = 2;
const int GROW_SIZE = 2;

template<typename T>
class MyVector
{
	private:
		//pointer of type T
		T* _pData = NULL;
		//the current number of elements in the array
		int _size;
		//the total current capacity of the array
		int _capacity;

	public:

		///----------------- Default Constructor -----------------------
		/// Purpose: To initialize all data members to their default values
		/// Parameters: None
		///-------------------------- End ------------------------------
		MyVector();

		///----------------- Copy Constructor -----------------------
		/// Purpose: Facilitate the copying of a MyVector object
		/// Parameters: MyVector object to be copied
		///-------------------------- End ------------------------------
		MyVector(MyVector&);

		///----------------- Constructor -----------------------
		/// Purpose: To construct a MyVector object, setting its capacity to provided value
		/// Parameters: integer for capacity
		///-------------------------- End ------------------------------
		MyVector(int);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~MyVector();

		///--------------------size Function---------------------
		/// Purpose: get the current number of elements in the array
		/// Parameters: none
		/// Returns: integer current number of elements in the array
		///---------------------------End-------------------------------
		int size() const;

		///--------------------capacity Function---------------------
		/// Purpose: get the total capacity of the array
		/// Parameters: none
		/// Returns: integer total capacity of the array
		///---------------------------End-------------------------------
		int capacity() const;

		///--------------------clear Function---------------------
		/// Purpose: Clar all the elements in the array, reset size and capacity to default
		/// Parameters: none
		/// Returns: none
		///---------------------------End-------------------------------
		void clear();

		///--------------------push_back Function---------------------
		/// Purpose: add the  value to the end of the array, grow as needed
		/// Parameters: integer to add to the array
		/// Returns: none
		///---------------------------End-------------------------------
		void push_back(const T&);

		///--------------------at Function-------------------------------------------------
		/// Purpose: Returns the value of the element at given index
		/// Parameters: integer for index
		/// Returns: value of type T at given index, throws exception if index is greater than size
		///---------------------------End--------------------------------------------------
		T at(int) const;

		///--------------------Copy Function-------------------------------------------------
		/// Purpose: Copies the object
		/// Parameters: Reference to a MyVector object
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Copy(MyVector&);

		///--------------------Free Function-------------------------------------------------
		/// Purpose: Frees (Deletes the pointers) the memory associated with the object
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void Free(void);

		///-------------------- assignment operator overloading Function -----------------------
		/// Purpose: Assigns the values of one MyVector object to another
		/// Returns: Reference to MyVector object
		///-------------------------- End ------------------------------
		MyVector& operator = (MyVector&);

		///--------------------pop_back Function-------------------------------------------------
		/// Purpose: This function removes the last integer pushed into the vector. 
		///			The size of the vector is reduced by one.
		///			The function does nothing if the vector is empty.
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		void pop_back();

		///--------------------last Function-------------------------------------------------
		/// Purpose: This function returns the last value pushed into the vector, 
		///			but it does not remove it. 
		///			Do not worry about the case where the vector is empty.
		/// Parameters: none
		/// Returns: type T
		///---------------------------End--------------------------------------------------
		T last();

		///--------------------subscript operator overloading Function----------------------
		/// Purpose: This function overloads the [] operator we use to index into an array. 
		/// Parameters: none
		/// Returns: none
		///---------------------------End--------------------------------------------------
		T operator [](int) const;
};


///-------------------- stream insertion overloading Function -----------------------
/// Purpose: Converts the object into a form that can be printed and overloads the stream insertion operator
/// Returns: reference to ostream object containing a representation of the object.
///-------------------------- End ------------------------------
template <typename T>
ostream& operator<<(ostream& out, const MyVector<T>& rho);

template <typename T>
ostream& operator<<(ostream& out, const MyVector<T>& rho)
{
	int capacity = rho.capacity();
	out << "capacity = " << capacity << endl;
	int size = rho.size();
	out << "size = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		out << "element " << i << " = " << rho.at(i) << endl;
	}
	return out;
}

//---------------------MyVector Template implementation---------------------------------

template <typename T>
MyVector<T>::MyVector()
{
	//A default constructor that creates an vector with a default capacity of 2
	_pData = new T[DEFAULT_CAPACITY]{NULL};
	_capacity = DEFAULT_CAPACITY;
	_size = 0;
}

template <typename T>
MyVector<T>::MyVector(MyVector& vector)
{
	//copy constructor 
	//free the memory in this object
	Free();
	//copy everything (including the dynamically allocated memory) in the vector object
	Copy(vector);
}

template <typename T>
MyVector<T>::MyVector(int n)
{
	//A parameterized constructor that creates a vector of capacity n
	_pData = new T[n];
	_capacity = n;
	_size = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
	//free up all the dynamically allocated memory.
	Free();
}

template <typename T>
int MyVector<T>::capacity() const
{
	return _capacity;
}

template <typename T>
int MyVector<T>::size() const
{
	return _size;
}

template <typename T>
void MyVector<T>::clear()
{
	//deletes all of the elements from the vector and resets its size to zero and its capacity to two.
	// Free the memory on the heap
	Free();
	//create a new array with default capacity
	_pData = new T[DEFAULT_CAPACITY];
	_capacity = DEFAULT_CAPACITY;
	_size = 0;
}

template <typename T>
void MyVector<T>::push_back(const T& value)
{
	//check to be sure that there is room in the array for the new value
	if (_capacity > _size)
	{
		//add the number to the array
		_pData[_size] = value;
		//increment size and 
		_size++;
	}
	else
	{
		//create a new array on the heap,twice the capacity of _pData
		T* newArray = new T[_capacity * GROW_SIZE]{NULL};

		//copy all of _pData into new Array
		for(int count = _capacity; count > 0; count--)
		{
			newArray[count - 1] = _pData[count - 1];
		}

		// Free the memory on the heap
		Free();
		//change _pData to newArray
		_pData = newArray;
		_capacity *= GROW_SIZE;
		//add the number to the array
		_pData[_size] = value;
		//increment size and 
		_size++;
	}
}

template <typename T>
T MyVector<T>::at(int n) const
{
	//returns the value of the element at position n in the vector. 
	//If the index n is greater than the size( ) of the vector, 
	//this function should throw an exception.

	//check to see if the given index is outside the range of the array
	if(n > this->_size - 1) throw n;

	//if its in range, return the value at the given index
	return this->_pData[n];
}

template <typename T>
void MyVector<T>::Copy(MyVector& vector)
{
	this->_capacity = vector._capacity;
	this->_size = vector._size;
	// make a new copy of the array on the heap
	this->_pData = new T[_capacity]{NULL};
	//copy all of vector._pData into new Array
	for (int count = _capacity; count > 0; count--)
	{
		this->_pData[count - 1] = vector._pData[count - 1];
	}
}

template <typename T>
void MyVector<T>::Free(void)
{
	// free up all the dynamically allocated memory
	//loop through all the addresses in _pData and set each to NULL
	//for (_capacity; _capacity > 0; _capacity--)
	//{
	//	_pData[_capacity - 1] = NULL;
	//}
	//delete the array
	delete[] this->_pData;
	//pointers should be set to NULL after calling delete to return storage to the heap
	this->_pData = NULL;
}

template <typename T>
MyVector<T>& MyVector<T>::operator = (MyVector<T>& rho)
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

template <typename T>
void MyVector<T>::pop_back()
{
	//does nothing if the vector is empty.
	if (this->_size == 0) return;
	//removes the last integer pushed into the vector.
	//remove the last number 
	this->_pData[_size - 1] = NULL;
	//decrement size
	this->_size--;
}

template <typename T>
T MyVector<T>::last()
{
	//This function returns the value of the last integer pushed into the vector,
	//but it does not remove it. 
	return this->_pData[_size - 1];
	//Do not worry about the case where the vector is empty.
}

template <typename T>
T MyVector<T>::operator [](int index) const
{
	//assert((index >= 0) && (index < _size));
	return this->_pData[index];
}
