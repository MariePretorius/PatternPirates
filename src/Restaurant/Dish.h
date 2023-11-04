#ifndef DISH_H
#define DISH_H
#include <list>
#include "../Kitchen/Ingredient.h"
#include "../Floor/Customer.h"
#include "../Floor/Bill.h"
using namespace std;

class Dish {

public: 			
	int getId();	
	Dish(double cond, Customer* customer, int tableId, Bill* bill);
	void addIngredient(Ingredient*);

private:
	list<Ingredient*> ingredients;
	int tableId;
	double condition;
	Customer* customer;
	Bill* bill;
};

#endif
