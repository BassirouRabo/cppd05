#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::_SIGN = 25;
const int PresidentialPardonForm::_EXEC = 5;

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardon", "UNKNOWN", _SIGN, _EXEC){
	this->_target = "UNKNOWN";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardon", target, _SIGN, _EXEC) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm):
		Form("PresidentialPardon", presidentialPardonForm._target,  _SIGN, _EXEC) {
	*this = presidentialPardonForm;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &obj) {
	(void)obj;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::cout << this->Form::getTarget()
	          << " has been pardoned by Zafod Beebkerox."
              << std::endl;
}