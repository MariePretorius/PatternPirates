#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chef.h"
#include "../Restaurant/Dish.h"

class HeadChef : Chef {

private:
	//List<Ingredient*> cookedIngredients;

	Dish* prepareOrder();

public:
	//void setIngredients(List<Ingredient*> cookedIngredients);

	void handleOrder();
};

#endif
