#include "OnlineStorage.h"
#include <cmath>
#include <iostream>
using namespace std;

OnlineStorage::OnlineStorage() : Storage(), OnlineService(), priceForMonthPerGB(1.00)
{
	cout << "WARNING!!! Price for month is not given! So we make your price for month per GB to be 1" << endl;
}

OnlineStorage::OnlineStorage(double priceForMonthPerGBPar) : Storage(), OnlineService(), priceForMonthPerGB(priceForMonthPerGBPar)
{
}

OnlineStorage::OnlineStorage(const char * hashcodePar, const char * namePar, double maxCapacityPar, double currentCapacityPar, int maxCounterPar, double priceForMonthPerGBPar) : Storage(hashcodePar, namePar, maxCapacityPar, currentCapacityPar), OnlineService(maxCounterPar), priceForMonthPerGB(priceForMonthPerGBPar)
{
}

void OnlineStorage::uploadFile(int fileSize)
{
	// Convert given MB to GB
	double newCapacityToAdd = (fileSize / 1024);

	setCurrentCapacity(getCurrentCapacity() + newCapacityToAdd);
}

double OnlineStorage::calcPrice()
{
	double price = (round(getCurrentCapacity()) * priceForMonthPerGB);
	return price;
}

void OnlineStorage::print() const
{
	cout << endl;
	cout << "___ Online Storage ___";
	
	Storage::print();
	OnlineService::print();

	cout << "Price For Month Per GB: " << priceForMonthPerGB << endl;
}
