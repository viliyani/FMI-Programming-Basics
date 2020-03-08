#include <iostream>
#include <random>
#include "MagicBox.h"
using namespace std;

int main()
{
	// Box of integers
	MagicBox<int> myBox;
	
	myBox.insert(1);
	myBox.insert(2);
	myBox.insert(3);
	myBox.insert(4);
	myBox.insert(5);

	myBox.list();

	cout << endl << "[-] Remove: " << myBox.pop() << endl;
	cout << endl << "[-] Remove: " << myBox.pop() << endl;
	cout << endl << "[-] Remove: " << myBox.pop() << endl;

	myBox.list();

	// Box of chars
	MagicBox<char> myCharsBox;

	myCharsBox.insert('a');
	myCharsBox.insert('b');
	myCharsBox.insert('c');
	myCharsBox.insert('d');

	myCharsBox.list();

	cout << endl << "[-] Remove: " << myCharsBox.pop() << endl;
	cout << endl << "[-] Remove: " << myCharsBox.pop() << endl;

	myCharsBox.list();

	system("pause");
	return 0;
}