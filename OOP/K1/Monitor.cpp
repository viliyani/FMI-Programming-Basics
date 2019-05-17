#define _CRT_SECURE_NO_WARNINGS
#include "Monitor.h"
#include <iostream>
#include <cstring>
using namespace std;

Monitor::Monitor() : width(0), height(0)
{
	setSerialNumber(" ");
}

Monitor::Monitor(const char * serialNumberPar, int widthPar, int heightPar) : width(widthPar), height(heightPar)
{
	setSerialNumber(serialNumberPar);
}

Monitor::Monitor(const Monitor & obj) : width(obj.width), height(obj.height)
{
	setSerialNumber(obj.serialNumber);
}

Monitor & Monitor::operator=(const Monitor & obj)
{
	if (this != &obj)
	{
		if (serialNumber != nullptr) {
			delete[] serialNumber;
		}

		serialNumber = new char[strlen(obj.serialNumber) + 1];
		strcpy(serialNumber, obj.serialNumber);
		
		width = obj.width;
		height = obj.height;
	}

	return *this;
}

void Monitor::setSerialNumber(const char * serialNumberPar)
{
	if (serialNumberPar == nullptr) {
		return;
	}

	delete[] serialNumber;
	
	serialNumber = new char[strlen(serialNumberPar) + 1];
	strcpy(serialNumber, serialNumberPar);
}

void Monitor::setWidth(int widthPar)
{
	width = widthPar;
}

void Monitor::setHeight(int heightPar)
{
	height = heightPar;
}

const char * Monitor::getSerialNumber() const
{
	return serialNumber;
}

int Monitor::getWidth() const
{
	return width;
}

int Monitor::getHeight() const
{
	return height;
}

void Monitor::print() const
{
	cout << endl;
	cout << "Serial number: " << serialNumber << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << endl;
}

Monitor::~Monitor()
{
	delete[] serialNumber;
}

bool operator<(const Monitor & one, const Monitor & two)
{
	if (one.width == two.width) {
		if (one.height < two.height) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (one.width < two.width) {
			return true;
		}
		else {
			return false;
		}
	}
}

ostream & operator<<(ostream & out, const Monitor & obj)
{
	out << endl;
	out << "______ MONITOR INFO ______" << endl;
	out << "Serial number: " << obj.getSerialNumber() << endl;
	out << "Width: " << obj.getWidth() << endl;
	out << "Height: " << obj.getHeight() << endl;
	out << endl;

	return out;
}
