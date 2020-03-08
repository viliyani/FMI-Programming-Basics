#pragma once
#include "User.h"

class VIP : virtual public User {
private:

public:
	VIP(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar);

	void changeTitle(const char * titlePar);
};