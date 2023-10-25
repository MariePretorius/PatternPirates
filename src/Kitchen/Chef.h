#ifndef CHEF_H
#define CHEF_H

class Chef {

private:
	string chefName;
	double chefExperience;
	int chefID;
	int workingSpeed;
	Chef* nextChef;
	Order* currentOrder;

public:
	void handleOrder();

	void setNextChef(Chef* nextChef);
};

#endif
