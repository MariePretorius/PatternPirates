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
	bool waiting = false;
	bool seated = false;
	bool readyToOrder = false;
	bool orderPlaced = false;
	bool eating = false;
	bool requestingBill = false;
	bool billPaid = false;
	FoodOrder order;
	Bill* bill;

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
};

#endif
