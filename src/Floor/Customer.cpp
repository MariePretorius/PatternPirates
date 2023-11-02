#include "Customer.h"
#include "WaitingForTable.h"

double Customer::calculateRating()
{
    return 0.0;
}

Customer::Customer(string paymentMethod)
{
    state = new WaitingForTable();

    if (paymentMethod == "Tab") {

    } else if (paymentMethod == "Bill") {

    }

    id = nextID++;
}

void Customer::placeOrder(FoodOrder order)
{
}

void Customer::nextState() 
{
    this->state = state->getNextState();
}

void Customer::payBill(Bill bill)
{
}

void Customer::leaveRating(Ratings allRatings)
{
    //double rating = calculateRating;
    allRatings.leaveRating(3.0);
}

void Customer::notifyHost()
{
}

FoodOrder Customer::getOrder()
{
    return FoodOrder();
}

CustomerState *Customer::getState()
{
    return state;
}

int Customer::getCustomerID()
{
    return id;
}
