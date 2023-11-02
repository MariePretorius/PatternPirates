#ifndef KITCHEN_H
#define KITCHEN_H
#include <iostream>
#include <list>
#include "../Restaurant/FoodOrder.h"
#include "../Restaurant/Dish.h"
#include "Ingredient.h"
#include "FoodOrder.h"
#include "Shelf.h"

class Kitchen {
    public:
        Kitchen();
        ~Kitchen();
        void addNewOrder(FoodOrder* newOrder);
        void notifyWaiter();
        void addDish(Dish* dish);
        Dish* takeDish(int id);
        FoodOrder* getNextOrder();
        Shelf* getShelf();
        void addCookedIngredient(Ingredient* ingredient);
        void addUncookedIngredient(Ingredient* ingredient);

    private:
        std::list<FoodOrder*> orders;
        std::list<Dish*> completedOrders;
        std::list<Ingredient*> uncookedIngredients;
        std::list<Ingredient*> cookedIngredients;
        FoodOrder* currentOrder;
        Shelf* shelf;
};

#endif