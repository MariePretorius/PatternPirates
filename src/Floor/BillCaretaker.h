#ifndef BILLCARETAKER_H
#define BILLCARETAKER_H

#include "BillMemento.h"

//comment added somewhere
#include <iostream>
#include <vector>

/**
 * @class BillCaretaker class.
 * @brief This class acts as the Caretaker in the Bill Memento design pattern.
*/
class BillCaretaker 
{
	private:
		//bool tab;  
		//std::string items;
		//bool paid;
		//int count;

		std::vector<BillMemento> mementos;  ///< Vector of BillMemento objects used for undo/redo functionality.

	public:
		/**
		 * @brief Default constructor for BillCaretaker
		*/
		BillCaretaker();

		/**
		 * @brief Saves the memento in the vector.
		 * @param memento BillMemento object to save.
		*/
		void saveMemento(const BillMemento& memento);

		/**
		 * @brief Returns the memento at a certain index.
		 * @param index Index of the memento you want returned.
		 * @return Returns a BillMemento object.
		*/
		BillMemento getMemento(int index) const;

		/**
		 * @brief Function that returns the amount of the mementos stored in the vector.
		 * @return Returns integer value of the amount of mementos.
		*/
		int getMementoCount() const;

		//void payBill();    move to Bill class
		//double calculateTotal();
};

#endif
