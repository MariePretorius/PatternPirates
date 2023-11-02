#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerState.h"
#include "../Restaurant/FoodOrder.h"
#include "Bill.h"
#include "Ratings.h"
#include "../Kitchen/Ingredient.h"

#include <list>
#include <iostream>
#include <string>
#include <random>

using namespace std;

class Customer {

private:
	CustomerState *state;
	FoodOrder order;
	Bill* bill;
	static int nextID;
	int id;
	string cookingMethod;
	list<Ingredient> ingredients;
	
	double calculateRating();

public:
	Customer(string paymentMethod);

	void placeOrder(FoodOrder order);

	void nextState();

	void payBill(Bill bill);

	void leaveRating(Ratings allRatings);

	void notifyHost();

	FoodOrder getOrder();

	CustomerState* getState();

	int getCustomerID();

	list<Ingredient> getIngredients();

	list<double> getPrices();

	string getCookingMethod();
};

int Customer::nextID = 1;

#endif
