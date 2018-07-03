#ifndef SHRUBERRY_CREATION_FORM_H
# define SHRUBERRY_CREATION_FORM_H

# include <fstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {

private:
	static const int _SIGN;
	static const int _EXEC;
	std::string _target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & shrubberyCreationForm);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & shrubberyCreationForm);
	//std::ostream &operator<<(std::ostream const & out, ShrubberyCreationForm const & shrubberyCreationForm);

	virtual void execute(Bureaucrat const & executor) const;

	std::string    getTarget(void) const;
};

#endif