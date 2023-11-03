#include "Kitchen.h"
#include "Chef.h"
#include "PrepChef.h"
using namespace std;

Kitchen::Kitchen(){
    this->prepChef = new PrepChef(this);
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

void Kitchen::notifyWaiter() {
    //Notify waiter that dish is ready
}

void Kitchen::addDish(Dish* dish) {
    completedOrders.push_back(dish);
    cout << "\033[1;36mA new order was just completed!  Order up!\033[0m" << endl;
}

Dish* Kitchen::takeDish(int id) {

    list<Dish*>::iterator it = completedOrders.begin();

    while(it != completedOrders.end())
    {
        if((*it)->getId() == id)
        {
            std::cout << "Order " << id << "was succesfully collected by a waiter :)" << std::endl;
            return *it;
        }
    }
    std::cout << "Order " << id << "is not yet ready to be collected." << std::endl;

}

void Kitchen::setCurrentDish(double cond) {
    currentDish = new Dish(cond);
}

void Kitchen::buyStock() {
    int buyOption;
    int quantity;
    char continueBuying='Y';

    double PriceArr[10]={30.50,48.60,12.99,50.20,10.00,17.10,60.00,
                         20.00,30.05};
    string OptionsArr[10] = {"Beef","Chicken","Breadrolls","Fish","Spinach",
                             "Salad","Pizza base","Onions","Eggs"};
    do {
        cout << "\033[1;36mList of possible items for your shelf:\033[0m" << endl;
        cout << "\033[1;36m1:\tBeef \033[0m" << endl;
        for (int i = 0; i < 10; ++i) {
            cout << "\033[1;36m"+ to_string(i)+"\t"+OptionsArr[i]+" \033[0m" << endl;
        }
        cout<<endl;
        cout<<"\033[1;36mPlease enter the item number you want to buy:";
        cin>>buyOption;
        cout<<endl;
        cout<<OptionsArr[buyOption]+ " costs R" + to_string(PriceArr[buyOption])+", enter quantity:" ;
        cin>>quantity;
        //shelf->addStock(new Ingredient()); //Ingredient needs a constructor
        finance->removeFunds(PriceArr[buyOption]);
        cout<< to_string(quantity)+" [" + OptionsArr[buyOption] + "] has been bought !";
        cout<<endl;
        cout<<"Amount of funds left: R"<< to_string(finance->getFunds());
        cout<<"Your shelf:"<<endl;
        cout<<shelf->getStockList()<<endl;
        cout<<"Do you want to buy more stock?[Y/n]: \033[0m";
        cin>> continueBuying;
    } while (continueBuying == 'Y');/*while (continueBuying=='Y'&& Shelf.getCurrCapacity<=Shelf.getMaxCapacity && finance.getFunds < 10)
    */ //create finance obj + add getCurrCapacity +getMaxCapacity to Shelf class

}

Ingredient* Kitchen::getUncookedIngredient() {
    Ingredient* nextIngredient = uncookedIngredients.front();
    uncookedIngredients.pop_front();
}

Ingredient* Kitchen::getCookedIngredient() {
    Ingredient* nextIngredient = cookedIngredients.front();
    cookedIngredients.pop_front();
}

int Kitchen::getIngredientAmt() {
    return uncookedIngredients.size();
}

Dish* Kitchen::getCurrentDish() {
    return currentDish;
}

void Kitchen::startKitchenProcess() {
    this->prepChef->handleOrder();

}



