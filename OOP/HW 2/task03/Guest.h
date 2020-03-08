#pragma once
class Guest {
private:
	char * ipAddress = nullptr;
public:
	Guest();
	Guest(const char * ipAddressPar);
	~Guest();

	void setIpAddress(const char * ipAddressPar);
	const char * getIpAddress() const;
};