//
// Created by Tristan on 2023/11/06.
//

#include "ObserverSubject.h"

ObserverSubject::ObserverSubject()
{
    observerList = list<Observer*>();
}

ObserverSubject::~ObserverSubject()
{

}

void ObserverSubject::attach(Observer *observer)
{
    observerList.push_front(observer);
}

void ObserverSubject::detach(Observer *observer)
{
    list<Observer*>::iterator it = observerList.begin();
    for(it; it != observerList.end(); it++)
    {
        if(*it == observer)
        {
            observerList.erase(it);
            return;
        }
    }
}

void ObserverSubject::notify()
{
    for(Observer * o : observerList)
    {
        o->update();
    }
}
