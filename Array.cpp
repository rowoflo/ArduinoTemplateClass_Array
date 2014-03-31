/*
 -------------------------------------------------------------------------------
 Array.cpp
 Array Project
 
 Initially created by Rowland O'Flaherty on 7/13/10.
 -------------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Friends
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Friend Overloaded Operators
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Lifecycle
//------------------------------------------------------------------------------

// Constructors
template <typename T>
Array<T>::
Array()
:
_length(0),
_nElements(0),
_elements(NULL)
{
	
}

template <typename T>
Array<T>::
Array(int nElements)
:
_length(0),
_nElements(nElements),
_elements(NULL)
{
	// Allocate memory
	_elements = (T*)malloc(nElements * sizeof(T));
	if(_elements == NULL)
	{	
		exit(1);
	}
}


// Destructor
template <typename T>
Array<T>::
~Array()
{
	free(_elements);
}

// Copy constructor
template <typename T>
Array<T>::
Array(const Array<T>& srcObj)
{
	copyHelper(srcObj);
}

// Assignment operator
template <typename T>
const Array<T>& Array<T>::
operator=(const Array<T>& rhsObj)
{
	// Self-assignment check
	if (this == &rhsObj)
	{
		return (*this);
	}
	
	// Free old memory
	free(_elements);
	
	// Copy new memory
	copyHelper(rhsObj);
	
	return (*this);
}

// Copy helper function
template <typename T>
void Array<T>::
copyHelper(const Array<T>& srcObj)
{
	int iElem;
	
	_length = srcObj._length;
	_nElements = srcObj._nElements;

	_elements = (T*)malloc(_nElements * sizeof(T));
	if(_elements == NULL)
	{	
		exit(1);
	}
	
	for (iElem = 0; iElem < _nElements; iElem++)
	{
		_elements[iElem] = srcObj._elements[iElem];
	}
}

//------------------------------------------------------------------------------
// Overloaded Operators
//------------------------------------------------------------------------------
template <typename T>
T& Array<T>::
operator[](int index)
{
	if (index < 0)
	{
		// Invalid index
		exit(1);
	}
	
	if (index >= _nElements) // Allocate a larger array
	{
		resize(_nElements + _allocSize);
	}
	
	if (index >= _length)
	{
		_length = index + 1;
	}
	
	return (_elements[index]);
}

template <typename T>
const T& Array<T>::
operator[](int index) const
{
	if (index < 0 || index >= _length)
	{
		// Invalid index
		exit(1);
	}
	return (_elements[index]);
}

//------------------------------------------------------------------------------
// Public Member Functions
//------------------------------------------------------------------------------
template <typename T>
int Array<T>::
length()
{
	return (_length);
}

template <typename T>
void Array<T>::
remove(int index)
{
	int iElem;
	
	// Loop through elements below index
	for (iElem = index; iElem < _length - 1; iElem++)
	{
		_elements[iElem] = _elements[iElem + 1];
	}
	_elements[_length] = NULL;
	_length -= 1;
}

template <typename T>
void Array<T>::
sort()
{
	int iElem;
	int jElem;
	T tmp;
	
	// Loop through elements
	for (iElem = 1; iElem < _length; iElem++)
	{
		for (jElem = iElem; jElem > 0; jElem--)
		{
			if (_elements[jElem] > _elements[jElem - 1]) // Switch
			{
				tmp = _elements[jElem];
				_elements[jElem] = _elements[jElem - 1];
				_elements[jElem - 1] = tmp;
			}
			else
			{
				break;
			}
		}
	}
}

template <typename T>
T Array<T>::
minimum()
{
	int iElem;
	T minVal = _elements[0];
	
	// Loop through elements
	for (iElem = 1; iElem < _length; iElem++)
	{
		if (_elements[iElem] < minVal) // Update min value
		{
			minVal = _elements[iElem];
		}
	}
	
	return(minVal);
}

template <typename T>
T Array<T>::
maximum()
{
	int iElem;
	T maxVal = _elements[0];
	
	// Loop through elements
	for (iElem = 1; iElem < _length; iElem++)
	{
		if (_elements[iElem] > maxVal) // Update max value
		{
			maxVal = _elements[iElem];
		}
	}
	
	return(maxVal);
}

template <typename T>
T Array<T>::
sum()
{
	int iElem;
	T sumVal = _elements[0];
	
	// Loop through elements
	for (iElem = 1; iElem < _length; iElem++)
	{	
		sumVal += _elements[iElem]; // Update sum value
	}
	
	return(sumVal);
}

template <typename T>
T Array<T>::
mean()
{
	T meanVal = sum()/_length;
	
	return(meanVal);
}

template <typename T>
T Array<T>::
median()
{
	int medInd = (_length + 1) / 2 - 1;
	Array<T> tmpArray = *this;
	tmpArray.sort();
	T medianVal = tmpArray[medInd];

	return(medianVal);
}

//------------------------------------------------------------------------------
// Protected Member Functions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Private Member Functions
//------------------------------------------------------------------------------
template <typename T>
void Array<T>::
resize(int newSize)
{
	int iElem;
	
	// Create new memory
	T* newElems = (T*)malloc(newSize * sizeof(T));
	if(newElems == NULL)
	{	
		exit(1);
	}
	
	
	// Copy from current array
	for (iElem = 0; iElem < _length; iElem++)
	{
		newElems[iElem] = _elements[iElem];
	}
	
	// Store new size
	_nElements = newSize;
	
	// Delete current array
	free(_elements);
	
	// Point to new array
	_elements = newElems;
}
