#pragma once

const int DEFAULT_MAX_COUNTER = 15;

class OnlineService {
private:
	unsigned int port;
	int counter;
	int maxCounter;
public:
	OnlineService();
	OnlineService(int maxCounterPar);
	OnlineService(unsigned int portPar, int maxCounterPar);

	void setPort(unsigned int portPar);
	unsigned int getPort() const;

	void addDevice();
	void removeDevice();

	void print() const;
}; 