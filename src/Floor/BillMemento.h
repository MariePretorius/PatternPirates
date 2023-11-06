/**
 * @file BillMemento.h
 * @brief Declaration of the BillMemento class.
 */

#ifndef BILLMEMENTO_H
#define BILLMEMENTO_H

#include <vector>
#include <iostream>

/**
 * @class BillMemento class.
 * @brief The BillMemento class acts as the Memento participant in the Bill Memento design pattern.
*/
class BillMemento 
{
	private:
		//std::string myBill;
		double totalCost;  ///< The current total cost of the bill.
		std::vector<std::string> items;  ///< Vector containing the list of menu items on the bill.
		//comment added somewhere

	public:
		/**
		 * @brief Parameterized constructor for the BillMemento class.
		 * @param billItems Menu items to be initialized on the bill.
		 * @param cost Joined cost of the menu items that are being added onto the bill.
		*/
		BillMemento(const std::vector<std::string>& billItems, double cost);

		/**
		 * @brief Returns the vector containing the items on the bill.
		 * @return Returns a vector of strings containing the items on the bill.
		*/
		const std::vector<std::string>& getItems() const;

		/**
		 * @brief Returns the current total cost of the bill.
		 * @return Returns a double representing the current total price of the bill.
		*/
		double getTotalCost() const;

		//BillMemento(const Bill& bill);
		//BillMemento();
		//void setBill(std::string bill);
		//std::string getBill();

};

#endif
