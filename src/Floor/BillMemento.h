#ifndef BILLMEMENTO_H
#define BILLMEMENTO_H

class BillMemento {

private:
	string myBill;

public:
	void setBill(string bill);

	string getBill();

	BillMemento(const Bill& bill);

	BillMemento();
};

#endif
