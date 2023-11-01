#ifndef PREPCHEF_H
#define PREPCHEF_H
#include "Chef.h"
#include "FoodOrder.h"

class PrepChef : Chef {
	private:
		void handleStock(FoodOrder* order);

	public:
		void handleOrder();
};

#endif
