#ifndef FRYER_H
#define FRYER_H

class Fryer : Cook {


public:
	void fillOil();

	Ingredient* fryIngredient();
};

#endif
