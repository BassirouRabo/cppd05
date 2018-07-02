#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int     main(void)
{


	try {
		Bureaucrat  bureaucrat("Bachir", 1);
		bureaucrat.decrementGrade();
	}catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

}