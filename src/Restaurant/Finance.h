//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_FINANCE_H
#define PROJ_FINANCE_H


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
    double funds;
};


#endif //PROJ_FINANCE_H
