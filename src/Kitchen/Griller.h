/**
 * @file Griller.h
 * @brief Declaration of the Griller class used as a ConcreteStrategy.
 */

#ifndef GRILLER_H
#define GRILLER_H
#include "Cook.h"
#include "Ingredient.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "Cook.h"

/**
 * @class Friller
 * @brief Represents a ConcreteStrategy, Griller, used to grill ingredients.
 */
class Griller : public Cook {


	public:
		/**
		 * Prepare the fryer station by heating the stove.
		 */
		void prepareStation() override;
		/**
		 * Cook an ingredient using the griller and change its condition to grilled.
		 * @param ingredient A pointer to the Ingredient to be grilled.
		 * @return A pointer to the grilled Ingredient.
		 */
		Ingredient* cookIngredient(Ingredient* ingredient) override;

};

#endif
