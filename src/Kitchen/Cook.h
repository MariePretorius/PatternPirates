/**
 * @file Cook.h
 * @brief Declaration of the Cook class.
 */
#ifndef COOK_H
#define COOK_H
class Ingredient;
/**
 * @class Cook
 * @brief Represents a Strategy that is used to define a fryer and a griller strategy.
 */
class Cook {

public:
	/**
     * Pure virtual function to prepare a specifc chef station.
     */
	virtual void prepareStation() = 0;
	/**
     * Pure virtual function to cook an ingredient.
     */
	virtual Ingredient* cookIngredient(Ingredient* ingredient) = 0;
};

#endif
