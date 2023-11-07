//
// Created by Tristan on 2023/11/06.
//
/**
 * @file Observer.h
 * @brief Declaration of observer class
 */
#ifndef PROJFINAL_OBSERVER_H
#define PROJFINAL_OBSERVER_H

/**
 * @file The declaration for the Observer participent
 * @brief Provides the interface through which waiters will interact with customer states.
 */
class Observer {
public:
    /**
     * @brief Constructor for the observer
     */
    Observer();
    /**
     * @brief Destructor for the obaserver
     */
    ~Observer();
    /**
     * @brief Update function for the Observer
     */
    virtual void update() = 0;
};


#endif //PROJFINAL_OBSERVER_H
