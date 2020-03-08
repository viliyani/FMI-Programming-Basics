#define _CRT_SECURE_NO_WARNINGS
#include "VIP.h"
#include <iostream>
#include <cstring>
using namespace std;

VIP::VIP(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar) : User(usernamePar, passwordPar, titlePar, ipAddressPar)
{
}

void VIP::changeTitle(const char * titlePar)
{
	if (titlePar == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}

	delete[] title;

	title = new char[strlen(titlePar) + 1];
	strcpy(title, titlePar);
}
