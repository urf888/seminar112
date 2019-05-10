#include "DynamicVector.h"

DynamicVector<int> initDVForTests()
{
	DynamicVector<int> d;
	d.add(1);
	d.add(2);

	return d;
}

void test_operatorEqual()
{
	DynamicVector<int> d1 = initDVForTests();

	DynamicVector<int> d2;
	d2.add(3);
	d2.add(4);

	d1 = d2;

	assert(d1.getElems()[0] == 3);
	assert(d2.getElems()[1] == 4);
}

void test_add()
{
	DynamicVector<int> d1 = initDVForTests();

	d1.add(3);

	assert(d1.getElems()[2] == 3);
}


void test_getSize()
{
	DynamicVector<int> d1 = initDVForTests();
	assert(d1.getSize() == 2);
	d1.add(222);
	assert(d1.getSize() == 3);
}

void test_getElems()
{
	DynamicVector<int> d1 = initDVForTests();
	int arr[2]{ 1,2 };
	assert(d1.getElems()[0] == arr[0]);
	assert(d1.getElems()[1] == arr[1]);
}

void test_operatorPlus()
{
	DynamicVector<int> d1 = initDVForTests();
	int x{ 3 };
	d1 = d1 + x;
	assert(d1.getElems()[0] == 1);
	assert(d1.getElems()[1] == 2);
	assert(d1.getElems()[2] == 3);
}

void test_resize()
{
	DynamicVector<int> d1 = initDVForTests();
	assert(d1.getCapacity() == 10);
	d1.add(3);
	d1.add(3);
	d1.add(3);
	d1.add(3);
	d1.add(3);
	d1.add(3);
	d1.add(3);
	d1.add(3);
	assert(d1.getCapacity() == 10);
	d1.add(3);
	assert(d1.getCapacity() == 20);
}
