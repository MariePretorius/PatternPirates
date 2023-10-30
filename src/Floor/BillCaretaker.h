#ifndef BILLCARETAKER_H
#define BILLCARETAKER_H

#include "BillMemento.h"

#include <iostream>
#include <vector>

class BillCaretaker 
{
	private:
		bool tab;
		//std::string items;
		bool paid;
		int count;

		std::vector<BillMemento> mementos;

	public:
		BillCaretaker();
		void saveMemento(const BillMemento& memento);
		BillMemento getMemento(int index) const;
		int getMementoCount() const;

		//void payBill();    move to Bill class
		//double calculateTotal();
};

#endif
