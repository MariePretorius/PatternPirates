//
// Created by user on 2023/11/03.
//

#include "WaiterTests.h"
WaiterTests::WaiterTests() {

}

bool WaiterTests::tests() {
    Finance * finance = new Finance();

    Waiter * waiter = new Waiter(finance);
    assert(waiter->getTables()->size() == 0);

    delete finance;
    delete waiter;
}
