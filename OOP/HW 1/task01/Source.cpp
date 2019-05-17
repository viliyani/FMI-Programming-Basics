#include <iostream>
#include "IntStack.h"
using namespace std;

int main()
{
	int n, temp;
	IntStack myStack;

	cout << "How many elements you will enter: " << endl;
	cin >> n;

	cout << "Now, please enter " << n << " elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		myStack.push(temp);
	}

	cout << endl << endl;

	myStack.print();
	sortStack(myStack);
	myStack.print();

	system("pause");
	return 0;
}