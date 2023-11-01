#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

class OrderCommand
{
	public:
		OrderCommand();
		virtual void execute() = 0;
};

#endif
