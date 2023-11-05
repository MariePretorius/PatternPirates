#ifndef HOST_H
#define HOST_H
#include "Table.h"
#include "Floor.h"
#include <sstream>
#include <list>

using namespace std;
    /**
     * @class Host
     * @brief Host is responsible for the seating of customers at the start of the simulation. Host is an Iterator.
    */
class Host {
private:
    Floor *f; ///<Reference to the floor.
    list<Table *>tables; ///< Reference to all the tables on the floor.
    vector<Customer* >customers; ///< Reference to all the customers waiting to be seated.

public:
    /**
	 * @brief Default constructor for Host.
     * @param fl A reference to the floor so that host can seat customers at tables on the floor.
    */
    Host(Floor* fl);

    /**
	 * @brief First returns the first table on the floor
	*/
	Table* first();

/**
	 * @brief next returns a pointer to the next table on the floor based on the current table
	 * @param curr a reference to the current table of which we want to the the next table.
	*/
	Table* next(Table* curr);

    /**
	 * @brief isFull iterates over all the tables on the floor and checks to see if all tables are occupied.
	*/
	bool isFull();

    /**
	 * @brief getNextOpenTable iterates over all the tables on the floor and returns the first table that isn't occupied
	*/
	Table* getNextOpenTable();

    /**
	 * @brief AssignCustomer calls getNextOpenTable and seats the number of customers at the open table based on the table's capacity
     */
    bool assignCustomer();

    /**
	 * @brief SetCustomers just sets the waiting customers
     * @param c list of customers waiting to be seated - called in Restaurant
	*/
    void setCustomers(vector<Customer*> c);

    /**
	 * @brief setTables sets the tables on the floor
     * @param t list of all tables on the floor -called in Restaurant
	*/
    void setTables(list<Table*> t);
    /**
     * @brief Destructor for Host
     */
    ~Host();

};

#endif
