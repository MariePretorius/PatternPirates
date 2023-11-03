#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Finance.h"
#include "../Floor/Floor.h"
#include "../Kitchen/Kitchen.h"
#include <iostream>
#include "../Floor/Host.h"
//hellos
using namespace std;
class Restaurant {

private:
	static Restaurant* uniqueInstance;
    Finance* funds;
    Floor* floor;
    Kitchen* kitchen;
public:
	static Restaurant* instance();

protected:
	Restaurant();

	Restaurant(Restaurant& restaurant);

	void operator=(Restaurant& restaurant);

public:
	void setup();

	void simulate();

    double getFunds();

    void subtractFunds(double x);

    Kitchen* getKitchen();
};
#endif
