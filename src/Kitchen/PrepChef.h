#ifndef PREPCHEF_H
#define PREPCHEF_H
#include "Chef.h"
#include "../Restaurant/FoodOrder.h"
#include "CookingChef.h"

class PrepChef : public Chef {
	private:
		void handleStock(FoodOrder* order);

	public:
        PrepChef();
		void handleOrder();
};

#endif
