#ifndef COOK_H
#define COOK_H
class Ingredient;
class Cook {

public:

	virtual void prepareStation() = 0;//pure virtual function
	virtual Ingredient* cookIngredient(Ingredient* ingredient) = 0;//pure virtual function

};

#endif
