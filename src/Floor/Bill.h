#ifndef BILL_H
#define BILL_H

class Bill {

private:
	string myBill;

public:
	Bill();

	BillMemento createMemento();

	void restoreMemento(const BillMemento memento);
};

#endif
