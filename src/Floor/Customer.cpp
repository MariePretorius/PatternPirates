#include "Customer.h"
#include "WaitingForTable.h"

Customer::Customer(string paymentMethod)
{
    state = new WaitingForTable();

    if (paymentMethod == "Tab") {

    } else if (paymentMethod == "Bill") {

    }
}

void Customer::placeOrder(FoodOrder order)
{
}

void Customer::nextState() 
{
    this->state = state;
}

void Customer::payBill(Bill bill)
{
}

void Customer::leaveRating(int rating)
{
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
