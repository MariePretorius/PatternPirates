/**
 * @file Chef.h
 * @brief Declaration of the Chef class.
 */

#ifndef CHEF_H
#define CHEF_H
#include <string>
#include "Kitchen.h"
#include "Shelf.h"
#include <string>
#include "../Restaurant/FoodOrder.h"
class Kitchen;
using namespace std;

/**
 * @class Chef
 * @brief Represents a chef in a restaurant kitchen.
 */
class Chef {
	private:
		std::string chefName; ///< The name of the chef.
		double chefExperience; ///< The experience level of the chef.
		int chefID; ///< The unique ID of the chef.
		int workingSpeed; ///< The chef's working speed.

	protected:

		static Kitchen* kitchen; ///< A pointer to the Kitchen where the chef works.
		Chef* nextChef; ///< A pointer to the next chef in the Chain of Responsibility.

	public:
		/**
		 * Pure virtual function to handle food orders.
		 */
		virtual void handleOrder() = 0;
};

#endif
