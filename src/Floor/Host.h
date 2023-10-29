#ifndef HOST_H
#define HOST_H
#include "Table.h"
#include "Floor.h"

class Host {


public:
	Table* first();

	Table* next();

	bool isFull();

	Table* currentTable();
};

#endif
