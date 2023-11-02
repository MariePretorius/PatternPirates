#ifndef PREPCHEF_H
#define PREPCHEF_H
#include "Chef.h"
#include "../Restaurant/FoodOrder.h"

#include "Chef.h"

class PrepChef : Chef {
	private:
		void handleStock(FoodOrder* order);


	public:
		void handleOrder();

};

#endif
