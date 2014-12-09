//============================================================================
// Project Prolog
// Author: Kevin S. O'Day
// Course: CS 1410 Section 002
// Project: Lab_13
// Purpose: Demonstrate understanding of function & class templates.
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

const string VALUE_CONSTRUCTOR_MSG = "Pair Parameterized (pass by value) Constructor ";
const string REFERENCE_CONSTRUCTOR_MSG = "Pair Parameterized (pass by reference) Constructor ";
const string DESTRUCTOR_MSG = "Pair Destructor ";

template<typename T>
class Pair
{
	private:
		T _first;
		T _second;

	public:

		///----------------- Copy Constructor -----------------------
		/// Purpose: Facilitate the copying of a Pair object
		/// Parameters: Pair object to be copied
		///-------------------------- End ------------------------------
		Pair(Pair&);

		///----------------- Constructor (by Value)-----------------------
		/// Purpose: To construct a Pair object, setting its capacity to provided value
		/// Parameters: 
		///-------------------------- End ------------------------------
		Pair(T, T);

		///----------------- Constructor (by Reference)-----------------------
		/// Purpose: To construct a Pair object, setting its capacity to provided value
		/// Parameters:
		///-------------------------- End ------------------------------
		Pair(const T&, const T&, bool);

		///----------------- Destructor -----------------------
		/// Purpose: To delete dynamically allocated storage, prevent leaks.
		/// Parameters: none
		///-------------------------- End ------------------------------
		virtual ~Pair();

		///--------------------getFirst Function---------------------
		/// Purpose: getter for _first
		/// Parameters: none
		/// Returns: value of type T
		///---------------------------End-------------------------------
		T getFirst(void);

		///--------------------getSecond Function---------------------
		/// Purpose: getter for _second
		/// Parameters: none
		/// Returns: value of type T
		///---------------------------End-------------------------------
		T getSecond(void);
};


template<typename T>
Pair<T>::Pair(T first, T second) : _first(first), _second(second)
{
	cout << VALUE_CONSTRUCTOR_MSG << endl;
}
template<typename T>
Pair<T>::Pair(const T& first, const T& second, bool) : _first(first), _second(second)
{
	cout << REFERENCE_CONSTRUCTOR_MSG << endl;
}

template<typename T>
Pair<T>::~Pair(void)
{
	cout << DESTRUCTOR_MSG << endl;
}

template <typename T>
T Pair<T>::getFirst()
{
	return _first;
}

template <typename T>
T Pair<T>::getSecond()
{
	return _second;
}
