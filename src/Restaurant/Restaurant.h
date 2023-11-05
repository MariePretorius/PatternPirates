#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Finance.h"
#include "../Floor/Floor.h"
#include "../Kitchen/Kitchen.h"
#include <iostream>
#include "../Floor/Host.h"
using namespace std;
/**
 * @class Restaurant
 * @brief Restaurant is a facade and a singleton. It is responsible for the game loop.
 */
class Restaurant {

private:
	static Restaurant* uniqueInstance; ///<unique instance part of singleton design pattern
    Finance* funds; ///< a reference to the funds of the restaurant
    Floor* floor; ///< reference to the floor of the restaurant
    Kitchen* kitchen; ///<reference to the kitchen of the restaurant
public:
    /**
     * instance is part of the singleton pattern it ensures that there is only one instance of Restaurant
     * @return returns the unuqueInstance
     */
	static Restaurant* instance();

protected:
    /**
     * @brief Default constructor made protected so that outside classes can't call it
     */
	Restaurant();

    /**
     * @brief Default copy constructor made protected so that outside classes can't call it
     */
	Restaurant(Restaurant& restaurant);
    /**
     * @brief Operator overloading of operator= made protected so that outside classes can't call it
     */
	void operator=(Restaurant& restaurant);
    /**
     * @brief Destructor for Restaurant
     */
    ~Restaurant();

public:
    /**
     * setup instantiates the kitchen, funds and floor. It also gets user input to populate the shelf with ingredients.
     */
	void setup();

    /**
     * simulate is responsible for the game loop , calling all the necessary functions from floor and kitchen
     */
	void simulate();

};
#endif
