#ifndef COOKINGCHEF_H
#define COOKINGCHEF_H
#include <list>
#include "Cook.h"
#include "Chef.h"

class CookingChef : Chef {

private:
	Cook* cook; //Strategy
	void changeCook(Cook* cook);//Change cook used at runtime (change strategy)

public:
	CookingChef(Cook* cook);
	void handleOrder();//Use strategy here
};

#endif
