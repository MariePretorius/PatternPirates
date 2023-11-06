#include "Bill.h"
#include <sstream>

/**
 * @brief Default constructor for Bill.
*/
Bill :: Bill(Customer * customer, Finance * f, Table* table)
{
    totalCost = 0.0;
    tab = false;
    paid = false;
    this->customer = customer;
    custID = customer->getCustomerID();
    this->bank = f;
    this->table = table;

    std::cout << "\x1B[33m";
    std::cout << "Customer " << custID << ": Bill Created" << std::endl;
    std::cout << "\x1B[0m";
}

/**
 * @brief Function to add items onto the bill
 * @param item The menu item to be added onto the bill.
 * @param cost The price of the menu item to be added onto the bill.
*/
void Bill :: addItem(const std::string& item, double cost)
{
    items.push_back(item);
    totalCost += cost;
}

/**
 * @brief Function to create the Bill Memento.
 * @return BillMemento object is returned.
*/
BillMemento Bill :: createMemento() const
{
    return BillMemento(items, totalCost);
}

/**
 * @brief Restores the info from the given Memento.
 * @param memento BillMemento object.
*/
void Bill :: restoreFromMemento(const BillMemento& memento)
{
    items = memento.getItems();
    totalCost = memento.getTotalCost();
}

/**
 * @brief Displayes the current state of the bill.
*/
void Bill :: showBill() const
{
    std::cout << "\x1B[33m";  //Change color to purple

    std::cout << "Bill Items:" << std::endl;
    for (const std::string& item : items)
    {
        std::cout << "- " << item << std::endl;
    }
    std::cout << "Total Cost: R" << totalCost << std::endl;

    std::cout << "\x1B[0m";  //Change color back to normal
}

/**
 * @brief Returns a string that displayes the current state of the bill.
 * @return Returns a string of the bill state.
*/
std::string Bill :: showBill(bool testing)
{
    std::string out = "";
    std::stringstream ss;
    std::string cost = "";

    out += "Bill Items:\n";
    for (const std::string& item : items)
    {
        out += "- " + item + "\n";
    }    

    ss << totalCost;
    ss >> cost;

    out += "Total Cost: R" + cost + "\n";

    return out;
}

/**
 * @brief Set the tab boolean value.
 * @param tab Boolean value to set the tab variable.
*/
void Bill :: setTab(bool tab)
{
    this->tab = tab;

    std::cout << "\x1B[33m";

    //std::cout << "This bill has been set to a tab." << std::endl;
    std::cout << "Customer " << custID << " has set their bill to a tab." << std::endl;

    std::cout << "\x1B[0m";
}

/**
 * @brief Pay the bill with the given amount if at least the cost is given.
 * @param id ID of the customer the bill belongs to
*/
void Bill :: payBill(int id)
{
    if (id == custID)
    {
        double costPaid = totalCost;
        std::stringstream ss;
        std::string cost = "";
        double tip = 0.0;

        tip = costPaid * 0.15;
        costPaid = costPaid + tip;

        std::cout << "\x1B[33m";

        totalCost = 0.0;
        
        //call finances function to add money
        bank->addFunds(costPaid);

        paid = true;

        ss << costPaid;
        ss >> cost;

        //std::cout << "Customer's bill has been paid. Total was: R" << cost << std::endl;
        std::cout << "Customer " << custID << "'s bill has been paid. Total was: R" << cost << std::endl;

        std::cout << "\x1B[0m";
    }
    else
    {
        std::cout << "\x1B[33m";

        std::cout << "ID given does not match the ID of this bill" << std::endl;

        std::cout << "\x1B[0m";
    }
}


/**
 * @brief Function to check whether the bill has been paid.
 * @return Returns true if bill is paid and false otherwise.
*/
bool Bill :: isPaid()
{
    return paid;
}

/**
 * @brief Function that returns a reference to the table the bill belongs to.
 * @return Returns a reference to a Table object.
*/
Table* Bill :: getTable()
{
    return this->table;
}

/**
 * @brief Function that returns a reference to the customer the bill belongs to.
 * @return Returns a reference to a Customer object.
*/
Customer* Bill :: getCustomer()
{
    return this->customer;
}

/**
 * @brief Function that returns a boolean value true id the bill is a tab.
 * @return Returns a boolean value.
*/
bool Bill :: getTab()
{
    return this->tab;
}

// example usage
// std::cout << "\x1B[33m"; 

// Bill bill;
// BillCaretaker caretaker;

// bill.addItem("Burger", 40.99);
// bill.addItem("Fries", 25.99);

// caretaker.saveMemento(bill.createMemento());

// bill.addItem("Soda", 15.95);

// std::cout << "Current Bill:\n";
// bill.showBill();

// bill.restoreFromMemento(caretaker.getMemento(0));

// std::cout << "\nRestored Bill:\n";
// bill.showBill();

// bill.setTab(true);
// bill.payBill(100.00);

// bool paid = bill.isPaid();
// if (paid)
//     std::cout << "Bill Paid" << std::endl;
// else
//     std::cout << "Not Paid" << std::endl;

// std::cout << "\x1B[0m"; 
