#pragma once
#include <random>

template <class T>
class MagicBox {
private:
	T * elements;
	int size;
	int capacity;

	bool isFull() const;
	void expand();
	int getRandNumber(int from, int to) const;
public:
	MagicBox();
	~MagicBox();

	void insert(T item);
	T pop();
	void list() const;
};

template <class T>
bool MagicBox<T>::isFull() const
{
	if (size >= capacity)
	{
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void MagicBox<T>::expand()
{
	int newCapacity = capacity * 2;
	T * newElements = new T[newCapacity];

	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;

	elements = newElements;
}

template <class T>
int MagicBox<T>::getRandNumber(int from, int to) const
{
	const int range_from = from;
	const int range_to = to;
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distr(range_from, range_to);
	int num = distr(generator);

	return num;
}

template <class T>
MagicBox<T>::MagicBox() : size(0), capacity(10)
{
	elements = new T[capacity];
}

template <class T>
MagicBox<T>::~MagicBox()
{
	delete[] elements;
}

template <class T>
void MagicBox<T>::insert(T item)
{
	if (isFull())
	{
		expand();
	}

	elements[size++] = item;
}

template <class T>
T MagicBox<T>::pop()
{
	if (size == 0) {
		cout << "Nothing to remove!" << endl;
		return -1;
	}

	int randomIndex = getRandNumber(0, (size - 1));

	int result = elements[randomIndex];

	if (randomIndex == (size - 1)) {
		size--;
	}
	else {
		elements[randomIndex] = elements[--size];
	}

	return result;
}

template <class T>
void MagicBox<T>::list() const
{
	cout << endl << "Elements are: " << endl;
	cout << "--> ";
	for (int i = 0; i < size; i++)
	{
		cout << elements[i] << "  ";
	}
	cout << endl;
}