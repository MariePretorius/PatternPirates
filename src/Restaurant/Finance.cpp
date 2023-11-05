//
// Created by Tristan on 2023/10/23.
//

#include "Finance.h"

/**
 * @brief default constructor for the finance object
 */
Finance::Finance()
{
    this->funds = 0;
}

/**
 * @brief Constructor override the allows for initial funds to be set.
 * @param initialFunds the initial amount desired
 */
Finance::Finance(double initialFunds)
{
    this->funds = initialFunds;
}

/**
 * @brief adds the amount stated to the total fund pool
 * @param funds the amount desired
 */
void Finance::addFunds(double funds)
{
    this->funds += funds;
}

/**
 * @brief removes the amount stated from the total fund pool
 * @param funds the amount desired
 */
void Finance::removeFunds(double funds)
{
    this->funds -= funds;
}

/**
 * @brief sets the funds to the amount desired
 * @param funds the amount desired
 */
void Finance::setFunds(double funds)
{
    this->funds = funds;
}

/**
 * @brief returns the amount of funds currently in the pool
 * @return the int of funds
 */
double Finance::getFunds()
{
    return this->funds;
}
