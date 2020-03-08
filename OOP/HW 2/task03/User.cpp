#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include <cstring>
#include <iostream>
using namespace std;

User::User() : Guest()
{
	username = new char[2];
	username[0] = ' ';
	username[1] = '\0';

	password = new char[2];
	password[0] = ' ';
	password[1] = '\0';

	title = new char[2];
	title[0] = ' ';
	title[1] = '\0';
}

User::User(const char * usernamePar, const char * passwordPar, const char * titlePar, const char * ipAddressPar) : Guest(ipAddressPar)
{
	if (usernamePar == nullptr) {
		cout << "Error! Nullptr! " << endl;
		username = new char[2];
		username[0] = ' ';
		username[1] = '\0';
	}
	else {
		username = new char[strlen(usernamePar) + 1];
		strcpy(username, usernamePar);
	}

	if (passwordPar == nullptr) {
		cout << "Error! Nullptr! " << endl;
		password = new char[2];
		password[0] = ' ';
		password[1] = '\0';
	}
	else {
		password = new char[strlen(passwordPar) + 1];
		password = encryptPassword(passwordPar);
	}

	if (titlePar == nullptr) {
		cout << "Error! Nullptr! " << endl;
		title = new char[2];
		title[0] = ' ';
		title[1] = '\0';
	}
	else {
		title = new char[strlen(titlePar) + 1];
		strcpy(title, titlePar);
	}
}

User::~User()
{
	delete[] username;
	delete[] password;
	delete[] title;
}

char * User::encryptPassword(const char * pass)
{
	// Source: http://www.cplusplus.com/forum/articles/38516/
	if (pass == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return nullptr;
	}

	int len = strlen(pass);
	char keyToEncrypt = 's'; //remember 115 in ascii
	char * encryptedPass = new char[len + 1];

	strcpy(encryptedPass, pass);

	for (int i = 0; i < len; i++)
	{
		encryptedPass[i] ^= keyToEncrypt;
	}
	
	return encryptedPass;
}

const char * User::getPassword() const
{
	return password;
}

const char * User::getUsername() const
{
	return username;
}

const char * User::getTitle() const
{
	return title;
}

void User::changePassword(const char * oldPass, const char * newPass)
{
	if (oldPass == nullptr || newPass == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}

	char * tempEncryptedOldPass = encryptPassword(oldPass);

	if (strcmp(password, tempEncryptedOldPass) != 0) {
		cout << "Your old password and given are not same!";
		delete[] tempEncryptedOldPass;
		return;
	}
	else {
		delete[] password;
		delete[] tempEncryptedOldPass;

		password = encryptPassword(newPass);
	}
}
