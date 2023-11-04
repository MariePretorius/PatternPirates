/**
 * @class Table
 * @brief This class represents the tables customer will be seated at.
 */

#ifndef TABLE_H
#define TABLE_H

#include "iostream"
#include <list>
#include "Customer.h"
#include <vector>
#include "../Restaurant/Dish.h"

using namespace std;

class Table {

private:
	int tableNumber; ///< The unique identifier for the table.
	int capacity; ///< The maximum number of customers the table can accommodate.
	list<Customer*> customers; ///< A list of customers currently seated at the table.
	bool occupied = false; ///< Indicates whether the table is currently occupied.
     vector<Dish*> * dishes;
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
	list<Customer*> * getCustomers();


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

     /**
     * @brief Assign a vector of Dish pointers to the Restaurant.
     * This function sets the dishes on the Table by assigning a vector of Dish pointers.
     * @param dishes A vector of Dish pointers to be assigned to the Table.
     */
     void assignDishes(vector<Dish*>* dishes);

     /**
     * @brief Check the state of the Customers and clear the dishes if necessary.
     * This function checks the state of the Customers at the Table and clears the dishes
     * if all customers are in the "Bill Requested" state.
     */
     void checkDishes();

     /**
     * @brief Check if all customers have finished eating.
     * This function checks the state of all customers to determine if they have finished eating.
     * @return True if all customers have finished eating; False otherwise.
     */
     bool doneEating();
};

#endif
