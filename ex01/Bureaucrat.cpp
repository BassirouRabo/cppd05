#include "Bureaucrat.hpp"


const int Bureaucrat::MIN = 1;
const int Bureaucrat::MAX = 150;

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < Bureaucrat::MIN)
		throw Bureaucrat::GradeTooLowException();
	if (grade > Bureaucrat::MAX)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) {
	*this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &bureaucrat) {
	this->_grade = bureaucrat.getGrade();
	return *this;
}
std::ostream & operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName()
	    << ", bureaucrat grade "
	    << bureaucrat.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < Bureaucrat::MIN)
		throw Bureaucrat::GradeTooLowException();
	if (grade > Bureaucrat::MAX)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

void Bureaucrat::incrementGrade(void) {
	if (getGrade() + 1 > Bureaucrat::MAX)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
}

void Bureaucrat::decrementGrade(void) {
	if (getGrade() - 1 < Bureaucrat::MIN)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
}