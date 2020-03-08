#pragma once
#include "Guest.h"

class User : public Guest {
protected:
	char * username = nullptr;
	char * password = nullptr;
	char * title = nullptr;
public:
	User();
	User(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar);
	~User();

	char * encryptPassword(const char * pass);

	const char * getPassword() const;
	const char * getUsername() const;
	const char * getTitle() const;

	void changePassword(const char * oldPass, const char * newPass);
};