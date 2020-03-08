#define _CRT_SECURE_NO_WARNINGS
#include "PowerUser.h"
#include <iostream>
#include <cstring>
using namespace std;
PowerUser::PowerUser(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar) : reputation(0), User(usernamePar, passwordPar, titlePar, ipAddressPar)
{
}

void PowerUser::recieveReputation(const char * fromUsername)
{
	if (strcmp(username, fromUsername) != 0) {
		reputation += 1;
	}
}

void PowerUser::print() const
{
	cout << endl;
	cout << "___ Info ___" << endl;
	cout << "IP Address: " << getIpAddress() << endl;
	cout << "Username: " << username << endl;
	cout << "Title: " << title << endl;
	cout << "Reputation: " << reputation << endl;
	cout << endl;
}

void PowerUser::changeUsername(const char * usernamePar)
{
	if (usernamePar == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}

	delete[] username;

	username = new char[strlen(usernamePar) + 1];
	strcpy(username, usernamePar);
}
