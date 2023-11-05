/**
 * @file HeadChef.h
 * @brief Declaration of the HeadChef class.
 */

#ifndef HEADCHEF_H
#define HEADCHEF_H
#include "Chef.h"
#include <list>
#include "../Restaurant/Dish.h"

#include "Chef.h"
#include "../Restaurant/Dish.h"

/**
 * @class HeadChef
 * @brief Declaration of the HeadChef class, thirdly used in the CoR.
 */
class HeadChef : public Chef {
	public:
	/**
	 * Handle assembling a dish as the head chef.
	 */
		void handleOrder();
};

#endif
