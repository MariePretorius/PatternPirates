/**
 * @file Fryer.h
 * @brief Declaration of the Fryer class used as a ConcreteStrategy.
 */

#ifndef FRYER_H
#define FRYER_H
#include "Cook.h"
#include "Ingredient.h"
#include <iostream>
#include <thread>
#include <chrono>

#include "Cook.h"

/**
 * @class Fryer
 * @brief Represents a ConcreteStrategy, Fryer, used to fry ingredients.
 */
class Fryer : public Cook {
	public:
		/**
		 * Prepare the fryer station by filling with oil and heating it.
		 */
		void prepareStation() override;
		/**
		 * Cook an ingredient using the fryer and change its condition to fried.
		 * @param ingredient A pointer to the Ingredient to be fried.
		 * @return A pointer to the fried Ingredient.
		 */
		Ingredient* cookIngredient(Ingredient* ingredient) override;
	};

#endif
