#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <fstream>

class ShrubberyCreationForm : public AForm {

	private:
		const std::string _target;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();
	
	virtual void executeAction() const;
		
	class FileOpenException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif