#ifndef GRILLER_H
#define GRILLER_H
#include "Cook.h"
#include "Ingredient.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "Cook.h"

class Griller : public Cook {


	public:
		void prepareStation() override;//override pure virtual function in Cook
		Ingredient* cookIngredient(Ingredient* ingredient) override;//grill ingredient

};

#endif
