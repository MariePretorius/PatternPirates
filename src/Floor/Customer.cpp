#include "Customer.h"
#include "WaitingForTable.h"

double Customer::calculateRating()
{
    return 5.0;
}

Customer::Customer(string paymentMethod, bool split)
{
    state = new WaitingForTable();

    if (split) {
        this->split = true;
    } else this->split = false;

    if (paymentMethod == "tab") {
        this->paymentMethod = "tab";

    } else if (paymentMethod == "bill") {
        this->paymentMethod = "bill";
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
}

void Customer::nextState() 
{
    this->state = state->getNextState();
}

void Customer::leaveRating(Ratings allRatings)
{
    //double rating = calculateRating;
    allRatings.leaveRating(3.0);
}

void Customer::notifyHost()
{
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
