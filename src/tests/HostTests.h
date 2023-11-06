//
// Created by HP PC on 05/11/2023.
//

#ifndef COS214PA2_HOSTTESTS_H
#define COS214PA2_HOSTTESTS_H
#include <cassert>
#include "../Floor/Host.h"
#include "../Floor/Table.h"
#include "../Floor/Floor.h"
#include "../Restaurant/Finance.h"
#include "../Kitchen/Shelf.h"
#include "../Kitchen/Kitchen.h"


class HostTests {
public:
    HostTests();
    void TestScenario();
    ~HostTests();
private:
    Floor* f;
    list<Table*> tables;
    vector<Customer*> customers;
    Host * host;

};


#endif //COS214PA2_HOSTTESTS_H
