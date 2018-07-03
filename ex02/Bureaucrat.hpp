#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Form;

class   Bureaucrat {

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

private:
	const std::string   _name;
	int                 _grade;
	static const int    MAX;
	static const int    MIN;

public:
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat const & bureaucrat);

	Bureaucrat &operator=(Bureaucrat const & bureaucrat);

	std::string         getName(void) const;
	int                 getGrade(void) const;
	void                setGrade(int grade);
	void                incrementGrade(void);
	void                decrementGrade(void);

	void					signForm(Form &form);
	void					executeForm(Form const & form);

	friend std::ostream &operator<<(std::ostream & out, Bureaucrat const & bureaucrat);
};

#endif