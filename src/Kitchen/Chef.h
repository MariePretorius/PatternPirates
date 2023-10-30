#ifndef CHEF_H
#define CHEF_H

#include <string>
#include "../Restaurant/FoodOrder.h"

using namespace std;

class Chef {

private:
	string chefName;
	double chefExperience;
	int chefID;
	int workingSpeed;
	Chef* nextChef;
	FoodOrder* currentOrder;

public:
	void handleOrder();

	void setNextChef(Chef* nextChef);
};

#endif
