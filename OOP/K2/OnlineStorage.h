#pragma once
#include "Storage.h"
#include "OnlineService.h"

class OnlineStorage : public Storage, public OnlineService {
private:
	double priceForMonthPerGB;
public:
	OnlineStorage();
	OnlineStorage(double priceForMonthPerGBPar);
	OnlineStorage(const char * hashcodePar, const char * namePar, double maxCapacityPar, double currentCapacityPar, int maxCounterPar, double priceForMonthPerGBPar);

	void uploadFile(int fileSize);

	double calcPrice();
	
	void print() const;
};