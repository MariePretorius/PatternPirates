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

	protected:
		static Kitchen* kitchen;
		Chef* nextChef; //CoR

	public:
		virtual void handleOrder() = 0;
};

#endif
