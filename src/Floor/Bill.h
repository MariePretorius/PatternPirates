#ifndef BILL_H
#define BILL_H

#include "BillMemento.h"


#include <iostream>
#include <vector>
class Bill 
{
	private:
		//std::string myBill;
		std::vector<std::string> items;
		double totalCost;

		bool tab;
		bool paid;
		//int count;

	public:
		Bill();
		void addItem(const std::string& item, double cost);
		BillMemento createMemento() const;
		void restoreFromMemento(const BillMemento& memento);
		void showBill() const;
		void isTab(bool tab);
};

#endif
