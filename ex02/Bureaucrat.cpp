#include "Bureaucrat.hpp"

const int Bureaucrat::MIN = 150;
const int Bureaucrat::MAX = 1;

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too high, it can't be less than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low, it can't me more than 150");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &gradeTooHighException) {
	*this = gradeTooHighException;
	return ;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & gradeTooHighException)
{
	(void)gradeTooHighException;
	return (*this);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &gradeTooLowException) {
	*this = gradeTooLowException;
	return ;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & gradeTooLowException)
{
	(void)gradeTooLowException;
	return (*this);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {
	return ;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < Bureaucrat::MAX)
		throw Bureaucrat::GradeTooLowException();
	if (grade > Bureaucrat::MIN)
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
	if (grade < Bureaucrat::MAX)
		throw Bureaucrat::GradeTooLowException();
	if (grade > Bureaucrat::MIN)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

void Bureaucrat::decrementGrade(void) {
	if (getGrade() + 1 > Bureaucrat::MIN)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::incrementGrade(void) {
	if (getGrade() - 1 < Bureaucrat::MAX)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::signForm(Form & form) {
	try
	{
		form.beSigned(*this);
		std::cout << this->getName()
		          << " signs "
		          << form.getName()
		          << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << this->getGrade()
		          << " cannot sign "
		          << form.getName()
		          << " because "
		          << exception.what()
		          << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->_name
		          << " executes "
		          << form.getName()
		          << " on target "
		          << form.getTarget()
		          << std::endl;
	}
	catch (std::exception & exception) {
		std::cout << this->_name
		          << " has failed to execute "
		          << form.getName()
		          << " because "
		          << exception.what() << std::endl;
	}
}