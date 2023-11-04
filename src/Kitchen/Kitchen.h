#ifndef KITCHEN_H
#define KITCHEN_H
#include <iostream>
#include <list>
#include "../Restaurant/FoodOrder.h"
#include "../Restaurant/Dish.h"
#include "Ingredient.h"
#include "Shelf.h"
#include "../Restaurant/Finance.h"
#include <vector>

class Chef;

class Kitchen {
    public:
        Kitchen(Finance* finance);
        ~Kitchen();
        void addNewOrder(FoodOrder* newOrder);
        void notifyWaiter();
        void addDish(Dish* dish);
        std::vector<Dish*> takeDishes();
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
        Finance* getFinance(); //Used for testing...might remove later

    private:
        Dish* currentDish;
        std::list<FoodOrder*> orders;
        std::vector<Dish*> completedOrders;
        std::list<Ingredient*> uncookedIngredients;
        std::list<Ingredient*> cookedIngredients;
        FoodOrder* currentOrder;
        Shelf* shelf;
        Finance* finance;
        Chef* prepChef;
};

#endif