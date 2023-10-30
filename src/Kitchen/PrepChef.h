#ifndef PREPCHEF_H
#define PREPCHEF_H

#include "Chef.h"

class PrepChef : Chef {


private:
	void sendOrder(FoodOrder* order);

	void handleStock();

public:
	void handleOrder();
};

#endif
