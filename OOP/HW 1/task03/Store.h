#pragma once
#include "Product.h"

int const FIRST_CAPACITY = 10;

class Store {
private:
	Product * products;
	int capacity;
	int totalProducts;

	bool isFull() const;
	void expand();
public:
	Store();
	~Store();

	int isProductExistsBySku(int skuPar);

	void addProduct(const Product & obj);
	void deleteProduct();
	void createProduct();
	void updateProduct();

	void displayProducts() const;

	void print() const;

	int inputInt();
};