#ifndef FOODORDER_H
#define FOODORDER_H

class Customer;
class Kitchen;
class Bill;

//#include "../Kitchen/Kitchen.h"
//#include "../Floor/Bill.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

class FoodOrder 
{
	private:
		std::string* ingredients;
		int numberOfIngredients;
		std::string cookingMethod;
		int tableNumber;
		Customer* customer;
		Kitchen* kitchen;
		Bill* bill;
		double* prices;
		int id;

		// prices map

	public:
		FoodOrder();
		FoodOrder(std::string* ingredients, double* prices, int num, std::string method, int tableNumber, Customer& customer, Kitchen* k, Bill* bill);
		~FoodOrder();
		void execute();
		void addToBill(std::string ingredient, double cost);
		std::string* getIngredients();
		std::string getCookingMethod();
		int getTableNumber();
		Customer* getCustomer();
		int getRandomID();  //can add vecter imput to check against duplicates
};

#endif
