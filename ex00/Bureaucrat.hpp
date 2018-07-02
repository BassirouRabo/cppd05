#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>
# include <string>

class   Bureaucrat {

	class GradeTooHighException: public std::exception {
		virtual const char *what() const throw() {
			return ("The grade can't be more than 150");
		}
	};

	class GradeTooLowException: public std::exception {
		virtual const char *what() const throw() {
			return ("The grade can't be less than 1");
		}
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
	void                incrementGrade(void);
	void                decrementGrade(void);

	friend std::ostream &operator<<(std::ostream & out, Bureaucrat const & bureaucrat);
};

#endif