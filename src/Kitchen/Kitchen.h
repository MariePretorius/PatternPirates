/**
 * @file Kitchen.h
 * @brief Definition of the Kitchen class.
 */

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

/**
 * @class Kitchen
 * @brief Represents the kitchen in the restaurant.
 */
class Kitchen {
    public:
        /**
         * @brief Constructor for the Kitchen class.
         * @param finance A pointer to the Finance object.
         */
        Kitchen(Finance* finance);
        /**
         * @brief Destructor for the Kitchen class.
         */
        ~Kitchen();
        /**
         * @brief Add a new food order to the kitchen.
         * @param newOrder A pointer to the new FoodOrder.
         */
        void addNewOrder(FoodOrder* newOrder);
        void notifyWaiter();
        /**
         * @brief Add a completed dish to the kitchen.
         * @param dish A pointer to the completed Dish.
         */
        void addDish(Dish* dish);
        /**
         * @brief Take the completed dishes from the kitchen.
         * @return A vector of pointers to completed Dishes.
         */
        std::vector<Dish*> takeDishes();
        /**
         * @brief Get the next food order from the kitchen.
         * @return A pointer to the next FoodOrder.
         */
        FoodOrder* getNextOrder();    
        /**
         * @brief Get the kitchen's shelf.
         * @return A pointer to the Shelf.
         */ 
        Shelf* getShelf();
        /**
         * @brief Add a cooked ingredient to the kitchen.
         * @param ingredient A pointer to the Ingredient.
         */
        void addCookedIngredient(Ingredient* ingredient);
        /**
         * @brief Add an uncooked ingredient to the kitchen.
         * @param ingredient A pointer to the Ingredient.
         */
        void addUncookedIngredient(Ingredient* ingredient);
        /**
         * Set the current dish being prepared.
         * @param cond The condition of the dish.
         */
        void setCurrentDish(double cond);
        /**
         * @brief Buy stock items for the kitchen's shelf.
         */
        void buyStock();
        /**
         * @brief Get an uncooked ingredient from the kitchen.
         * @return A pointer to the uncooked Ingredient.
         */
        Ingredient* getUncookedIngredient();
        /**
         * @brief Get a cooked ingredient from the kitchen.
         * @return A pointer to the cooked Ingredient.
         */
        Ingredient* getCookedIngredient();
        /**
         * @brief Get the number of uncooked ingredients in the kitchen.
         * @return The number of uncooked ingredients.
         */
        int getIngredientAmt();
        /**
         * @brief Get the current dish being prepared in the kitchen.
         * @return A pointer to the current Dish.
         */
        Dish* getCurrentDish();
        /**
         * @brief Start the kitchen process, handled by the PrepChef.
         */
        void startKitchenProcess();
        /**
         * @brief Get the finance information of the kitchen.
         * @return A pointer to the Finance object.
         */
        Finance* getFinance(); 

    private:
        Dish* currentDish;///< The current dish in the making
        std::list<FoodOrder*> orders;///< The list of unhandles orders
        std::vector<Dish*> completedOrders;///< The list of dishes that are completed
        std::list<Ingredient*> uncookedIngredients;///< The list of uncooked ingredients 
        std::list<Ingredient*> cookedIngredients;///< The list of cooked ingredients
        FoodOrder* currentOrder;///< The current order being handled
        Shelf* shelf;///< The shelf of the kitchen
        Finance* finance;///< The finance information of the kitchen
        Chef* prepChef;///< The first chef in the kitchen, the prep chef
};

#endif