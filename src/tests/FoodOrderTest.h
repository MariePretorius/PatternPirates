#ifndef FOODORDERTEST_H
#define FOODORDERTEST_H

#include "../Restaurant/FoodOrder.h"
#include "../Floor/Customer.h"
#include "../Floor/Bill.h"
#include "../Kitchen/Kitchen.h"

class FoodOrderTest 
{
    public:
        FoodOrderTest();
        ~FoodOrderTest();
        void testExecute();
        void testAddToBill();
        void testGetters();
        void testRandomID();
        void runTests();
    private:
        FoodOrder* foodOrder;
};

#endif
