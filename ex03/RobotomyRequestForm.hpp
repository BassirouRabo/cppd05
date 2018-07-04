
#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <fstream>

# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);

	~RobotomyRequestForm(void);

	RobotomyRequestForm		&operator= (const RobotomyRequestForm &rhs);

	virtual void				execute(const Bureaucrat &executor) const;

	static const std::string	name;

private:
	static const int			_sign;
	static const int			_exec;
};

#endif
