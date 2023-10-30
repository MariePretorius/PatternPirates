#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerState.h"
#include "../Restaurant/FoodOrder.h"
#include "Bill.h"
#include <string>

using namespace std;

class Customer {

private:
	CustomerState *state;
	bool waiting;
	bool seated;
	bool readyToOrder;
	bool orderPlaced;
	bool eating;
	bool requestingBill;
	bool billPaid;
	FoodOrder order;
	Bill* bill;

public:
	Customer(string paymentMethod);

	void placeOrder(FoodOrder order);

	void changeState(CustomerState* state);

	void payBill(Bill bill);

	void leaveRating(int rating);

	void notifyHost();

	FoodOrder getOrder();

	CustomerState* getState();
};

#endif
