//
// Created by user on 2023/11/03.
//


#include "FinanceTests.h"
#include "iostream"

using namespace std;
FinanceTests::FinanceTests() {
    this->finance = new Finance(80000);
}

FinanceTests::~FinanceTests() {
    delete this->finance;
}

bool FinanceTests::tests() {
    try
    {
        assert(finance->getFunds() == 80000);
        finance->addFunds(597);
        assert(finance->getFunds() == 80597);
        finance->removeFunds(10000);
        assert(finance->getFunds() == 70597);
        finance->setFunds(5);
        assert(finance->getFunds() == 5);
    }
    catch(...)
    {
        std::cout << "\033[35mFinances Test Failed.\033[0m" << std::endl;
        return false;
    }
    std::cout << "\033[35mFinances Test Successful!\033[0m" << std::endl;
    return true;
}
