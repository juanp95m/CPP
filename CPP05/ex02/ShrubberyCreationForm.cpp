#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	AForm::operator=(copy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileOpenException();
	file << "     ccee88oo          "    << std::endl;
	file << " C8O8O8Q8PoOb o8oo     "    << std::endl;
	file << " dOB69QO8PdUOpugoO9bD  "    << std::endl;
	file << " CgggbU8OU qOp qOdoUOdcb "  << std::endl;
	file << "   6OuU  /p u gcoUodpP "    << std::endl;
	file << "     \\\/   douUP     "     << std::endl;
	file << "       \\\/\/\/       "     << std::endl;
	file << "        |||/\         "     << std::endl;
	file << "        |||\/         "     << std::endl;
	file << "        |||||         "     << std::endl;
	file << "       /|||||\      "       << std::endl;

	file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Could not open or create the shrubbery file.";
}
	   


