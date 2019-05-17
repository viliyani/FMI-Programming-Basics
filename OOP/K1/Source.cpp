#include <iostream>
#include "PC.h"
using namespace std;

int main()
{
	Monitor lg("LG Led HD", 1280, 820);
	Monitor hp("HP ProDisplay P221", 1920, 1020);
	Monitor sony("Sony 4k", 4220, 2340);
	Monitor asus("Asus color", 1600, 600);
	Monitor acer("Acer IPS Matrix", 1980, 1200);

	PC lenovo;
	lenovo.addMonitor(lg);
	lenovo.addMonitor(hp);
	lenovo.addMonitor(sony);
	lenovo.addMonitor(asus);
	lenovo.addMonitor(acer);

	if (lenovo.isExists(lg.getSerialNumber())) {
		cout << "Yes, LG exists." << endl;
	}
	else {
		cout << "No, LG not exists." << endl;
	}

	cout << endl << endl;

	lenovo.printMonitors();

	system("pause");
	return 0;
}