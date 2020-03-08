#include <iostream>
#include "OnlineStorage.h"
using namespace std;

int main()
{
	OnlineStorage myStorage("3u487yyd12gad21efadf","OOP-Exams-Dont-Steal", 8.00, 5.50, 5, 3.50);
	
	myStorage.setPort(80);

	myStorage.addDevice();
	myStorage.addDevice();
	myStorage.addDevice();

	myStorage.uploadFile(1300);

	myStorage.print();

	cout << "Total price for month is: " << myStorage.calcPrice() << endl;

	system("pause");
	return 0;
}