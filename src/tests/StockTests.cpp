//
// Created by user on 2023/11/03.
//

#include "StockTests.h"
#include <iostream>

StockTests::StockTests() {

}

bool StockTests::tests() {
    Stock * stock1 = new Stock("randomStock1", 20, 2.50, 0);
    Stock * stock2 = new Ingredient("randomStock2", 30, 5.00, 0);

    Shelf * shelf = new Shelf();

    assert(stock1->getName().compare("randomStock1") == 0);
    assert(stock1->getCostPerUnit() == 2.50);

    assert(stock2->getName().compare("randomStock2") == 0);
    assert(stock2->getCostPerUnit() == 5.00);
    stock2->removeStock(5);
    shelf->addStock(stock1);
    shelf->addStock(stock2);

    assert(shelf->getStockListVector().size() == 2);
    Stock * temp = shelf->deductStock("randomStock1");
    assert(temp == stock1);
    std::cout << "\033[35mStock Test Successful!\033[0m" << std::endl;

    delete stock1;
    delete stock2;
    delete shelf;

    return true;
}
