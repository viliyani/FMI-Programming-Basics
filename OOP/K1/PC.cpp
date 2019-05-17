#define _CRT_SECURE_NO_WARNINGS
#include "PC.h"
#include <iostream>
#include <cstring>
using namespace std;

PC::PC() : capacity(DEFAULT_CAPACITY), totalMonitors(0)
{
	monitors = new Monitor[capacity];
	setPCSerialNumber(" ");
}

PC::PC(const char * pcSerialNumberPar) : capacity(DEFAULT_CAPACITY), totalMonitors(0)
{
	monitors = new Monitor[capacity];
	setPCSerialNumber(pcSerialNumberPar);
}

PC::PC(const char * pcSerialNumberPar, int capacityPar) : totalMonitors(0)
{
	monitors = new Monitor[capacity];
	setPCSerialNumber(pcSerialNumberPar);
	capacity = capacityPar;
}

PC::PC(const PC & obj) : capacity(obj.capacity), totalMonitors(obj.totalMonitors)
{
	if (totalMonitors > 0) {
		monitors = new Monitor[totalMonitors];

		for (int i = 0; i < totalMonitors; i++)
		{
			monitors[i] = obj.monitors[i];
		}
	}
	else {
		monitors = new Monitor[capacity];
	}

	setPCSerialNumber(obj.pcSerialNumber);
}

PC & PC::operator=(const PC & obj)
{
	if (this != &obj) {
		delete[] monitors;

		capacity = obj.capacity;
		totalMonitors = obj.totalMonitors;
		setPCSerialNumber(obj.pcSerialNumber);
		
		monitors = new Monitor[capacity];

		for (int i = 0; i < totalMonitors; i++) {
			monitors[i] = obj.monitors[i];
		}
	}

	return *this;
}

void PC::expand()
{
	int newCapacity = capacity * 2;

	Monitor * newMonitors;
	newMonitors = new Monitor[newCapacity];

	for (int i = 0; i < totalMonitors; i++) {
		newMonitors[i] = monitors[i];
	}

	delete[] monitors;

	monitors = newMonitors;
}

bool PC::isFull()
{
	if (totalMonitors >= capacity) {
		return true;
	}
	else {
		return false;
	}
}

void PC::addMonitor(const Monitor & obj)
{
	if (isFull())
	{
		expand();
	}

	monitors[totalMonitors++] = obj;
}

void PC::setPCSerialNumber(const char * pcSerialNumberPar)
{
	if (pcSerialNumberPar == nullptr) {
		return;
	}

	delete[] pcSerialNumber;

	pcSerialNumber = new char[strlen(pcSerialNumberPar) + 1];
	strcpy(pcSerialNumber, pcSerialNumberPar);
}

const char * PC::getPCSerialNumber() const
{
	return pcSerialNumber;
}

int PC::getCapacity() const
{
	return capacity;
}

int PC::getTotalMonitors() const
{
	return totalMonitors;
}

bool PC::isExists(const char * monitorSerialNumber) const
{
	for (int i = 0; i < totalMonitors; i++) {
		if (strcmp(monitorSerialNumber, monitors[i].getSerialNumber()) == 0) {
			return true;
		}
	}
	return false;
}

Monitor & PC::operator[](int index)
{
	return monitors[index];
}

void PC::printMonitors() const
{
	cout << endl;
	cout << "______ PC INFO ______" << endl;
	cout << "Total Monitors: " << totalMonitors << endl;
	
	for (int i = 0; i < totalMonitors; i++) {
		cout << "Monitor " << (i + 1) << endl;
		cout << monitors[i];
	}

	cout << endl;
}

PC::~PC()
{
	delete[] monitors;
	delete[] pcSerialNumber;
}
