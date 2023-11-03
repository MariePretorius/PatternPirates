#ifndef COOKINGCHEF_H
#define COOKINGCHEF_H
#include <list>
#include "Cook.h"
#include "Chef.h"
#include "HeadChef.h"
#include "Fryer.h"
#include "Griller.h"

class CookingChef : public Chef {

private:
	Cook* cook; //Strategy
	void changeCook(Cook* cook);//Change cook used at runtime (change strategy)

public:
	CookingChef();
	void handleOrder();//Use strategy here
};

#endif
