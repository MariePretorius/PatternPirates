/**
 * @file CookingChef.h
 * @brief Declaration of the CookingChef class.
 */

#ifndef COOKINGCHEF_H
#define COOKINGCHEF_H
#include <list>
#include "Cook.h"
#include "Chef.h"
#include "HeadChef.h"
#include "Fryer.h"
#include "Griller.h"

/**
 * @class CookingChef
 * @brief Declaration of the CookingChef class, secondly used in the CoR.
 */
class CookingChef : public Chef {

private:
	Cook* cook; ///< Pointer to the strategy object used
	/**
	 * Change the cook (strategy used) associated with the CookingChef.
	 * @param cook A pointer to the Cook to be associated with the CookingChef.
	 */
	void changeCook(Cook* cook);

public:
	/**
	 * Constructor for the CookingChef class.
	 */
	CookingChef();
	/**
	 * Handle a food order in the kitchen by assigning the appropriate cook
	 * and preparing ingredients.
	 */
	void handleOrder();
};

#endif
