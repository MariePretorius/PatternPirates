#ifndef HEADCHEF_H
#define HEADCHEF_H

class HeadChef : Chef {

private:
	List<Ingredient*> cookedIngredients;

	Dish* prepareOrder();

public:
	void setIngredients(List<Ingredient*> cookedIngredients);

	void handleOrder();
};

#endif
