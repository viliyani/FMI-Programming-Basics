#pragma once
#include <iostream>
using namespace std;

// My product is Laptop
class Product {
private:
	int sku;
	char * brand = nullptr;
	char * model = nullptr;
	char * category = nullptr;
	double price;
	int count;
	int screen; // Screen Sizes in inches
	int hd; // Hard Drive Size in GB
	int year; // Year of production
public:
	Product();
	Product(int skuPar, const char * brandPar, const char * modelPar, const char * categoryPar, double pricePar, int countPar, int screenPar, int hdPar, int yearPar);
	Product(const Product & obj);
	Product & operator=(const Product & obj);
	~Product();

	void initialize();
	void update();

	void setSku(int skuPar);
	void setBrand(const char * brandPar);
	void setModel(const char * modelPar);
	void setCategory(const char * categoryPar);
	void setPrice(double pricePar);
	void setCount(int countPar);
	void setScreen(int screenPar);
	void setHd(int hdPar);
	void setYear(int yearPar);
	
	int getSku() const;
	const char * getBrand() const;
	const char * getModel() const;
	const char * getCategory() const;
	double getPrice() const;
	int getCount() const;
	int getScreen() const;
	int getHd() const;
	int getYear() const;
	
	void print() const;

	int inputInt();
	double inputDouble();

	friend std::ostream & operator<<(std::ostream & out, Product & obj);
};