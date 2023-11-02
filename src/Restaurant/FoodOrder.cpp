#include "FoodOrder.h"
#include "../Floor/Customer.h"
#include "../Floor/Bill.h"
#include "../Kitchen/Kitchen.h"

FoodOrder :: FoodOrder() {}

FoodOrder :: FoodOrder(std::string* ingredients, double* prices, int num, std::string method, int tableNumber, Customer& customer, Kitchen* k, Bill* bill) : kitchen{k}, bill(bill)
{
    this->customer = &customer;
    //this->kitchen = &k;
    //this->bill = &bill;
    this->numberOfIngredients = num;
    this->cookingMethod = method;
    this->tableNumber = tableNumber;
    this->ingredients = new std::string[numberOfIngredients];
    this->prices = new double[numberOfIngredients];
    for (int i = 0; i < numberOfIngredients; i++)
    {
        this->ingredients[i] = ingredients[i];
        this->prices[i] = prices[i];
        addToBill(ingredients[i], prices[i]);
    }
}

FoodOrder :: ~FoodOrder()
{
    delete ingredients;
    delete prices;
}

void FoodOrder :: execute()
{
    kitchen->addNewOrder(this);
}

void FoodOrder :: addToBill(std::string ingredient, double cost)
{
    bill->addItem(ingredient, cost);
}

std::string* FoodOrder :: getIngredients()
{
    return this->ingredients;
}

std::string FoodOrder :: getCookingMethod()
{
    return this->cookingMethod;
}

int FoodOrder :: getTableNumber()
{
    return this->tableNumber;
}

Customer* FoodOrder :: getCustomer()
{
    return this->customer;
}

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