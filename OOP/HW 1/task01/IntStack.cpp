#include "IntStack.h"
#include <iostream>
using namespace std;

IntStack::IntStack() : size(FIRST_CAPACITY), top(-1)
{
	elements = new int[size];
}

IntStack::IntStack(const IntStack & obj) : top(obj.top), size(obj.size)
{
	elements = new int[size];
	if (!obj.isEmpty()) {
		for (int i = 0; i <= top; i++) {
			elements[i] = obj.elements[i];
		}
	}
}

IntStack & IntStack::operator=(const IntStack & obj)
{
	if (this != &obj)
	{
		delete[] elements;

		size = obj.size;
		top = obj.top;

		elements = new int[size];
		if (!obj.isEmpty()) {
			for (int i = 0; i <= top; i++) {
				elements[i] = obj.elements[i];
			}
		}
	}
	return *this;
}

void IntStack::expand()
{
	int newSize = size * 2;
	int * newElements = new int[newSize];

	for (int i = 0; i <= top; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

bool IntStack::isFull() const
{
	if ((top + 1) >= size) {
		return true;
	}
	else {
		return false;
	}
}

bool IntStack::isEmpty() const
{
	return top == -1;
}

int IntStack::peek() const
{
	if (isEmpty()) {
		cout << "Empty stack" << endl;
		return -1;
	}
	return elements[top];
}

void IntStack::push(int num)
{
	if (isFull()) {
		expand();
	}

	elements[++top] = num;
}

int IntStack::pop()
{
	if (isEmpty()) {
		cout << "Empty stack" << endl;
		return -1;
	}
	return elements[top--];
}

int IntStack::getTotalElements() const
{
	return top + 1;
}

void IntStack::print() const
{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else {
		for (int i = top; i >= 0; i--)
		{
			cout << elements[i] << endl;
		}
	}
	cout << endl;
}

IntStack::~IntStack()
{
	delete[] elements;
}

void sortStack(IntStack & obj)
{
	int size = obj.top;

	for (int i = 0; i <= size; i++) {
		for (int j = i + 1; j <= size; j++)
		{
			if (obj.elements[i] > obj.elements[j])
			{
				int swap = obj.elements[i];
				obj.elements[i] = obj.elements[j];
				obj.elements[j] = swap;
			}
		}
	}
}
