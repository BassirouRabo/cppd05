#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {

private:
	static const int _EXEC;
	static const int _SIGN;
	std::string _target;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & presidentialPardonForm);
	~PresidentialPardonForm(void);

	PresidentialPardonForm & operator=(PresidentialPardonForm const & presidentialPardonForm);
	//std::ostream &operator<<(std::ostream const & out, PresidentialPardonForm const & presidentialPardonForm);

	virtual void execute(Bureaucrat const & executor) const;

	std::string    getTarget(void) const;
};

#endif