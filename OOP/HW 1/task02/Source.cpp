#include <iostream>
#include "DNSRecord.h"
#include "DNSCache.h"
using namespace std;

int main()
{
	DNSRecord google("google.bg", "64.233.191.216");
	DNSRecord facebook("facebook.com", "204.15.23.232");
	DNSRecord fmi("fmi.uni-sofia.bg", "62.44.101.138");
	
	DNSCache myCache;
	myCache.addRecord(google);
	myCache.addRecord(facebook);
	myCache.addRecord(fmi);
	myCache.print();

	cout << myCache.lookup("facebook.com") << endl;

	system("pause");
	return 0;
}