#pragma once
#include <iostream>
using namespace std;

class Monitor {
private:
	char * serialNumber = nullptr;
	int width;
	int height;
public:
	Monitor();
	Monitor(const char * serialNumberPar, int widthPar, int heightPar);
	Monitor(const Monitor & obj);
	Monitor& operator=(const Monitor & obj);

	void setSerialNumber(const char * serialNumberPar);
	void setWidth(int widthPar);
	void setHeight(int heightPar);

	const char * getSerialNumber() const;
	int getWidth() const;
	int getHeight() const;

	friend bool operator<(const Monitor & one, const Monitor & two);
	friend ostream & operator<<(ostream & out, const Monitor & obj);

	void print() const;

	~Monitor();
};