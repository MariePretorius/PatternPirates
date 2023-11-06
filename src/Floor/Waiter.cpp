//
// Created by Tristan on 2023/10/23.
//
using namespace std;
#include "Waiter.h"
#include "Customer.h"
#include "Bill.h"
#include "../Restaurant/FoodOrder.h"
#include <vector>
void Waiter::moveToNext()
{
    //will iterate to the next table in the tables list
    //foreach

}

void Waiter::getOrdersFromCurrTable()
{
    //call getter for each customer
    //call getter for each element of an order
    //create a foodorder object and put it into list with reference to customer that ordered it
    //repeat for all customers in table
    //repeat for all tables
    //call execute once all tables have been served
    //repeat for all waiters
}

/**
 * @brief Waiter Constructor
 * @param finance takes in a finance object
 */
Waiter::Waiter(Finance * finance, Ratings * ratings)
{
    this->finance = finance;
    tables = std::vector<Table*>();
    orders = std::vector<FoodOrder*>();
    this->ratings = ratings;
}

/**
 * @brief Adds a table to the waiter's list of tables which they wait
 * @param newTable A table pointer
 */
void Waiter::addTableToWait(Table *newTable)
{
    tables.push_back(newTable);
}

void Waiter::addOrder(FoodOrder *newOrder)
{
    orders.push_back(newOrder);
}

std::vector<FoodOrder *> *Waiter::giveOrders() {
    return &(this->orders);
}

void Waiter::createBill(bool split, Table *table) {
    std::list<Customer*> * temp = table->getCustomers();
    list<Customer*>::iterator it = table->getCustomers()->begin();
    if((*it)->getPaymentMethod())
    {
        //if split
        //creates a bill for each customer
        for(it; it != table->getCustomers()->end(); it++)
        {

        }

        //creates a bill based on orders
    }
    else
    {
        //bills.push_back(new Bill())
        //creates a bill for the whole table
    }
}

/**
 * @brief The Waiter will go to each table and fetch the orders from each customer seated at each table
 */
void Waiter::getOrders() {
    //call getter for each customer
    for(vector<Table*>::iterator table = tables.begin(); table != tables.end(); table++)
    {
        list<Customer*>::iterator customers = (*table)->getCustomers()->begin();

        while(customers != (*table)->getCustomers()->end())
        {
            std::cout << "\033[35mCustomer state is:\t\t"<< (*customers)->getState()->getName() <<"!\033[0m" << std::endl;
            if((*customers)->getState()->getName() == "Ready To Order")
            {
                vector<std::string> tempIngredient = ((*customers)->getIngredients());
                vector<double> tempPrices = (*customers)->getPrices();
                //vector<string> method = (*customers)->getCookingMethod();
                vector<string> vectorIngredients = vector<string>();
                vector<double> vectorDouble = vector<double>();
                for(string ingredient : tempIngredient)
                {
                    vectorIngredients.push_back(ingredient);
                }
                for(double &d : tempPrices)
                {
                    vectorDouble.push_back(d);
                }
                Bill * temp = new Bill(*customers,this->finance, *table);
                bills.push_back(temp);
                //FoodOrder(std::vector<std::string> ingredients, std::vector<double> prices, int num, std::string method, int tableNumber, Customer& customer, Bill* bill);
                FoodOrder * tempFoodOrder = new FoodOrder(vectorIngredients,vectorDouble,vectorIngredients.size(),
                                                          (*customers)->getCookingMethod(), (*table)->getTableNumber(), **customers,temp);
                this->orders.push_back(tempFoodOrder);
                (*customers)->nextState();
                std::cout << "\033[35mCustomer state has changed to:\t\t"<< (*customers)->getState()->getName() <<"!\033[0m" << std::endl;
            }

            customers++;
        }
    }
    //call getter for each element of an order
    //create a foodorder object and put it into list with reference to customer that ordered it
    //repeat for all customers in table
    //repeat for all tables
    //call execute once all tables have been served
    //repeat for all waiters
}

/**
 * @brief gets the Waiter's orders
 * @return a vector of FoodOrder pointers
 */
std::vector<FoodOrder *> * Waiter::fetchOrders() {
    return &orders;
}
/**
 * @brief Goes through this waiter's list of tables and checks if all customers a requesting bill, and then has them pay the bill
 * @return double The average Rating of all the waiter's tables
 */
void Waiter::doRounds() {
    std::cout << "\033[35mA Waiter is now doing their rounds.\033[0m" << std::endl;
    for (Table *t : tables) {
        std::cout << "\033[35mA waiter is at table number"<< t->getTableNumber() <<"\033[0m" << std::endl;
        if(t->doneEating())
        {
            std::cout << "\033[35mThe table is done eating.\033[0m" << std::endl;
            //writes up the bill for the table
            list<Customer *>::iterator customer = t->getCustomers()->begin();
            if((*customer)->getSplit())
            {
                std::cout << "\033[35mThe table is splitting the bill.\033[0m" << std::endl;
                //if splitting
                for(customer; customer != t->getCustomers()->end(); customer++)
                {
                    for(Bill * b : bills)
                    {
                        if((*customer) == b->getCustomer())
                        {

                            if(!b->isPaid())
                            {
                                std::cout << "\033[35mThe bill belonging to customer number "<< (*customer)->getCustomerID() <<" has the following contents:\n \033[0m" << std::endl;
                                b->showBill();
                                b->payBill((*customer)->getCustomerID());
                            }
                        }
                    }
                }
                for(customer = t->getCustomers()->begin(); customer != t->getCustomers()->end(); customer++)
                {
                    (*customer)->getRating();
                    (*customer)->nextState();
                }
            }
            else
            {
                std::cout << "\033[35mThe table is not splitting the bill.\033[0m" << std::endl;
                list<Customer *>::iterator customer = t->getCustomers()->begin();
                //iterate through the bills associated with a table and then have one id pay it
                //test comment
                for(Bill * b : bills)
                {
                    if(b->getTable() == t)
                    {
                        std::cout << "\033[35mThe bill has the following contents:\n \033[0m" << std::endl;
                        b->showBill();
                        if(!b->isPaid())
                        {
                            b->payBill((*customer)->getCustomerID());
                        }
                    }
                }
                for(customer = t->getCustomers()->begin(); customer != t->getCustomers()->end(); customer++)
                {
                    (*customer)->nextState();
                    cout << "\033[35mA customer left a rating of: \033[0m" << (*customer)->getRating() << endl;
                    ratings->leaveRating((*customer)->getRating());
                }
            }

        }
    }
}

/**
 * @brief Adds a dish to the waiter's hand vector
 * @param dish A dish pointer
 */
void Waiter::addDishToHand(Dish *dish) {
    dishesInHand.push_back(dish);
}

/**
 * @brief Returns the list of all tables waited by this waiter
 * @return a pointer to a vector of table pointers
 */
std::vector<Table *> *Waiter::getTables() {
    return &tables;
}

/**
 * @brief Drops the orders off at their respective tables
 */
void Waiter::passOrdersToTables() {
    //for each table
    for(Table * t: tables)
    {
        //go to each customer
        list<Customer*>::iterator customer = t->getCustomers()->begin();
        vector<Dish*> otherHand = vector<Dish*>();
        if(!t->getCustomers()->empty())
        {
            for(customer; customer != t->getCustomers()->end(); customer++)
            {
                bool given = false;
                //go through list of dishes
                vector<Dish*>::iterator d = dishesInHand.begin();
                if(!dishesInHand.empty())
                {
                    while(!given)
                    {
                        //and check if it needs to go to this table

                        if ((*d)->getTableId() == t->getTableNumber()) {
                            //add it to a vector
                            otherHand.push_back(*d);
                            //remove from source
                            vector<Dish *>::iterator it = std::find(dishesInHand.begin(), dishesInHand.end(), *d);
                            dishesInHand.erase(d);
                            given = true;
                        }
                        d++;
                        //then throw the dishes onto the table
                    }
                }
            }
            t->assignDishes(&otherHand);
        }

    }
}

Waiter::~Waiter() {

    for(Bill * c : bills)
    {
        delete c;
    }

    for(Dish * c : dishesInHand)
    {
        delete c;
    }
}


