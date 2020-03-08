#include "OnlineService.h"
#include <iostream>
using namespace std;

OnlineService::OnlineService() : port(0), counter(0), maxCounter(DEFAULT_MAX_COUNTER)
{
}

OnlineService::OnlineService(int maxCounterPar) : port(0), counter(0), maxCounter(maxCounterPar)
{
}

OnlineService::OnlineService(unsigned int portPar, int maxCounterPar) : port(portPar), counter(0), maxCounter(maxCounterPar)
{
}

void OnlineService::setPort(unsigned int portPar)
{
	port = portPar;
}

unsigned int OnlineService::getPort() const
{
	return port;
}

void OnlineService::addDevice()
{
	if (counter >= maxCounter) {
		cout << "Impossible add!" << endl;
	}
	else {
		cout << "Success add!" << endl;

		counter++;
	}
}

void OnlineService::removeDevice()
{
	if (counter == 0)
	{
		cout << "Nothing to remove!" << endl;
	}
	else {
		counter--;
	}
}

void OnlineService::print() const
{
	cout << "Port: " << port << endl;
	cout << "Connected devices: " << counter << endl;
	cout << "Maximum capacity devices: " << maxCounter << endl;
}
