//
// Created by user on 2023/11/03.
//

#include "WaiterTests.h"
WaiterTests::WaiterTests() {

}

bool WaiterTests::tests() {
    Finance * finance = new Finance();
    Ratings * ratings = new Ratings();
    Waiter * waiter = new Waiter(finance, ratings);
    assert(waiter->getTables()->size() == 0);
}
