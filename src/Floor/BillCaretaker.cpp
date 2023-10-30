#include "BillCaretaker.h"

BillCaretaker :: BillCaretaker() {}

void BillCaretaker :: saveMemento(const BillMemento& memento)
{
    mementos.push_back(memento);
}

BillMemento BillCaretaker :: getMemento(int index) const
{
    if (index >= 0 && index < mementos.size())
    {
        return mementos[index];
    }
    return BillMemento({}, 0.0);
}

int BillCaretaker :: getMementoCount() const
{
    return mementos.size();
}