#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int     main(void) {
	try {
		Bureaucrat  bureaucrat("Bachir", 2);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}