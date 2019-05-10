#pragma once
#include <string>
#include <assert.h>
using namespace std;

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;
public:

	///  The constructor of a dynamic vector
	//input: 
	//	 givenCapacity - an integer
	//output: 
	//	 creates an object of type DynamicVector
	DynamicVector(int givenCapacity = 10);

	///  The copy constructor of a dynamic vector
	//input: 
	//	 givenV - a reference to a constant dynamic vector
	//output: 
	//	 creates an object of type DynamicVector
	DynamicVector(const DynamicVector& givenV);

	/// The destructor of a dynamic vector
	//input: 
	//	 -
	//output: 
	//	the dynamic vector that calls this function will be destroyed
	~DynamicVector();

	/// The assignment operator of a dynamic vector
	//input: 
	//	 givenV - a reference to a constant dynamic vector
	//output: 
	//	 the dynamic vector that calls this function will get the values contained in givenV
	DynamicVector& operator=(const DynamicVector& givenV);

	/// Adds an element to the dynamic vector
	//input: 
	//	 givenE - a reference to a constant object of type TElem
	//output: 
	//	 the given element will be added to the dynamic vector that calls this function
	void add(const T& givenE);

	/// Deletes a movie from the dynamic vector
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie to be deleted
	//output: 
	//	 0 - if the movie is successfully deleted
	//	 1 - otherwise
	bool delMovie(const string& givenTitle);

	/// Updates a movie from the dynamic vector
	//input: 
	//	 givenTitle - a reference to a constant string - the title of the movie to be updated
	//	 givenNewEl - an object of type TElem - it will take the place of the old movie
	//output: 
	//	 true - if the update was successful
	//	 false - otherwise
	bool update(const string& givenTitle, T givenNewEl);

	/// Returns the size of a dynamic vector
	//input: 
	//	 -
	//output: 
	//	 size - an integer
	int getSize() const { return size; }

	/// Returns the capacity of a dynamic vector
	//input: 
	//	 -
	//output: 
	//	 capacity - an integer
	int getCapacity() const { return capacity; }

	/// Returns the array of elements from the dynamic vector
	//input: 
	//	 -
	//output: 
	//	 a pointer to an array of objects of type TElem
	T* getElems() const { return this->elems; }

	/// Returns the dynamic vector obtained by appending to the current dynamic 
	/// vector an element that is taken as an argument
	//input: 
	//	 givenElem - a reference to a constant object of type T - the element to be appended
	//output: 
	//	 an object of type DynamicVector
	DynamicVector operator+(const T& givenElem);          // Activity 5

private:

	/// Increases the capacity of the dynamic vector
	//input: 
	//	 givenFactor - a number of type double - the capacity will be multiplied by it
	//output: 
	//	 -
	void resize(double givenFactor = 2);

public:

	/// Tests the functions from dynamic vector
	//input: 
	//	 -
	//output: 
	//	 if a function doesn't function properly, an exception will be thrown
	void dynamicVectorTests();
};

template<typename T>
DynamicVector<T>::DynamicVector(int givenCapacity)
{
	this->capacity = givenCapacity;
	this->size = 0;
	this->elems = new T[givenCapacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& givenV)
{
	this->size = givenV.size;
	this->capacity = givenV.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = givenV.elems[i];
	}
}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& givenV)
{
	if (this == &givenV)
	{
		return *this;
	}
	this->size = givenV.size;
	this->capacity = givenV.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = givenV.elems[i];
	}

	return *this;
}

template<typename T>
void DynamicVector<T>::add(const T& givenE)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}
	this->elems[this->size++] = givenE;
}

template<typename T>
bool DynamicVector<T>::delMovie(const string& givenTitle)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i].getTitle() == givenTitle)
		{
			for (int j = i; j < this->size - 1; j++)
			{
				this->elems[j] = this->elems[j + 1];
			}
			this->size--;
			return true;
		}
	}
	return false;
}

template<typename T>
bool DynamicVector<T>::update(const string& givenTitle, T givenNewEl)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i].getTitle() == givenTitle)
		{
			this->elems[i] = givenNewEl;
			return true;
		}
	}
	return false;
}



template<typename T>
DynamicVector<T> DynamicVector<T>::operator+(const T& givenElem)
{
	DynamicVector dv = *this;
	dv.add(givenElem);
	return dv;
}

template<typename T>
void DynamicVector<T>::resize(double givenFactor)
{
	this->capacity *= static_cast<int>(givenFactor);
	T* newElems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		newElems[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = newElems;
}

//-============================================Tests============================================-\\

DynamicVector<int> initDVForTests();
void test_operatorEqual();
void test_add();
void test_getSize();
void test_getElems();
void test_operatorPlus();
void test_resize();


template<typename T>
void DynamicVector<T>::dynamicVectorTests()
{
	test_operatorEqual();
	test_add();
	test_getSize();
	test_getElems();
	test_operatorPlus();
	test_resize();
}
