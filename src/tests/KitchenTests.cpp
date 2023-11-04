#include "KitchenTests.h"
#include "../Restaurant/FoodOrder.h"
#include <vector>

KitchenTests::KitchenTests() {

}

void KitchenTests::runTests() {
    Kitchen* kitchen = new Kitchen(new Finance());
    Table * table = new Table(0,5);
    Customer* customer1 = new Customer("Bill", false);
    Bill* bill1 = new Bill(customer1, kitchen->getFinance(), table);
    Customer* customer2 = new Customer("Bill", false);
    Bill* bill2 = new Bill(customer2, kitchen->getFinance(), table);
    Customer* customer3 = new Customer("Bill", false);
    Bill* bill3 = new Bill(customer3, kitchen->getFinance(), table);
    Customer* customer4 = new Customer("Bill", false);
    Bill* bill4 = new Bill(customer4, kitchen->getFinance(), table);
    Customer* customer5 = new Customer("Bill", false);
    Bill* bill5 = new Bill(customer5, kitchen->getFinance(), table);

    std::vector<std::string> food1{"Egg", "Egg", "Breadroll", "Steak", "Pumpkin"};
    std::vector<double> prices1{12, 12, 3, 45, 30};

    std::vector<std::string> food2{"Apple", "Apple", "Breadroll", "Strawberry", "Pumpkin"};
    std::vector<double> prices2{5, 5, 3, 3, 30};

    std::vector<std::string> food3{"Egg", "Steak", "Breadroll", "Steak", "Berry"};
    std::vector<double> prices3{12, 45, 3, 45, 5};

    std::vector<std::string> food4{"Banana", "Bread", "Grapes", "Steak", "Rice"};
    std::vector<double> prices4{7, 15, 10, 45, 12};

    std::vector<std::string> food5{"Apple", "Egg", "Grapes", "Steak", "Brocolli"};
    std::vector<double> prices5{5, 12, 10, 45, 20};

    kitchen->addNewOrder(new FoodOrder(food1,prices1,5,"Grilled",2,*customer1,bill1));
    kitchen->addNewOrder(new FoodOrder(food2,prices2,5,"Fried",2,*customer2,bill2));
    kitchen->addNewOrder(new FoodOrder(food3,prices3,5,"Grilled",2,*customer3,bill3));
    kitchen->addNewOrder(new FoodOrder(food4,prices4,5,"Fried",2,*customer4,bill4));
    kitchen->addNewOrder(new FoodOrder(food5,prices5,5,"Grilled",2,*customer5,bill5));

    kitchen->startKitchenProcess();
}