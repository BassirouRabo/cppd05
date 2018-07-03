#include "Form.hpp"

const int   Form::MIN = 150;
const int   Form::MAX = 1;

const char *Form::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}

Form::GradeTooHighException::GradeTooHighException(void) {
	return ;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &gradeTooHighException) {
	*this = gradeTooHighException;
	return;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const & gradeTooHighException) {
	void(gradeTooHighException);
	return (*this);
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}

Form::GradeTooLowException::GradeTooLowException(void) {
	return ;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &gradeTooLowException) {
	*this = gradeTooLowException;
	return ;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & gradeTooLowException) {
	(void) (gradeTooLowException);
	return (*this);
}

Form::GradeTooLowException::~GradeTooLowException(void) throw(){
	return ;
}

Form::Form(std::string name) :
		_name(name),
		_grade_to_sign(1),
		_grade_to_execute(1),
		_is_signed(false) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) :
		_name(name),
		_grade_to_sign(grade_to_sign),
		_grade_to_execute(grade_to_execute),
		_is_signed(false){
	if (grade_to_sign < MAX || grade_to_execute < MAX)
		throw Form::GradeTooHighException();
	if (grade_to_sign > MIN || grade_to_execute > MIN)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &form):
_name(form.getName()),
_grade_to_sign(form.getIsSigned()),
_grade_to_execute(form.getGradeToExecute()),
_is_signed(form.getIsSigned())
{
	*this = form;
	return ;
}

Form::~Form(void) {
/*	std::cout << "Form "
              << getName()
              << " destroyed"
              << std::endl;*/
}

int Form::getGradeToSign(void) const {
	return this->_grade_to_sign;
}

int Form::getGradeToExecute() const {
	return this->_grade_to_execute;
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
	    << form.getGradeToSign()
	    << ", Is signed "
	    << form.getIsSigned();
	return out;
}

void Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign())
		throw Form::GradeTooLowException();
	else
		setIsSigned(true);
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
				<< ". It has to be "
				<< getGradeToSign()
				<< ", but he has "
				<< bureaucrat.getGrade()
	              << std::endl;
	}
}