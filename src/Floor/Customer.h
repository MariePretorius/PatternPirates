/**
 * @class Customer
 * @brief This class represents the customers who enter the restaurant.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerState.h"
#include "Ratings.h"
#include "../Kitchen/Ingredient.h"
#include "../Kitchen/Stock.h"

#include <list>
#include <iostream>
#include <string>
#include <random>

using namespace std;

class Customer {

private:
	CustomerState *state; ///< The current state of the customer.
	static int nextID; ///< A static variable to generate unique customer IDs.
	int id; ///< The unique identifier for the customer.
	string cookingMethod; ///< The method used for preparing the customer's order.
	vector<Stock*> stock; ///< A list of ingredients for the customer's order.
	string paymentMethod = "bill"; ///< The method of payment chosen by the customer.
	bool split = false; ///< Indicates whether the customer's bill is split.
	
	double calculateRating();

public:
	/**
     * @brief Constructor for the Customer class.
     * @param paymentMethod The method of payment chosen by the customer.
     * @param split Indicates whether the customer's bill is split.
     */
	Customer(string paymentMethod, bool split, vector<Stock*> stock);

	/**
     * @brief Transition to the next customer state.
     * This function transitions the customer to their next state based on the
     * current state and the restaurant's policies.
     */
	void nextState();

	/**
     * @brief Leave a rating based on all received ratings.
     * @param allRatings A Ratings object containing all received ratings.
     * This function allows the customer to leave a rating based on the received
     * ratings for their dining experience.
     */
	void leaveRating(Ratings allRatings);

	/**
     * @brief Notify the restaurant host of the customer's status.
     * This function notifies the host of the customer's arrival.
     */
	void notifyHost();

	/**
     * @brief Get the current state of the customer.
     * @return A pointer to the current state of the customer.
     */
	CustomerState* getState();

	/**
     * @brief Get the unique customer ID.
     * @return The unique identifier for the customer.
     */
	int getCustomerID();

	/**
     * @brief Get the list of ingredients for the customer's order.
     * @return A list of Ingredient objects representing the customer's order.
     */

	vector<string> getIngredients();



	/**
     * @brief Get the prices of the ordered items.
     * @return A list of prices for the customer's order items.
     */
	vector<double> getPrices();

	/**
     * @brief Get the cooking method for the order.
     * @return The method used for preparing the customer's order.
     */
	string getCookingMethod();

	/**
     * @brief Get the chosen payment method.
     * @return The method of payment chosen by the customer.
     */
	bool getPaymentMethod();

	/**
     * @brief Get the customer's rating.
     * @return The customer's overall rating based on their dining experience.
     */
	double getRating();

	/**
     * @brief Check if the bill is split.
     * @return True if the customer's bill is split, false otherwise.
     */
	bool getSplit();

	/**
     * @brief Get the name of the customer's current state.
     * @return A string containing the name of the current state.
     */
	string getStateName();

	/**
     * @brief Get the name of the chosen payment method.
     * @return A string containing the name of the chosen payment method.
     */
	string getPaymentName();
};



#endif
