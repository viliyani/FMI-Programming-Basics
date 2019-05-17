#define _CRT_SECURE_NO_WARNINGS
#include "DNSCache.h"
#include <iostream>
#include <cstring>
using namespace std;

void DNSCache::expand()
{
	int newCapacity = capacity * 2;
	DNSRecord * newRecords;
	newRecords = new DNSRecord[newCapacity];

	for (int i = 0; i < totalRecords; i++) {
		newRecords[i] = records[i];
	}

	delete[] records;

	records = newRecords;
}

DNSCache::DNSCache() : capacity(FIRST_CAPACITY), totalRecords(0)
{
	records = new DNSRecord[capacity];
}

DNSCache::DNSCache(const DNSCache & obj) : capacity(obj.capacity), totalRecords(obj.totalRecords)
{
	delete[] records;

	for (int i = 0; i < totalRecords; i++) {
		records[i] = obj.records[i];
	}
}

DNSCache::DNSCache(const DNSRecord & obj) : capacity(FIRST_CAPACITY), totalRecords(0)
{
	addRecord(obj);
}

DNSCache & DNSCache::operator=(const DNSCache & obj)
{
	if (this != &obj) {
		delete[] records;

		capacity = obj.capacity;
		totalRecords = obj.totalRecords;

		for (int i = 0; i < totalRecords; i++) {
			records[i] = obj.records[i];
		}
	}
	return *this;
}

int DNSCache::getCapacity() const
{
	return capacity;
}

int DNSCache::getTotalRecords() const
{
	return totalRecords;
}

void DNSCache::print() const
{
	cout << endl;
	cout << "### DNS CACHE ###" << endl;
	
	for (int i = 0; i < totalRecords; i++) {
		records[i].print();
	}

	cout << endl;
}

DNSCache::~DNSCache()
{
	delete[] records;
}

bool DNSCache::isFull() const
{
	return totalRecords >= capacity;
}

void DNSCache::addRecord(const DNSRecord & obj)
{
	if (isFull())
	{
		expand();
	}

	records[totalRecords++] = obj;
}

const char * DNSCache::lookup(const char * domainNamePar) const
{	
	for (int i = 0; i < totalRecords; i++) {
		if (strcmp(domainNamePar, records[i].getDomainName()) == 0) {
			return records[i].getIpAddress();
		}
	}

	char * nullResult;
	nullResult = "NULL";

	return nullResult;
}

void DNSCache::flush()
{
	delete[] records;

	capacity = FIRST_CAPACITY;
	totalRecords = 0;
}
