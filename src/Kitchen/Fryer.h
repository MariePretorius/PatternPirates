#ifndef FRYER_H
#define FRYER_H
#include "Cook.h"
#include "Ingredient.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "Cook.h"

class Fryer : public Cook {


	public:
		void prepareStation() override;//override pure virtual function in Cook
		Ingredient* cookIngredient(Ingredient* ingredient) override;//fry ingredient
	};


#endif
