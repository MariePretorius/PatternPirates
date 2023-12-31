#include "Customer.h"
#include "WaitingForTable.h"

int Customer::nextID = 1;

double Customer::calculateRating()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(1.0, 5.0);

    double random_value = distribution(gen);
    return random_value;
}

Customer::Customer(string paymentMethod, bool split, vector<Stock*> stock)
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
    for (int i = 0; i < 3; i++) {
        int randIndex = distribution(gen);
        if (randIndex == 1) {
            this->cookingMethod.push_back("Grilled");
        } else this->cookingMethod.push_back("Fried");
    }

    random_device other;
    mt19937 gen2(other());
    uniform_int_distribution<int> distribution2(1, 2);
    int otherNum = distribution2(gen2);

    random_device ing;
    mt19937 gen3(ing());
    uniform_int_distribution<int> distribution3(0, (stock.size() - 1));
    for (int i = 0; i < 3; i++) {
        int randomIndex = distribution3(gen3);
        this->stock.push_back(stock[randomIndex]);
    }
}

void Customer::nextState() 
{
    this->state = state->getNextState();
    this->notify();
}

void Customer::leaveRating(Ratings allRatings)
{
    double rating = calculateRating();
    allRatings.leaveRating(rating);
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

vector<string> Customer::getIngredients()
{
    vector<string> ingredients;
    for (int i = 0; i < 3; i++) {
        ingredients.push_back(stock[i]->getName());
    }
    return ingredients;
}

vector<double> Customer::getPrices()
{
    vector<double> prices;
    for (int i = 0; i < 3; i++) {
        prices.push_back(stock[i]->getCostPerUnit());
    }
    return prices;
}

vector<string> Customer::getCookingMethod()
{
    //Added this line becuase waiter didn't like that the variable it was fetching was private for some reason
    vector<string> temp = cookingMethod;
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
