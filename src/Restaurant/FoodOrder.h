#ifndef FOODORDER_H
#define FOODORDER_H

#include "../Floor/Customer.h"
#include <iostream>

class FoodOrder {

private:
	std::string ingredients;
	std::string cookingMethod;
	int tableNumber;
	Customer& customer;

public:
	FoodOrder(std::string ingredients, std::string method, std::string tableNumber, Customer& customer);

	FoodOrder();

	void execute();

	void addToBill(std::string ingredient);

	std::string getIngredients();
};

#endif
