/**
 * @file Dish.h
 * @brief Definition of the Dish class.
 */

#ifndef DISH_H
#define DISH_H
#include <list>
#include "../Kitchen/Ingredient.h"
#include "../Floor/Customer.h"
class Bill;
//#include "../Floor/Bill.h"
using namespace std;

/**
 * @class Dish
 * @brief Represents a completed order and a finished dish that is given to customers by a waiter.
 */
class Dish {

public: 		
	/**
	 * Get the table ID where the dish is served.
	 * @return The table ID.
	 */	
	int getTableId();
	/**
	 * Constructor for the Dish class.
	 * @param cond The condition of the dish.
	 * @param customer A pointer to the Customer who ordered the dish.
	 * @param tableId The ID of the table where the dish is served.
	 * @param bill A pointer to the Bill associated with the dish.
	 */
	Dish(double cond, Customer* customer, int tableId, Bill* bill);
	/**
	 * Add an ingredient to the dish.
	 * @param ingredient A pointer to the Ingredient to be added.
	 */
	void addIngredient(Ingredient*);

private:
	list<Ingredient*> ingredients; ///< The list of ingredients contained in the dish
	int tableId; ///< The ID of the table the dish belongs to
	double condition;///< The current condition of the dish, represented as a percentage
	Customer* customer;///< A pointer to the customer the dish belongs to
	Bill* bill;///< A pointer to the bill where the dish's cost should be added
};

#endif
