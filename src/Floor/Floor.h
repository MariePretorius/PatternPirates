//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_FLOOR_H
#define PROJ_FLOOR_H

#include <list>

class Customer;
class Host;

#include "Table.h"

class Floor
{
public:
    Floor();
    Host * createHost();
    int getCapacity();

private:
    std::list<Table> tables;
    int numberOfTables;
    std::list<Customer *> customers;
};



#endif //PROJ_FLOOR_H
