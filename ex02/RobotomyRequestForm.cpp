#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_SIGN = 72;
const int RobotomyRequestForm::_EXEC = 45;

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy", "UNKNOWN", _SIGN, _EXEC) {
	this->_target = "UNKNOWN";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", target, _SIGN, _EXEC){
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) :
		Form("Robotomy", robotomyRequestForm._target, _SIGN, _EXEC) {
	*this = robotomyRequestForm;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & robotomyRequestForm) {
	(void)robotomyRequestForm;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	if (rand() & 1) {
		std::cout
				<< "BZZZZZZZZZZ..."
				<< Form::getTarget()
				<< " has been robotomized successfully !" << std::endl;
	} else {
		std::cout << "The "
		          << Form::getTarget()
		          << "robotomization failed !"
		          << std::endl;
	}
}