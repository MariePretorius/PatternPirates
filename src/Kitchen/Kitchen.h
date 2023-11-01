#ifndef KITCHEN_H
#define KITCHEN_H
#include <iostream>
#include <list>
#include "../Restaurant/FoodOrder.h"
#include "../Restaurant/Dish.h"
#include "Ingredient.h"
#include "FoodOrder.h"

class Kitchen {
    public:
        Kitchen();
        ~Kitchen();
        void addNewOrder(FoodOrder* newOrder);
        void notifyWaiter();
        void addDish(Dish* dish);
        Dish* takeDish(int id);
        FoodOrder* getNextOrder();

    private:
        std::list<FoodOrder*> orders;
        std::list<Dish*> completedOrders;
        std::list<Ingredient*> uncookedIngredients;
        std::list<Ingredient*> cookedIngredients;
        FoodOrder* currentOrder;
        
};

#endif