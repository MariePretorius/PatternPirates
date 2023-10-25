//
// Created by Tristan on 2023/10/23.
//

#include "Finance.h"

Finance::Finance()
{
    this->funds = 0;
}

Finance::Finance(double initialFunds)
{
    this->funds = initialFunds;
}

void Finance::addFunds(double funds)
{
    this->funds += funds;
}

void Finance::removeFunds(double funds)
{
    this->funds -= funds;
}

void Finance::setFunds(double funds)
{
    this->funds = funds;
}

double Finance::getFunds()
{
    return this->funds;
}
