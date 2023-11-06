#include "FoodOrder.h"
#include "../Floor/Customer.h"
#include "../Floor/Bill.h"
#include "../Kitchen/Kitchen.h"

#include <sstream>

/**
 * @brief Default constructor for the class.
*/
FoodOrder :: FoodOrder() {}

/**
 * Parameterized constructor for the class.
 * @param ingredients List of ingredients in the order.
 * @param prices List of prices for the ingredients.
 * @param num Number of ingredients in order.
 * @param method The cooking method of the order.
 * @param tableNumber Table number the order came from.
 * @param customer Reference to the customer who ordered this.
 * @param k Reference to the kitchen object.
 * @param bill Reference to the bill for this order.
*/
FoodOrder :: FoodOrder(std::vector<std::string> ingredients, std::vector<double> prices, int num, std::string method, int tableNumber, Customer& customer, Bill* bill) : bill(bill)
{
    //added pre-instantiation to prevent segfault
    this->ingredients = vector<std::string>();
    this->prices = vector<double>();
    this->customer = &customer;
    //this->kitchen = &k;
    //this->bill = &bill;
    this->numberOfIngredients = num;
    this->cookingMethod = method;
    this->tableNumber = tableNumber;
    //this->ingredients = new std::string[numberOfIngredients];
    //this->prices = new double[numberOfIngredients];
    for (int i = 0; i < numberOfIngredients; i++)
    {
        //this->ingredients[i] = ingredients[i];
        this->ingredients.push_back(ingredients[i]);
        //this->prices[i] = prices[i];

        //I'm not sure why you were pushing the same ingredient twice. Assumed it was a mistake.
        this->prices.push_back(prices[i]);
        
        addToBill(this->ingredients[i], this->prices[i]);
    }

    // std::stringstream ss;
    // std::string custId = "";
    // ss << customer.getCustomerID();
    // ss >> custId;

    // std::cout << "\x1B[35m";

    // std::cout << "Customer " << custId << ": Order created." << std::endl;

    // std::cout << "\x1B[0m";
}

/**
 * @brief Destructor for this class.
*/
FoodOrder :: ~FoodOrder()
{
    //delete ingredients;
    //delete prices;
}

/**
 * @brief Execute function to pass order to kitchen.
*/
void FoodOrder :: execute()
{
    kitchen->addNewOrder(this);
}

/**
 * @brief Function to add all the ingredients onto the bill.
 * @param ingredient Single ingredient to add to bill.
 * @param cost Cost of the ingredient being added.
*/
void FoodOrder :: addToBill(std::string ingredient, double cost)
{
    bill->addItem(ingredient, cost);
}

/**
 * @brief Returns the ingredient list.
 * @return Returns a vector of ingredients.
*/
std::vector<std::string> * FoodOrder :: getIngredients()
{
    return &this->ingredients;
}

/**
 * @brief Returns the cooking method.
 * @return Returns a string of the cooking method.
*/
std::string FoodOrder :: getCookingMethod()
{
    return this->cookingMethod;
}

/**
 * @brief Returns the table number the order belongs to.
 * @return Returns integer value of the table number.
*/
int FoodOrder :: getTableNumber()
{
    return this->tableNumber;
}

/**
 * @brief Returns a pointer to the customer the order belongs to.
 * @return Customer object pointer.
*/
Customer* FoodOrder :: getCustomer()
{
    return this->customer;
}

/**
 * @brief Returns a pointer to the bill the order belongs to.
 * @return Bill object pointer.
*/
Bill* FoodOrder :: getBill()
{
    return this->bill;
}

/**
 * @brief Returns a random id between 1000 and 9999.
 * @return Return an integer value for the id.
*/
int FoodOrder :: getRandomID()   //add vector if necessary
{
    std::srand(static_cast<unsigned int>(time(nullptr)));
    int randomNumber = std::rand() % 9000 + 1000;

    return randomNumber;

    // std::vector<int> ids;
    // int k = 1111;
    // bool found = false;
    // bool done = false;
    // int randomNumber = 0;

    // for (int i = 0; i < 10; i++)
    // {
    //     ids.push_back(k);
    //     k++;
    // }

    // do
    // {
    //     //std::srand(static_cast<unsigned int>(time(nullptr)));
    //     randomNumber = std::rand() % 9000 + 1000;

    //     auto it = std::find(ids.begin(), ids.end(), randomNumber);

    //     if (it != ids.end()) 
    //     {
    //         found = true;
    //     } 

    //     // for (int i = 0; i < ids.size(); i++)
    //     // {
    //     //     if (ids[i] == random)
    //     //     {
    //     //         found = true;
    //     //         break;
    //     //     }
    //     // }
    // }
    // while (found == true);

    // ids.push_back(randomNumber);
    
    // return randomNumber;
}

/**
 * @brief Sets the kitchen pointer.
 * @param k Pointer to a kitchen object.
*/
void FoodOrder :: setKitchen(Kitchen* k)
{
    this->kitchen = k;
}

// In Waiter: 
// void takeOrder()
// {
//     // order parameters : 
//     // std::string* ingredients : array of ingredients
//     // double* prices : array of prices corresponding to the array of ingredients
//     // int num : number of ingredients/prices
//     // std::string method : cooking method
//     // int tableNumber : table number corresponding to the order
//     // Customer& customer : customer whose order it is
//     // Kitchen& k : reference to the kitchen
//     // Bill& bill : reference to the bill [used to add the order onto the bill]

//     // contents of function
//     FoodOrder order(ingredients, prices, num, method, tableNumber, customer, kitchen, bill);

//     order.execute();
// }

// In Kitchen
// void prepareFood(const std::string* ingredients, std::string cookingMethod) 
// {
//     // set cooking method
//     // add ingredients
    
//     // start process basically
//     // add to queue
// }