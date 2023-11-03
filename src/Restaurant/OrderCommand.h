#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

/**
 * @class OrderCommand Class
 * This class is abstract. This class is the Command participant in the Command design pattern.
*/
class OrderCommand
{
	public:
		/**
		 * @brief Default constructor for the class.
		*/
		OrderCommand();

		/**
		 * @brief Pure virtual function for the execute command.
		*/
		virtual void execute() = 0;
};

#endif
