#ifndef FOODORDER_H
#define FOODORDER_H

class Customer;
class Kitchen;
class Bill;

//#include "../Kitchen/Kitchen.h"
//#include "../Floor/Bill.h"
#include <iostream>

class FoodOrder 
{
	private:
		std::string* ingredients;
		int numberOfIngredients;
		std::string cookingMethod;
		int tableNumber;
		Customer* customer;
		Kitchen& kitchen;
		Bill& bill;
		double* prices;

		// prices map

	public:
		FoodOrder(std::string* ingredients, double* prices, int num, std::string method, int tableNumber, Customer& customer, Kitchen& k, Bill& bill);
		~FoodOrder();
		void execute();
		void addToBill(std::string ingredient, double cost);
		std::string* getIngredients();
		std::string getCookingMethod();
		int getTableNumber();
		Customer* getCustomer();
};

#endif
