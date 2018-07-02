#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void) {
	Bureaucrat  bureaucrat("Bachir", 15);
	bureaucrat.decrementGrade();
	Form form("BIRTHDAY-ACT");

	form.signForm(bureaucrat);
	return (0);
}