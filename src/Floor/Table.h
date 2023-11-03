/**
 * @class Table
 * @brief This class represents the tables customer will be seated at.
 */

#ifndef TABLE_H
#define TABLE_H

#include "iostream"
#include <list>
#include "Customer.h"

using namespace std;

class Table {

private:
	int tableNumber; ///< The unique identifier for the table.
	int capacity; ///< The maximum number of customers the table can accommodate.
	list<Customer*> customers; ///< A list of customers currently seated at the table.
	bool occupied = false; ///< Indicates whether the table is currently occupied.

public:
	/**
     * @brief Constructor for the Table class.
     * @param tableNumber The unique identifier for the table.
     * @param capacity The maximum number of customers the table can accommodate.
     */
	Table(int tableNumber, int capacity);
	
	/**
     * @brief Assign a list of customers to the table.
     * @param customers A list of Customer objects to be assigned to the table.
     */
	void assignCustomers(list<Customer*> customers);

	/**
     * @brief Remove all customers from the table.
     * This function removes all customers currently seated at the table.
     */
	void removeCustomers();

	/**
     * @brief Get the list of customers seated at the table.
     * @return A list of Customer objects currently seated at the table.
     */
	list<Customer*> getCustomers();

	/**
     * @brief Get the capacity of the table.
     * @return The maximum number of customers the table can accommodate.
     */
	int getCapacity();

	/**
     * @brief Get the table number.
     * @return The unique identifier for the table.
     */
	int getTableNumber();

	/**
     * @brief Check if the table is currently occupied.
     * @return True if the table is occupied, false otherwise.
     */
	bool isOccupied();
};

#endif
