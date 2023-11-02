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

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 2);
    int num = distribution(gen);

    if (num == 1) {
        cookingMethod = "grilled";
    } else cookingMethod = "fried";

    random_device other;
    mt19937 gen(other());
    uniform_int_distribution<int> distribution2(1, 2);
    int otherNum = distribution2(gen);

    if (otherNum == 1) {
        paymentMethod = "tab";
        //tab = true
    } else paymentMethod = "bill";
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

list<Ingredient> Customer::getIngredients()
{
    return ingredients;
}

list<double> Customer::getPrices()
{
    return list<double>();
}

string Customer::getCookingMethod()
{
    return cookingMethod;
}

bool Customer::getPaymentMethod()
{
    if (paymentMethod == "tab") {
        return true;
    } else return false;
}
