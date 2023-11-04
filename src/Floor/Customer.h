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

    //changed to pointer to prevent seg fault
	list<Ingredient> * getIngredients();

	list<double> getPrices();

	string getCookingMethod();

	bool getPaymentMethod();

	double getRating();

	bool getSplit();
};



#endif
