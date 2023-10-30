#include "Customer.h"

Customer::Customer(string paymentMethod)
{
    if (paymentMethod == "Tab") {

    } else if (paymentMethod == "Bill") {
        
    }
}

void Customer::placeOrder(FoodOrder order)
{
}

void Customer::changeState(CustomerState* state)
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
