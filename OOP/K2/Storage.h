#pragma once

class Storage {
private:
	char * hashcode = nullptr;
	char * name = nullptr;
	double maxCapacity;
	double currentCapacity;
public:
	Storage();
	Storage(const char * hashcodePar, const char * namePar, double maxCapacityPar, double currentCapacityPar);
	Storage(const Storage & obj);
	Storage & operator=(const Storage & obj);
	~Storage();

	void setHashcode(const char * hashcodePar);
	void setName(const char * namePar);
	void setMaxCapacity(double maxCapacityPar);
	void setCurrentCapacity(double currentCapacityPar);

	const char * getHashcode() const;
	const char * getName() const;
	double getMaxCapacity() const;
	double getCurrentCapacity() const;

	void print() const;
};