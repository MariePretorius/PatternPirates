#include "Kitchen.h"
#include "Chef.h"
#include "PrepChef.h"
using namespace std;

Kitchen::Kitchen(Finance* finance){
    this->finance = finance;
    this->prepChef = new PrepChef(this);
    this->shelf = new Shelf();
};

Kitchen::~Kitchen() {

}

FoodOrder* Kitchen::getNextOrder() {
    if (!orders.empty()) {
        FoodOrder* nextOrder = orders.front();
        orders.erase(orders.begin());
        currentOrder = nextOrder;
        return nextOrder;
    } else {
        cout << "\033[1;36mAll orders are handled,  for now...\033[0m" << endl;
        return nullptr;
    }
}

Shelf* Kitchen::getShelf() {
    return shelf;
}

void Kitchen::addCookedIngredient(Ingredient* ingredient) {
    cookedIngredients.push_back(ingredient);
}

void Kitchen::addUncookedIngredient(Ingredient* ingredient) {
    uncookedIngredients.push_back(ingredient);
}

void Kitchen::addNewOrder(FoodOrder* newOrder) {
    orders.push_back(newOrder);
    cout << "\033[1;36mA new order was just added to the kitchen!\033[0m" << endl;
}

void Kitchen::addDish(Dish* dish) {
    completedOrders.push_back(dish);
    cout << "\033[1;36mA new order was just completed!  Order up!\033[0m" << endl;
}

std::vector<Dish*> Kitchen::takeDishes() {
    if (completedOrders.empty()) {
        std::cout << "Orders are not yet ready to be collected." << std::endl;
    } else {
        std::cout << "Orders was succesfully collected by a waiter :)" << std::endl;
        return completedOrders;
    }
}

void Kitchen::setCurrentDish(double cond) {
    currentDish = new Dish(cond, currentOrder->getCustomer(),currentOrder->getTableNumber(),currentOrder->getBill());
}

void Kitchen::buyStock() {
    int buyOption;
    int quantity;
    char continueBuying='Y';
    int counter=0;

    double PriceArr[30]={15.50,10.25,25.99,18.99,40.50,50.00,12.99,12.99,20.00,15.00,12.99,
                         15.50,10.00,5.00,8.00,8.00,5.25,18.25,10.50,30.75,20.99,25.00,25.00,20.99,15.50,
                         18.00,20.50,25.25,15.25,10.00};
    string OptionsArr[30] = {"Rice","Flour","Eggs","Milk","Chicken",
                             "Ground beeg","Pasta","Potatoes","Tomatoes","Onions",
                             "Carrot","Bread","Sugar","Salt","Pepper","Cucumber",
                             "Bell Pepper","Brocolli","Spinach","Cheese","Butter",
                             "Olive Oil","Cereal","Apple","Banana","Orange","Grapes",
                             "Peanut Butter","Yogurt","Chocolate"};
    do {
        cout << "\033[1;36mList of possible items for your shelf:\033[0m" << endl;
        for (int i = 0; i < 29; i++) {
            cout << "\033[1;36m" + to_string(i)+ "\t" + OptionsArr[i] + "\t\t" + to_string(PriceArr[i]) + " \033[0m" << endl;
        }
        cout<<endl;
        cout<<"\033[1;36mPlease enter the item number you want to buy:\033[0m";
        cin>>buyOption;
        cout <<buyOption;
        //input validation
       /* while ( buyOption >30)
        {
            cout<<"\033[1;36mPlease enter the item number you want to buy:\033[0m";
            cin>>buyOption;
        }*/
        cout<<endl;
        cout<<"\033[1;36m" + OptionsArr[buyOption] + " costs R" + to_string(PriceArr[buyOption]) + ", enter quantity:\033[0m" ;
        cin>>quantity;
        if (quantity * PriceArr[buyOption] > finance->getFunds()) {
            cout << "\033[1;36mYou do not have enough funds left to make this purchase.\033[0m" << endl;
            continue;
        };
        if (quantity + shelf->getCurrentCapacity() > shelf->getMaxCapacity()) {
            cout << "\033[1;36mYou do not have enough space left on the shelf to make this purchase.\033[0m" << endl;
            continue;
        };
        shelf->addStock(new Ingredient(OptionsArr[buyOption],quantity,PriceArr[buyOption],counter++));
        finance->removeFunds(quantity*PriceArr[buyOption]);
        cout<< "\033[1;36m" + to_string(quantity) + " [" + OptionsArr[buyOption] + "] has been bought !\033[0m";
        cout<<endl;
        cout<<"\033[1;36mAmount of funds left: R" << finance->getFunds() << "\033[0m" <<endl;
        cout<<"\033[1;36mYour shelf:\033[0m"<<endl;
        cout<< "\033[1;36m" + shelf->getStockList() + "\033[0m"<<endl;
        cout << "\033[1;36mCurrent shelf capacity: \033[0m" << shelf->getCurrentCapacity() << "/" << shelf->getMaxCapacity() << endl;
        cout<<"\033[1;36mDo you want to buy more stock?[Y/n]: \033[0m";
        cin>> continueBuying;
    } while ((continueBuying == 'Y' || continueBuying == 'y') && finance->getFunds() > 0 && shelf->getCurrentCapacity() < shelf->getMaxCapacity());
}

Ingredient* Kitchen::getUncookedIngredient() {
    Ingredient* nextIngredient = uncookedIngredients.front();
    uncookedIngredients.pop_front();
    return nextIngredient;
}

Ingredient* Kitchen::getCookedIngredient() {
    Ingredient* nextIngredient = cookedIngredients.front();
    cookedIngredients.pop_front();
    return nextIngredient;
}

int Kitchen::getIngredientAmt() {
    return uncookedIngredients.size();
}

Dish* Kitchen::getCurrentDish() {
    return currentDish;
}

void Kitchen::startKitchenProcess() {
    this->prepChef->handleOrder();
    delete this->prepChef;
}

Finance* Kitchen::getFinance() {
    return this->finance;
}



