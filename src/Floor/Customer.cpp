#include "Customer.h"
#include "WaitingForTable.h"
int Customer::nextID = 1;
double Customer::calculateRating()
{
    return 5.0;
}

Customer::Customer(string paymentMethod, bool split, vector<Ingredient*> ingredients)
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

    //Changed to reference 'this' to make sure it was assigning to the correct variable.
    if (num == 1) {
        this->cookingMethod = "grilled";
    } else this->cookingMethod = "fried";

    random_device other;
    mt19937 gen2(other());
    uniform_int_distribution<int> distribution2(1, 2);
    int otherNum = distribution2(gen2);
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

vector<Ingredient> * Customer::getIngredients()
{
    return &ingredients;
}

list<double> Customer::getPrices()
{
    return list<double>();
}

string Customer::getCookingMethod()
{
    //Added this line becuase waiter didn't like that the variable it was fetching was private for some reason
    string temp = cookingMethod;
    //cout<<cookingMethod<<endl;
    return temp;
}

bool Customer::getPaymentMethod()
{
    if (paymentMethod == "tab") {
        return true;
    } else return false;
}

double Customer::getRating()
{
    return 5.0;
}

bool Customer::getSplit()
{
    return split;
}

string Customer::getStateName()
{
    return state->getName();
}

string Customer::getPaymentName()
{
    return paymentMethod;
}
