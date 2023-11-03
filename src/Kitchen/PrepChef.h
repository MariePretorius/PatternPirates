#ifndef PREPCHEF_H
#define PREPCHEF_H
#include "Chef.h"
#include "../Restaurant/FoodOrder.h"
#include "CookingChef.h"

class Chef;

class PrepChef : public Chef {
	private:
		void handleStock(FoodOrder* order);

	public:
		void handleOrder();
};

#endif
