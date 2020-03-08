#pragma once
#include "User.h"

class PowerUser : virtual public User {
private:
	int reputation = 0;
public:
	PowerUser(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar);

	void recieveReputation(const char * fromUsername);

	void print() const;

	void changeUsername(const char * usernamePar);
		
};