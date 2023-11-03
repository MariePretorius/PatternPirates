/**
 * @class Customer
 * @brief This class represents the customers who enter the restaurant.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerState.h"
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
	static int nextID;
	int id;
	string cookingMethod;
	list<Ingredient> ingredients;
	string paymentMethod = "bill";
	bool split = false;
	
	double calculateRating();

public:
	Customer(string paymentMethod, bool split);

	void nextState();

	void leaveRating(Ratings allRatings);

	void notifyHost();

	CustomerState* getState();

	int getCustomerID();

	list<Ingredient> getIngredients();

	list<double> getPrices();

	string getCookingMethod();

	bool getPaymentMethod();

	double getRating();

	bool getSplit();

	string getStateName();

	string getPaymentName();
};



#endif
