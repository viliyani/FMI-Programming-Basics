#include <iostream>
#include "Guest.h"
#include "Admin.h"
using namespace std;

int main()
{
	Admin manager("John Doe","qwerty","The Boss","192.25.53.103");
	VIP Peter("Peter", "123456", "The VIP", "78.234.22.14");
	PowerUser George("George", "^a!353_Sdf@", "Newbie", "125.43.42.12");

	manager.print();

	manager.recieveReputation(Peter.getUsername());
	manager.recieveReputation(George.getUsername());
	manager.changeUsername("John The Boss");

	manager.print();

	manager.changeOtherUsername(George, "Gosho");

	George.print();

	system("pause");
	return 0;
}