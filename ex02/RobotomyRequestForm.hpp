#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include <ctime>
# include <cstdlib>
# include <iostream>

# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {
private:
	static const int _EXEC;
	static const int _SIGN;
	std::string _target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & robotomyRequestForm);
	~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(RobotomyRequestForm const & robotomyRequestForm);
	//std::ostream &operator<<(std::ostream const & out, RobotomyRequestForm const & robotomyRequestForm);

	virtual void execute(Bureaucrat const & executor) const;

	std::string    getTarget(void) const;
};

#endif