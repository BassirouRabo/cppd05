#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <fstream>

# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);

	~PresidentialPardonForm(void);

	PresidentialPardonForm		&operator= (const PresidentialPardonForm &rhs);

	virtual void				execute(const Bureaucrat &executor) const;

	static const std::string	name;

private:
	static const int			_sign;
	static const int			_exec;
};

#endif
