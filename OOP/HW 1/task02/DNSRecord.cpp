#define _CRT_SECURE_NO_WARNINGS
#include "DNSRecord.h"
#include <iostream>
#include <cstring>
using namespace std;

DNSRecord::DNSRecord()
{
	setDomainName(" ");
	setIpAddress(" ");
}

DNSRecord::DNSRecord(const char * domainNamePar, const char * ipAddressPar)
{
	setDomainName(domainNamePar);
	setIpAddress(ipAddressPar);
}

DNSRecord::DNSRecord(const DNSRecord & obj)
{
	setDomainName(obj.domainName);
	setIpAddress(obj.ipAddress);
}

DNSRecord & DNSRecord::operator=(const DNSRecord & obj)
{
	if (this != &obj) {
		setDomainName(obj.domainName);
		setIpAddress(obj.ipAddress);
	}

	return *this;
}

void DNSRecord::setDomainName(const char * domainNamePar)
{
	if (domainNamePar == nullptr) {
		cout << "You're giving null pointer!" << endl;
		return;
	}

	delete[] domainName;

	domainName = new char[strlen(domainNamePar) + 1];
	strcpy(domainName, domainNamePar);
}

void DNSRecord::setIpAddress(const char * ipAddressPar)
{
	if (ipAddressPar == nullptr) {
		cout << "You're giving null pointer!" << endl;
		return;
	}

	delete[] ipAddress;

	ipAddress = new char[strlen(ipAddressPar) + 1];
	strcpy(ipAddress, ipAddressPar);
}

const char * DNSRecord::getDomainName() const
{
	return domainName;
}

const char * DNSRecord::getIpAddress() const
{
	return ipAddress;
}

void DNSRecord::print() const
{
	cout << endl;
	cout << "_____ DNS RECORD _____" << endl;
	cout << "Domain Name: " << domainName << endl;
	cout << "IP Address: " << ipAddress << endl;
	cout << endl;
}

DNSRecord::~DNSRecord()
{
	delete[] domainName;
	delete[] ipAddress;
}
