#ifndef RESTAURANT_H
#define RESTAURANT_H

class Restaurant {

private:
	Restaurant* uniqueInstance;

public:
	Restaurant* instance();

protected:
	Restaurant();

	Restaurant(Restaurant& restaurant);

	void operator=(Restaurant& restaurant);

public:
	void setup();

	void simulate();
};

#endif
