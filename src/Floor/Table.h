#ifndef TABLE_H
#define TABLE_H

class Table {

private:
	int tableNumber;
	int capacity;
	List<Customer> customers;

public:
	void assignCustomers(List<Customer> customers);

	void removeCustomers(List<Customer> customers);

	List<Customer> getCustomers();

	int getCapacity();
};

#endif
