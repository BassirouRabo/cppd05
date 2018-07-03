#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void) {
	Bureaucrat  bureaucrat1("Bachir", 15);
	Bureaucrat  bureaucrat2("Issa", 15);

	bureaucrat2.decrementGrade();
	Form form("BIRTHDAY-ACT");

	form.signForm(bureaucrat1);
	form.signForm(bureaucrat2);
	return (0);
}