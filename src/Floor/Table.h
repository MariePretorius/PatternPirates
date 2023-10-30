#ifndef TABLE_H
#define TABLE_H

#include "iostream"
#include <list>
#include "Customer.h"

using namespace std;

class Table {

private:
	int tableNumber;
	int capacity;
	list<Customer> customers;

public:
	Table(int tableNumber, int capacity);
	
	void assignCustomers(list<Customer> customers);

	void removeCustomers(list<Customer> customers);

	list<Customer> getCustomers();

	int getCapacity();
};

#endif
