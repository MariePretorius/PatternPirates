#ifndef BILL_H
#define BILL_H

#include "BillMemento.h"

class Bill {

private:
	string myBill;

public:
	Bill();

	BillMemento createMemento();

	void restoreMemento(const BillMemento memento);
};

#endif
