#ifndef BILL_H
#define BILL_H

#include "BillMemento.h"
#include "Customer.h"
#include "../Restaurant/Finance.h"

#include <iostream>
#include <vector>
#include <sstream>

/**
 * @class Bill
 * @brief The Bill class is the originator in the Memento pattern. 
*/
class Bill 
{
	private:
		std::vector<std::string> items;  ///< List of items on the bill.
		double totalCost;  ///< Current total cost of the bill.
		Customer& customer;  ///< Reference to a customer object.
		int custID;  ///< ID of the customer the bill belongs to.
		Finance& bank;

		bool tab;  ///< Boolean value set to indicate whether the bill is a tab.
		bool paid;  ///< Boolean value set to indicate whether the bill has been paid.
		//int count;

	public:
		/**
		 * @brief Default constructor for Bill.
		*/
		Bill(Customer& customer, Finance& f);

		/**
		 * @brief Function to add items onto the bill
		 * @param item The menu item to be added onto the bill.
		 * @param cost The price of the menu item to be added onto the bill.
		*/
		void addItem(const std::string& item, double cost);

		/**
		 * @brief Function to create the Bill Memento.
		 * @return BillMemento object is returned.
		*/
		BillMemento createMemento() const;

		/**
		 * @brief Restores the info from the given Memento.
		 * @param memento BillMemento object.
		*/
		void restoreFromMemento(const BillMemento& memento);

		/**
		 * @brief Displayes the current state of the bill.
		*/
		void showBill() const;

		/**
		 * @brief Set the tab boolean value.
		 * @param tab Boolean value to set the tab variable.
		*/
		void setTab(bool tab);

		/**
		 * @brief Pay the bill with the given amount if at least the cost is given.
		 * @param id ID of the customer the bill belongs to
		*/
		void payBill(int id);

		/**
		 * @brief Function to check whether the bill has been paid.
		 * @return Returns true if bill is paid and false otherwise.
		*/
		bool isPaid();
};

#endif
