#include "Store.h"

bool Store::isFull() const
{
	return totalProducts >= capacity;
}

void Store::expand()
{
	int newCapacity = capacity * 2;
	Product * newProducts = new Product[newCapacity];

	for (int i = 0; i < totalProducts; i++) {
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

Store::Store() : capacity(FIRST_CAPACITY), totalProducts(0)
{
	products = new Product[capacity];
}

Store::~Store()
{
	delete[] products;
}

int Store::isProductExistsBySku(int skuPar)
{
	for (int i = 0; i < totalProducts; i++) {
		if (products[i].getSku() == skuPar) {
			return i;
			break;
		}
	}
	return -1;
}

void Store::addProduct(const Product & obj)
{
	if (isFull()) {
		expand();
	}

	products[totalProducts++] = obj;
}

void Store::deleteProduct()
{
	int findSku = 0;
	int index = 0;

	cout << endl;
	cout << "Enter SKU: ";

	findSku = inputInt();
	index = isProductExistsBySku(findSku);

	if (totalProducts == 0 || index == -1) {
		cout << "*** No products to be deleted." << endl;
	}
	else {
		if (index != (totalProducts - 1)) {
			products[index] = products[--totalProducts];
		}
		else {
			totalProducts--;
		}
		cout << "--> Product has been deleted!";
	}
}

void Store::createProduct()
{
	Product newProduct;
	newProduct.initialize();
	addProduct(newProduct);

	cout << "--> New product is added!" << endl;
}

void Store::updateProduct()
{
	int findSku = inputInt();
	int index = isProductExistsBySku(findSku);

	if (index == -1) {
		cout << "*** Product with SKU = " << findSku << " is not found in our store!" << endl;
	}
	else {
		products[index].update();

		cout << "--> Product is updated!" << endl;
	}
	
}

void Store::displayProducts() const
{
	if (totalProducts > 0) {
		print();
	}
	else {
		cout << "*** No products in the store at the moment!";
	}
}

void Store::print() const
{
	cout << endl;
	cout << "### SUPER LAPTOP ONLINE STORE ###" << endl;

	for (int i = 0; i < totalProducts; i++) {
		products[i].print();
	}

	cout << endl;
}

int Store::inputInt()
{
	int temp = -1;

	while (!(cin >> temp)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Bad data. Try again: ";
	}

	return temp;
}
