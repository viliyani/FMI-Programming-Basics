#pragma once

class DNSRecord {
private:
	char * domainName = nullptr;
	char * ipAddress = nullptr;
public:
	DNSRecord();
	DNSRecord(const char * domainNamePar, const char * ipAddressPar);
	DNSRecord(const DNSRecord & obj);

	DNSRecord & operator=(const DNSRecord & obj);

	void setDomainName(const char * domainNamePar);
	void setIpAddress(const char * ipAddressPar);

	const char * getDomainName() const;
	const char * getIpAddress() const;

	void print() const;

	~DNSRecord();
};