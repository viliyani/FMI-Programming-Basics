#define _CRT_SECURE_NO_WARNINGS
#include "Storage.h"
#include <cstring>
#include <iostream>
using namespace std;

Storage::Storage() : maxCapacity(0), currentCapacity(0)
{
	setHashcode(" ");
	setName(" ");
}

Storage::Storage(const char * hashcodePar, const char * namePar, double maxCapacityPar, double currentCapacityPar) : maxCapacity(maxCapacityPar), currentCapacity(currentCapacityPar)
{
	setHashcode(hashcodePar);
	setName(namePar);
}

Storage::Storage(const Storage & obj) : maxCapacity(obj.maxCapacity), currentCapacity(obj.currentCapacity)
{
	setHashcode(obj.hashcode);
	setName(obj.name);
}

Storage & Storage::operator=(const Storage & obj)
{
	if (this != &obj)
	{
		setHashcode(obj.getHashcode());
		setName(obj.getName());
		setMaxCapacity(obj.getMaxCapacity());
		setCurrentCapacity(obj.getCurrentCapacity());
	}
	return *this;
}

Storage::~Storage()
{
	delete[] hashcode;
	delete[] name;
}

void Storage::setHashcode(const char * hashcodePar)
{
	if (hashcodePar == nullptr)
	{
		cout << "Error! Nullptr is given!";
		return;
	}

	delete[] hashcode;

	hashcode = new char[strlen(hashcodePar) + 1];
	strcpy(hashcode, hashcodePar);
}

void Storage::setName(const char * namePar)
{
	if (namePar == nullptr)
	{
		cout << "Error! Nullptr is given!";
		return;
	}

	delete[] name;

	name = new char[strlen(namePar) + 1];
	strcpy(name, namePar);
}

void Storage::setMaxCapacity(double maxCapacityPar)
{
	maxCapacity = maxCapacityPar;
}

void Storage::setCurrentCapacity(double currentCapacityPar)
{
	currentCapacity = currentCapacityPar;
}

const char * Storage::getHashcode() const
{
	return hashcode;
}

const char * Storage::getName() const
{
	return name;
}

double Storage::getMaxCapacity() const
{
	return maxCapacity;
}

double Storage::getCurrentCapacity() const
{
	return currentCapacity;
}

void Storage::print() const
{
	cout << endl;
	cout << "Hash-code: " << hashcode << endl;
	cout << "Name: " << name << endl;
	cout << "Max Capacity: " << maxCapacity << " GB" << endl;
	cout << "Current Capacity: " << currentCapacity << " GB" << endl;
}
