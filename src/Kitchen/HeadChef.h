#ifndef HEADCHEF_H
#define HEADCHEF_H
#include "Chef.h"
#include <list>
#include "Dish.h"

class HeadChef : Chef {

private:
	list<Ingredient*> cookedIngredients;
	Dish* prepareOrder();

public:
	void handleOrder();

protected:
	void setIngredients(list<Ingredient*> cookedIngredients);
};

#endif
