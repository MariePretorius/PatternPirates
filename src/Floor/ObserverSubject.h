//
// Created by Tristan on 2023/11/06.
//
/**
 * @file ObserverSubject.h
 * @brief provides an interface for the Waiters to observe their customers
 */
#ifndef PROJFINAL_OBSERVERSUBJECT_H
#define PROJFINAL_OBSERVERSUBJECT_H



#include "Observer.h"
#include <list>

using namespace std;

/**
 * @class ObserverSubject
 * @brief The class from which an observable class will inherit
 */
class ObserverSubject {
public:
    /**
     * @brief The constructor for the ObserverSubject class
     */
    ObserverSubject();
    /**
     * @brief The destructor for the ObserverSubject class
     */
    ~ObserverSubject();
    /**
     * @brief Adds a given observer to the list of Observers to be notified
     * @param observer The Observer object to be added
     */
    void attach(Observer * observer);
    /**
     * @brief Removes a given observer from the list of observers to be notified
     * @param observer The Observer object to be removed
     */
    void detach(Observer * observer);
    /**
     * @brief notifies all Observers in the vector to check their subject's state
     */
    void notify();
private:
    list<Observer*> observerList; ///> The list of observers to be notified
};


#endif //PROJFINAL_OBSERVERSUBJECT_H
