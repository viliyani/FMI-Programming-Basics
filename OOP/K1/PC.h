#pragma once
#include "Monitor.h"

int const DEFAULT_CAPACITY = 10;

class PC {
private:
	Monitor * monitors;
	int capacity; // Total capacity of monitors
	int totalMonitors; // Total connected monitors
	char * pcSerialNumber = nullptr;

	void expand();
	bool isFull();
public:
	PC();
	PC(const char * pcSerialNumberPar);
	PC(const char * pcSerialNumberPar, int capacityPar);
	PC(const PC & obj);
	PC& operator=(const PC & obj);
	
	void addMonitor(const Monitor & obj);
	
	void setPCSerialNumber(const char * pcSerialNumberPar);

	const char * getPCSerialNumber() const;
	int getCapacity() const;
	int getTotalMonitors() const;

	bool isExists(const char * monitorSerialNumber) const;
	Monitor & operator[](int index);

	void printMonitors() const;

	~PC();
};