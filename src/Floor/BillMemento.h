#ifndef BILLMEMENTO_H
#define BILLMEMENTO_H

#include <vector>
#include <iostream>

class BillMemento 
{
	private:
		//std::string myBill;
		double totalCost;
		std::vector<std::string> items;

	public:
		BillMemento(const std::vector<std::string>& billItems, double cost);
		const std::vector<std::string>& getItems() const;
		double getTotalCost() const;

		//BillMemento(const Bill& bill);
		//BillMemento();
		//void setBill(std::string bill);
		//std::string getBill();

};

#endif
