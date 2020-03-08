#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Guest.h"
#include <cstring>
using namespace std;

Guest::Guest()
{
	setIpAddress("none.no.ip.address");
}

Guest::Guest(const char * ipAddressPar)
{
	setIpAddress(ipAddressPar);
}

Guest::~Guest()
{
	delete[] ipAddress;
}

void Guest::setIpAddress(const char * ipAddressPar)
{
	if (ipAddressPar == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}

	delete[] ipAddress;

	ipAddress = new char[strlen(ipAddressPar) + 1];
	strcpy(ipAddress, ipAddressPar);
}

const char * Guest::getIpAddress() const
{
	return ipAddress;
}
