#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include <cstring>
#include <iostream>
using namespace std;

Product::Product() : sku(0), price(0.0), count(0), screen(0), hd(0), year(0)
{
	setBrand(" ");
	setModel(" ");
	setCategory(" ");
}

Product::Product(int skuPar, const char * brandPar, const char * modelPar, const char * categoryPar, double pricePar, int countPar, int screenPar, int hdPar, int yearPar) : sku(skuPar), price(pricePar), count(countPar), screen(screenPar), hd(hdPar), year(yearPar)
{
	setBrand(brandPar);
	setModel(modelPar);
	setCategory(categoryPar);
}

Product::Product(const Product & obj) : sku(obj.sku), price(obj.price), count(obj.count), screen(obj.screen), hd(obj.hd), year(obj.year)
{
	setBrand(obj.brand);
	setModel(obj.model);
	setCategory(obj.category);
}

Product & Product::operator=(const Product & obj)
{
	if (this != &obj) {
		sku = obj.sku; 
		price = obj.price;
		count = obj.count;
		screen = obj.screen;
		hd = obj.hd;
		year = obj.year;
		setBrand(obj.brand);
		setModel(obj.model);
		setCategory(obj.category);
	}
	return *this;
}

Product::~Product()
{
	delete[] brand;
	delete[] model;
	delete[] category;
}

void Product::initialize()
{
	char * tempBrand = new char[100];
	char * tempModel = new char[100];
	char * tempCategory = new char[100];

	cout << "SKU: ";
	sku = inputInt();

	cout << "Brand: ";
	cin >> tempBrand;
	setBrand(tempBrand);

	cout << "Model: ";
	cin >> tempModel;
	setModel(tempModel);

	cout << "Category: ";
	cin >> tempCategory;
	setCategory(tempCategory);

	cout << "Price: ";
	price = inputDouble();

	cout << "Count: ";
	count = inputInt();

	cout << "Screen: ";
	screen = inputInt();

	cout << "HD: ";
	hd = inputInt();

	cout << "Year: ";
	year = inputInt();

	delete[] tempBrand;
	delete[] tempModel;
	delete[] tempCategory;
}

void Product::update()
{
	char * tempBrand = new char[100];
	char * tempModel = new char[100];
	char * tempCategory = new char[100];

	cout << endl;
	cout << "-> Enter new values: " << endl;

	cout << "SKU [" << sku << "] : ";
	sku = inputInt();

	cout << "Brand [" << getBrand() << "] : ";
	cin >> tempBrand;
	setBrand(tempBrand);

	cout << "Model [" << getModel() << "] : ";
	cin >> tempModel;
	setModel(tempModel);

	cout << "Category [" << getCategory() << "] : ";
	cin >> tempCategory;
	setCategory(tempCategory);

	cout << "Price [" << price << "] : ";
	price = inputDouble();

	cout << "Count [" << count << "] : ";
	count = inputInt();

	cout << "Screen [" << screen << "] : ";
	screen = inputInt();

	cout << "HD [" << hd << "] : ";
	hd = inputInt();

	cout << "Year [" << year << "] : ";
	year = inputInt();

	delete[] tempBrand;
	delete[] tempModel;
	delete[] tempCategory;
}

void Product::setSku(int skuPar)
{
	sku = skuPar;
}

void Product::setBrand(const char * brandPar)
{
	if (brandPar == nullptr) {
		return;
	}

	delete[] brand;
	brand = new char[strlen(brandPar) + 1];
	strcpy(brand, brandPar);
}

void Product::setModel(const char * modelPar)
{
	if (modelPar == nullptr) {
		return;
	}

	delete[] model;
	model = new char[strlen(modelPar) + 1];
	strcpy(model, modelPar);
}

void Product::setCategory(const char * categoryPar)
{
	if (categoryPar == nullptr) {
		return;
	}

	delete[] category;
	category = new char[strlen(categoryPar) + 1];
	strcpy(category, categoryPar);
}

void Product::setPrice(double pricePar)
{
	price = pricePar;
}

void Product::setCount(int countPar)
{
	count = countPar;
}

void Product::setScreen(int screenPar)
{
	screen = screenPar;
}

void Product::setHd(int hdPar)
{
	hd = hdPar;
}

void Product::setYear(int yearPar)
{
	year = yearPar;
}

int Product::getSku() const
{
	return sku;
}

const char * Product::getBrand() const
{
	if (brand == nullptr) {
		char * empty = new char[1];
		empty[0] = '\0';
		return empty;
	}
	return brand;
}

const char * Product::getModel() const
{
	if (model == nullptr) {
		char * empty = new char[1];
		empty[0] = '\0';
		return empty;
	}
	return model;
}

const char * Product::getCategory() const
{
	if (category == nullptr) {
		char * empty = new char[1];
		empty[0] = '\0';
		return empty;
	}
	return category;
}

double Product::getPrice() const
{
	return price;
}

int Product::getCount() const
{
	return count;
}

int Product::getScreen() const
{
	return screen;
}

int Product::getHd() const
{
	return hd;
}

int Product::getYear() const
{
	return year;
}

void Product::print() const
{
	cout << endl;
	cout << "_____ LAPTOP _____" << endl;
	cout << "SKU: " << sku << endl;
	cout << "Brand: " << getBrand() << endl;
	cout << "Model: " << getModel() << endl;
	cout << "Category: " << getCategory() << endl;
	cout << "Price: " << price << endl;
	cout << "Count: " << count << endl;
	cout << "Screen: " << screen << endl;
	cout << "HDD: " << hd << endl;
	cout << "Year: " << year << endl;
	cout << endl;
}

int Product::inputInt()
{
	int temp = -1;

	while (!(cin >> temp)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Bad data. Try again: ";
	}

	return temp;
}

double Product::inputDouble()
{
	double temp = -1;

	while (!(cin >> temp)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Bad data. Try again: ";
	}

	return temp;
}

std::ostream & operator<<(std::ostream & out, Product & obj)
{
	obj.print();
	return out;
}
