#ifndef BILLCARETAKER_H
#define BILLCARETAKER_H

#include "BillMemento.h"
#include <string>

using namespace std;

class BillCaretaker {

private:
	bool tab;
	string items;
	bool paid;

	int count;

public:
	BillCaretaker();

	void saveMemento(const BillMemento& memento);

	BillMemento getMemento(int index);

	int getMementoCount();

	void payBill();

	double calculateTotal();
};

#endif
