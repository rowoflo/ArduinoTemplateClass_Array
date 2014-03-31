/*
 -------------------------------------------------------------------------------
 Array.h
 Array Project
 
 This template class adds array functionality to Arduino code.
 
 Initially created by Rowland O'Flaherty on 7/13/10.
 -------------------------------------------------------------------------------
 */

#ifndef _Array_h_
#define _Array_h_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


template <typename T>
class Array
{
	//--------------------------------------------------------------------------
	// Friends
	//--------------------------------------------------------------------------
	
	
	//--------------------------------------------------------------------------
	// Friend Overloaded Operators
	//--------------------------------------------------------------------------

	
public:
	//--------------------------------------------------------------------------
	// Constants, Enums, and Types
	//--------------------------------------------------------------------------
	
	
	//--------------------------------------------------------------------------
	// Lifecycle
	//--------------------------------------------------------------------------
	
	// Constructors
	Array();
	Array(int nElements);
	
	// Destructor
	~Array();
	
	// Copy constructor
	Array(const Array<T>& srcObj);
	
	// Assignment operator
	const Array& operator=(const Array<T>& rhsObj);
	
	
	//--------------------------------------------------------------------------
	// Overloaded Operators
	//--------------------------------------------------------------------------
	T& operator[](int index);
	const T& operator[](int index) const;
	
	//--------------------------------------------------------------------------
	// Public Member Functions
	//--------------------------------------------------------------------------
	int length();
	void remove(int index);
	void sort();
	T minimum();
	T maximum();
	T sum();
	T mean();
	T median();
	
	//--------------------------------------------------------------------------
	// Public Member Variables
	//--------------------------------------------------------------------------
	
	
	
protected:
	//--------------------------------------------------------------------------
	// Protected Member Functions
	//--------------------------------------------------------------------------

	
	//--------------------------------------------------------------------------
	// Protected Member Variables
	//--------------------------------------------------------------------------
	int _length;
	T* _elements;
	
	
private:
	//--------------------------------------------------------------------------
	// Lifecycle
	//--------------------------------------------------------------------------
	void copyHelper(const Array<T>& srcObj);
	
	//--------------------------------------------------------------------------
	// Private Member Functions
	//--------------------------------------------------------------------------
	void resize(int newSize);
	
	//--------------------------------------------------------------------------
	// Private Member Variables
	//--------------------------------------------------------------------------
	static const int _allocSize = 5;
	int _nElements;
	
};

#include "Array.cpp"

#endif