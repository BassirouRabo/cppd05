#include "Form.hpp"

const int   MIN = 1;
const int   MAX = 150;

Form::Form(std::string name) : _name(name), _grade(15), _is_signed(false) {}

Form::Form(std::string name, bool is_signed) : _name(name), _grade(15), _is_signed(is_signed) {}

Form::~Form(void) {
/*	std::cout << "Form "
              << getName()
              << " destroyed"
              << std::endl;*/
}

int Form::getGrade(void) const {
	return this->_grade;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_is_signed;
}

void Form::setIsSigned(bool is_signed) {
	this->_is_signed = is_signed;
}

Form & Form::operator=(Form const & form) {
	this->_is_signed = form.getIsSigned();
	return *this;
}

std::ostream & operator<<(std::ostream & out, Form const & form) {
	out << form.getName()
	    << ", form grade "
	    << form.getGrade()
	    << ", Is signed "
	    << form.getIsSigned();
	return out;
}

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() >= getGrade())
		setIsSigned(true);
	else
		throw Form::GradeTooLowException();
}

void    Form::signForm(Bureaucrat & bureaucrat) {
	try {
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName().c_str()
		          << " signs "
		          << getName()
		          << std::endl;
	} catch (std::exception & exception) {
		std::cout << bureaucrat.getName().c_str()
		          << " cannot sign "
		          << getName()
		          << " because his "
		          << exception.what()
	              << std::endl;
	}
}