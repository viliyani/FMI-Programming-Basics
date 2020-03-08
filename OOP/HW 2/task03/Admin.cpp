#define _CRT_SECURE_NO_WARNINGS
#include "Admin.h"
#include <iostream>
#include <cstring>
using namespace std;

Admin::Admin(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar) : User(usernamePar, passwordPar, titlePar, ipAddressPar), PowerUser(usernamePar, passwordPar, titlePar, ipAddressPar), VIP(usernamePar, passwordPar, titlePar, ipAddressPar)
{
}

void Admin::changeUsername(const char * usernamePar)
{
	if (usernamePar == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}

	delete[] username;

	username = new char[strlen(usernamePar) + 1];
	strcpy(username, usernamePar);
}

void Admin::changeOtherUsername(PowerUser & obj, const char * newUsername)
{
	if (newUsername == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}


	obj.changeUsername(newUsername);
}
