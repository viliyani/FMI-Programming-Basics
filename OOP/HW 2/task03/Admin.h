#pragma once
#include "VIP.h"
#include "PowerUser.h"

class Admin : public VIP, public PowerUser {
private:

public:
	Admin(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar);

	void changeUsername(const char * usernamePar);

	void changeOtherUsername(PowerUser & obj, const char * newUsername);
};
