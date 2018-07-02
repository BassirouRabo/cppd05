#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class   Form {

	class GradeTooHighException: public std::exception {
		virtual const char *what() const throw() {
			return ("grade is too high");
		}
	};

	class GradeTooLowException: public std::exception {
		virtual const char *what() const throw() {
			return ("grade is too low");
		}
	};

private:
	const std::string     _name;
	const int             _grade;
	bool                  _is_signed;
	static const int        MIN;
	static const int        MAX;

public:
	Form(std::string name);
	Form(std::string name, bool is_signed);
	Form(Form const & form);
	~Form(void);

	std::string         getName(void) const;
	int                 getGrade(void) const;
	bool                getIsSigned(void) const;
	void                setIsSigned(bool is_signed);

	Form &operator=(Form const & form);
	friend std::ostream &operator<<(std::ostream & out, Form const & form);

	void    beSigned(Bureaucrat & bureaucrat);
	void    signForm(Bureaucrat & bureaucrat);

};

#endif