#pragma once
#include "DNSRecord.h"

int const FIRST_CAPACITY = 10;

class DNSCache {
private:
	DNSRecord * records;
	int capacity;
	int totalRecords;

	void expand();
public:
	DNSCache();
	DNSCache(const DNSCache & obj);
	DNSCache(const DNSRecord & obj);
	DNSCache & operator=(const DNSCache & obj);

	bool isFull() const;
	void addRecord(const DNSRecord & obj);

	const char * lookup(const char * domainNamePar) const;
	void flush();

	int getCapacity() const;
	int getTotalRecords() const;

	void print() const;

	~DNSCache();
};