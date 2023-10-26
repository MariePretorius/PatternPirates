#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {

private:
	CustomerState state;
	boolean waiting;
	boolean seated;
	boolean readyToOrder;
	boolean orderPlaced;
	boolean eating;
	boolean requestingBill;
	boolean billPaid;
	FoodOrder order;
	Bill* bill;

public:
	void placeOrder(FoodOrder order);

	void changeState(CustomerState state);

	void payBill(Bill bill);

	void leaveRating(int rating);

	void notifyHost();

	FoodOrder getOrder();

	CustomerState* getState();
};

#endif
