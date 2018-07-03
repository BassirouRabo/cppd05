#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class   Form {

	class GradeTooHighException: public std::exception {
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & gradeTooHighException);
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException &operator=(GradeTooHighException const & gradeTooHighException);

		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & gradeTooLowException);
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException  &operator= (GradeTooLowException const & gradeTooLowException);

		virtual const char *what() const throw();
	};

	class NotSignedException: public std::exception {
	public:
		NotSignedException(void);
		NotSignedException(NotSignedException const & gradeTooLowException);
		virtual ~NotSignedException(void) throw();

		NotSignedException  &operator= (NotSignedException const & gradeTooLowException);

		virtual const char *what() const throw();
	};

private:
	const std::string     _name;
	const std::string     _target;
	const int             _grade_to_sign;
	const int             _grade_to_execute;
	bool                  _is_signed;
	static const int        MIN;
	static const int        MAX;

public:
	Form(std::string name, std::string target);
	Form(std::string name, std::string target, int grade_to_sign, int grade_to_execute);
	Form(Form const & form);
	~Form(void);

	std::string         getName(void) const;
	std::string         getTarget(void) const;
	int                 getGradeToSign(void) const;
	int                 getGradeToExecute(void) const;
	bool                getIsSigned(void) const;
	void                setIsSigned(bool is_signed);

	Form &operator=(Form const & form);
	friend std::ostream &operator<<(std::ostream & out, Form const & form);

	void    beSigned(Bureaucrat & bureaucrat);
	void    signForm(Bureaucrat & bureaucrat);

	virtual void              execute(Bureaucrat const & executor) const = 0;

};

#endif