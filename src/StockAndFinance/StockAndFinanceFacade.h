//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_STOCKANDFINANCEFACADE_H
#define PROJ_STOCKANDFINANCEFACADE_H

#include "Finance.h"
#include "Shelf.h"

class StockAndFinanceFacade
{
public:
    StockAndFinanceFacade();

    void addFunds(double funds);
    void removeFunds(double funds);
    void setFunds(double funds);
    double getFunds();

};


#endif //PROJ_STOCKANDFINANCEFACADE_H
