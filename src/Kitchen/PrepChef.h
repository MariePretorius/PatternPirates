/**
 * @file PrepChef.h
 * @brief This file contains the implementation of the PrepChef class.
 */

#ifndef PREPCHEF_H
#define PREPCHEF_H
#include "Chef.h"
#include "../Restaurant/FoodOrder.h"
#include "CookingChef.h"


/**
 * @class PrepChef
 * @brief Declaration of the PrepChef class, first used in the CoR.
 */
class PrepChef : public Chef {
	private:
		/**
		 * @brief Handle the stock for a given food order.
		 * Deducts the required ingredients from the shelf and adds uncooked ingredients to the kitchen.
		 * @param order A pointer to the FoodOrder object.
		 */
		void handleStock(FoodOrder* order);

	public:
		/**
		 * @brief Constructor for the PrepChef class.
		 * @param thisKitchen A pointer to the Kitchen object.
		 */
        PrepChef(Kitchen* thisKitchen);
		/**
		 * @brief Destructor for the PrepChef class.
		 */
		~PrepChef();
		/**
		 * @brief Handle an order from the kitchen.
		 * Gets the next order from the kitchen and handles its stock.
		 */
		void handleOrder();
};

#endif
