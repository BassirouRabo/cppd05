#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Form
{
	public:


		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(const GradeTooLowException &src);
				virtual ~GradeTooLowException(void) throw();

				GradeTooLowException &operator= (const GradeTooLowException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};


		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(const GradeTooHighException &src);
				virtual ~GradeTooHighException(void) throw();

				GradeTooHighException &operator= (const GradeTooHighException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		class NotSignedException : public std::exception
		{
			public:
				NotSignedException(void);
				NotSignedException(const NotSignedException &src);
				virtual ~NotSignedException(void) throw();

				NotSignedException &operator= (const NotSignedException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		Form(void);
		Form(const Form &src);
		Form(std::string targer, std::string name,\
				int grade_to_sign, int grade_to_execute);

		~Form(void);

		Form					&operator= (const Form &obj);
		friend std::ostream		&operator<< (std::ostream &out,\
				const Form &obj);

		void					beSigned(Bureaucrat bureaucrat);

		bool					getSigned(void) const;
		int						getGradeToSign(void) const;
		int						getGradeToExecute(void) const;
		std::string				getName(void) const;
		std::string				getTarget(void) const;

		virtual void			execute(const Bureaucrat &executor) const = 0;

	private:
		bool					_signed;
		const int				_grade_to_sign;
		const int				_grade_to_execute;
		const std::string		_name;
		const std::string		_target;
};

#endif
