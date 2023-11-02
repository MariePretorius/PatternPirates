#ifndef CHEF_H
#define CHEF_H
#include <string>
#include "Kitchen.h"
#include "Shelf.h"

#include <string>
#include "../Restaurant/FoodOrder.h"

using namespace std;

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
