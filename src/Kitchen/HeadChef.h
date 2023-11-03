#ifndef HEADCHEF_H
#define HEADCHEF_H
#include "Chef.h"
#include <list>
#include "../Restaurant/Dish.h"

#include "Chef.h"
#include "../Restaurant/Dish.h"

class HeadChef : public Chef {
	public:
		void handleOrder();
};

#endif
