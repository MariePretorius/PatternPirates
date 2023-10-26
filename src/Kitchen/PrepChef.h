#ifndef PREPCHEF_H
#define PREPCHEF_H

class PrepChef : Chef {


private:
	void sendOrder(Order* order);

	void handleStock();

public:
	void handleOrder();
};

#endif
