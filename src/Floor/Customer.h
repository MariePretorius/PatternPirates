#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerState.h"
#include "../Restaurant/FoodOrder.h"
#include "Bill.h"
#include "Ratings.h"
#include <string>

using namespace std;

class Customer {

private:
	CustomerState *state;
	FoodOrder order;
	Bill* bill;
	static int nextID;
	int id;
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
};

int Customer::nextID = 1;

#endif
