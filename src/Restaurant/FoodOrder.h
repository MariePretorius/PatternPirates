#ifndef FOODORDER_H
#define FOODORDER_H

#include "OrderCommand.h"

class Customer;
class Kitchen;
class Bill;

//#include "../Kitchen/Kitchen.h"
//#include "../Floor/Bill.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <vector>

/**
 * @class FoodOrder Class
 * This class is the ConcreteCommand participant in the Command design pattern. It Inherits from the OrderCommand class.
*/
class FoodOrder : public OrderCommand
{
	private:
		std::vector<std::string> ingredients;  ///< Vector containing the ingredients in the order.
		int numberOfIngredients;  ///< Integer containing the number of ingredients in the order.
		std::string cookingMethod;  ///< String containing the cooking method of the order.
		int tableNumber;  ///< Integer containing the table number this order belongs to.
		Customer* customer;  ///< Reference to the customer that ordered this.
		Kitchen* kitchen;  ///< Reference to the Kitchen object.
		Bill* bill;  ///< Reference to the Bill object of this order.
		std::vector<double> prices;  ///< Vector containing the prices of the ingredients of this order.
		int id; ///< Integer used to identify the order.

	public:
		/**
		 * @brief Default constructor for the class.
		*/
		FoodOrder();

		/**
		 * Parameterized constructor for the class.
		 * @param ingredients List of ingredients in the order.
		 * @param prices List of prices for the ingredients.
		 * @param num Number of ingredients in order.
		 * @param method The cooking method of the order.
		 * @param tableNumber Table number the order came from.
		 * @param customer Reference to the customer who ordered this.
		 * @param bill Reference to the bill for this order.
		*/
		FoodOrder(std::vector<std::string> ingredients, std::vector<double> prices, int num, std::string method, int tableNumber, Customer& customer, Bill* bill);
		
		/**
		 * @brief Destructor for this class.
		*/
		~FoodOrder();

		/**
		 * @brief Execute function to pass order to kitchen.
		*/
		void execute();

		/**
		 * @brief Function to add all the ingredients onto the bill.
		 * @param ingredient Single ingredient to add to bill.
		 * @param cost Cost of the ingredient being added.
		*/
		void addToBill(std::string ingredient, double cost);

		/**
		 * @brief Returns the ingredient list.
		 * @return Returns a vector of ingredients.
		*/
		std::vector<std::string> getIngredients();

		/**
		 * @brief Returns the cooking method.
		 * @return Returns a string of the cooking method.
		*/
		std::string getCookingMethod();

		/**
		 * @brief Returns the table number the order belongs to.
		 * @return Returns integer value of the table number.
		*/
		int getTableNumber();

		/**
		 * @brief Returns a pointer to the customer the order belongs to.
		 * @return Customer object pointer.
		*/
		Customer* getCustomer();

		/**
		 * @brief Returns a random id between 1000 and 9999.
		 * @return Return an integer value for the id.
		*/
		int getRandomID();  //can add vecter imput to check against duplicates

		/**
		 * @brief Sets the kitchen pointer.
		 * @param k Pointer to a kitchen object.
		*/
		void setKitchen(Kitchen* k);
};

#endif
