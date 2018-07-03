#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void) {
	Bureaucrat  bureaucrat1("Bachir", 10);
	Bureaucrat  bureaucrat2("Issa", 15);
/*
	try {

		Bureaucrat  bureaucrat2("Issa", 149);
		bureaucrat2.decrementGrade();
		bureaucrat2.decrementGrade();
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}*/

	/*try {
		Form form("ACT1", 1, 151);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	try {
		Form form("ACT1", 0, 110);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
*/

/*	bureaucrat2.decrementGrade();
	Form form("BIRTHDAY-ACT");

	form.signForm(bureaucrat1);
	form.signForm(bureaucrat2);*/


	//std::cout << form << std::endl;

/*	Form form("ACT1", 10, 145);
	form.signForm(bureaucrat1);
	form.signForm(bureaucrat2);*/

	Form form("ACT1", 5, 145);
	try {
		form.beSigned(bureaucrat1);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}


	return (0);
}