#ifndef FOODORDER_H
#define FOODORDER_H

class FoodOrder {

private:
	string ingredients;
	string cookingMethod;
	int tableNumber;
	Customer& customer;

public:
	FoodOrder(string ingredients, string method, string tableNumber, Customer& customer);

	FoodOrder();

	void execute();

	void addToBill(string ingredient);

	string getIngredients();
};

#endif
