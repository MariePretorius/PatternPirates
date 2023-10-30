#ifndef BILL_H
#define BILL_H

class Bill {
//hellooooooooo i am testing commits
private:
	string myBill;

public:
	Bill();

	BillMemento createMemento();

	void restoreMemento(const BillMemento memento);
};

#endif
