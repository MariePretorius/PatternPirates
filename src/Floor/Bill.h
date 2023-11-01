#ifndef BILL_H
#define BILL_H

#include "BillMemento.h"
//#include "Customer.h"

//comment added somewhere


#include <iostream>
#include <vector>
#include <sstream>
class Bill 
{
	private:
		//std::string myBill;
		std::vector<std::string> items;
		double totalCost;
		//Customer& customer;
		//std::string custID/name;  add when that function is added to customer

		bool tab;
		bool paid;
		//int count;

	public:
		Bill();  //(Customer& customer);
		void addItem(const std::string& item, double cost);
		BillMemento createMemento() const;
		void restoreFromMemento(const BillMemento& memento);
		void showBill() const;
		void setTab(bool tab);
		void payBill(double amount);
		bool isPaid();
};

#endif
