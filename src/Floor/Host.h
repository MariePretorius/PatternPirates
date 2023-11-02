#ifndef HOST_H
#define HOST_H
#include "Table.h"
#include "Floor.h"
#include <sstream>
#include <list>

using namespace std;
class Host {
private:
    Floor *f;
    list<Table *>tables;

public:
    Host(Floor* fl);

    void getAllTables(list<Table*> table);

	Table* first();

	Table* next(Table* curr);

	bool isFull();

	Table* getNextOpenTable();

    bool assignCustomer();

};

#endif
