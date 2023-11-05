#ifndef FOODORDERTEST_H
#define FOODORDERTEST_H

#include "../Restaurant/FoodOrder.h"
#include "../Floor/Customer.h"
#include "../Floor/Bill.h"
#include "../Kitchen/Kitchen.h"

#include <vector>
#include <cassert>

class FoodOrderTest 
{
    public:
        FoodOrderTest();
        void testFoodOrder();
        void runTests();
    private:
        FoodOrder* foodOrder;
        Kitchen* kitchen;
        Customer* customer;
        //Bill bill;
};

#endif
