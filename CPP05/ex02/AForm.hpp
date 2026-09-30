#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {

	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	protected:
		virtual void executeAction() const = 0;

	public:
	AForm();
	AForm(const AForm& copy);
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm& operator=(const AForm& copy);
	virtual ~AForm();
	
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToExecute() const;
	int getGradeToSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);
	
	void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif