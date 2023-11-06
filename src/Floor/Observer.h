//
// Created by Tristan on 2023/11/06.
//

#ifndef PROJFINAL_OBSERVER_H
#define PROJFINAL_OBSERVER_H

/**
 * @file The declaration for the Observer participent
 * @brief Provides the interface through which waiters will interact with customer states.
 */
class Observer {
public:
    Observer();
    ~Observer();
    virtual void update() = 0;
};


#endif //PROJFINAL_OBSERVER_H
