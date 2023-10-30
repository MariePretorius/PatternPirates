#ifndef COOKINGCHEF_H
#define COOKINGCHEF_H

#include "Chef.h"
#include "Cook.h"

class CookingChef : Chef {

private:
	//List<Ingredient*> uncookedIngredients;
	//List<Ingredient*> cookedIngredients;
	Cook* cook;

	//Ingredient* cookingIngredient();

public:
	//void setIngredients(List<Ingredient*> ingredients);

	void handleOrder();
};

#endif
