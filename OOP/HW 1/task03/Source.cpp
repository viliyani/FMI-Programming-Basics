#include <iostream>
#include "Store.h"
using namespace std;

char askForOption() {
	
	char c;

	cout << endl;
	cout << "______________________________" << endl;
	cout << "|      CHOOSE AN OPTION:      |" << endl;
	cout << "|#############################|" << endl;
	cout << "|                             |" << endl;
	cout << "|   A     Add new product     |" << endl;
	cout << "|   X     Delete product      |" << endl;
	cout << "|   C     Change product      |" << endl;
	cout << "|   D     Display product     |" << endl;
	cout << "|   Q     Quit                |" << endl;
	cout << "|_____________________________|" << endl;
	cout << endl;

	cout << endl;
	cout << "ENTER OPTION: " << endl;

	cin >> c;

	return c;
}

int main()
{
	cout << endl;
	cout << "### SUPER LAPTOP ONLINE STORE ###";
	cout << endl;

	Store myStore;
	char option = 'n'; // n = nothing 

	while (option != 'Q') {
		system("CLS");
		
		switch (option) {
			case 'A':
				cout << "--> Add New Product: " << endl;
				myStore.createProduct();
				break;
			case 'X':
				cout << "--> Delete Product: " << endl;
				myStore.deleteProduct();
				break;
			case 'C':
				cout << "--> Change Product: " << endl;
				cout << "Enter SKU: ";
				myStore.updateProduct();
				break;
			case 'D':
				myStore.displayProducts();
				break;
			default:
				break;
		};

		option = askForOption();
	}

	system("pause");
	return 0;
}