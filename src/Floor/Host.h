#ifndef HOST_H
#define HOST_H

class Host {


public:
	Table* first();

	Table* next();

	boolean isFull();

	Table* currentTable();
};

#endif
