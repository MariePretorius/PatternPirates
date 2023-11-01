#ifndef CHEF_H
#define CHEF_H
#include <string>
#include "FoodOrder.h"
#include "Kitchen.h"

class Chef {
	private:
		std::string chefName;
		double chefExperience;
		int chefID;
		int workingSpeed;
		Chef* nextChef;

	protected:
		Kitchen* kitchen;

	public:
		void handleOrder();
		void setNextChef(Chef* nextChef);
};

#endif
