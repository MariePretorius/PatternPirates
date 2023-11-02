#include "BillCaretaker.h"

/**
 * @brief Default constructor for BillCaretaker
*/
BillCaretaker :: BillCaretaker() {}

/**
 * @brief Saves the memento in the vector.
 * @param memento BillMemento object to save.
*/
void BillCaretaker :: saveMemento(const BillMemento& memento)
{
    mementos.push_back(memento);
}

/**
 * @brief Returns the memento at a certain index.
 * @param index Index of the memento you want returned.
 * @return Returns a BillMemento object.
*/
BillMemento BillCaretaker :: getMemento(int index) const
{
    if (index >= 0 && index < mementos.size())
    {
        return mementos[index];
    }
    return BillMemento({}, 0.0);
}

/**
 * @brief Function that returns the amount of the mementos stored in the vector.
 * @return Returns integer value of the amount of mementos.
*/
int BillCaretaker :: getMementoCount() const
{
    return mementos.size();
}