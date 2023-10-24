//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_FLOOR_H
#define PROJ_FLOOR_H

#include <list>

class Table;

class Floor
{
public:
    Floor();
    int getCapacity();

private:
    //std::list<Table> tables;
    int numberOfTables;
};


#endif //PROJ_FLOOR_H
