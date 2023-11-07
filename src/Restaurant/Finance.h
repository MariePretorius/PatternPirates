//
// Created by Tristan on 2023/10/23.
//
/**
 * @file Finance.h
 * @brief The declaration for the Finance class
 */
#ifndef PROJ_FINANCE_H
#define PROJ_FINANCE_H

/**
 * @class Finance
 * @brief Manages the funds of the restaurant
 */
class Finance
{
public:
    Finance();
    Finance(double initialFunds);

    void addFunds(double funds);
    void removeFunds(double funds);
    void setFunds(double funds);
    double getFunds();

private:
    double funds; ///< The current funds in the "Bank"
};


#endif //PROJ_FINANCE_H
