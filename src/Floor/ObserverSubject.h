//
// Created by Tristan on 2023/11/06.
//

#ifndef PROJFINAL_OBSERVERSUBJECT_H
#define PROJFINAL_OBSERVERSUBJECT_H

/**
 * @file The declaration for the Subject participent
 * @brief provides an interface for the Waiters to observe their customers
 */

#include "Observer.h"
#include <list>

using namespace std;
class ObserverSubject {
public:
    ObserverSubject();
    ~ObserverSubject();
    void attach(Observer * observer);
    void detach(Observer * observer);
    void notify();
private:
    list<Observer*> observerList;
};


#endif //PROJFINAL_OBSERVERSUBJECT_H
