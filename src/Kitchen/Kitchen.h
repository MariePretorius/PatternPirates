#ifndef KITCHEN_H
#define KITCHEN_H
#include <iostream>
#include <list>
#include "../Restaurant/FoodOrder.h"
#include "../Restaurant/Dish.h"
#include "Ingredient.h"
#include "Shelf.h"
#include "../Restaurant/Finance.h"

class Chef;


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
        void setCurrentDish(double cond);
        void buyStock();
        Ingredient* getUncookedIngredient();
        Ingredient* getCookedIngredient();
        int getIngredientAmt();
        Dish* getCurrentDish();
        void startKitchenProcess();

    private:
        Dish* currentDish;
        std::list<FoodOrder*> orders;
        std::list<Dish*> completedOrders;
        std::list<Ingredient*> uncookedIngredients;
        std::list<Ingredient*> cookedIngredients;
        FoodOrder* currentOrder;
        Shelf* shelf;
        Finance* finance;
        Chef* prepChef;
};

#endif