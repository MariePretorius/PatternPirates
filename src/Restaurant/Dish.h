#ifndef DISH_H
#define DISH_H
#include <list>
#include "../Kitchen/Ingredient.h"
using namespace std;

class Dish {

public: 			
	int getId();	
	Dish(double cond);
	void addIngredient(Ingredient*);

private:
	list<Ingredient*> ingredients;
	int id;
	double condition;
};

#endif
