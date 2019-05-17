#pragma once

int const FIRST_CAPACITY = 20;

class IntStack {
private:
	int * elements;
	int top;
	int size;
	
	void expand();
public:
	IntStack();
	IntStack(const IntStack & obj);
	IntStack & operator=(const IntStack & obj);

	bool isFull() const;
	bool isEmpty() const;

	int peek() const;
	void push(int num);
	int pop();

	int getTotalElements() const;

	void print() const;

	friend void sortStack(IntStack & obj);

	~IntStack();
};