#include "ShrubberyCreatingForm.hpp"

ShrubberyCreatingForm::ShrubberyCreatingForm() : AForm("ShrubberyCreatingForm", 145, 137), _target("Default") {}

ShrubberyCreatingForm::ShrubberyCreatingForm(const std::string& target) : AForm("ShrubberyCreatingForm", 145, 137), _target(target){}

ShrubberyCreatingForm::ShrubberyCreatingForm(const ShrubberyCreatingForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreatingForm& ShrubberyCreatingForm::operator=(const ShrubberyCreatingForm& copy) {
	AForm::operator=(copy);
	return *this;
}

ShrubberyCreatingForm::~ShrubberyCreatingForm() {}

void ShrubberyCreatingForm::executeAction() const {
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw ShrubberyCreatingForm::FileOpenException();
	file << "     ccee88oo                 ccee88oo    "          << std::endl;
	file << " C8O8O8Q8PoOb o8oo        C8O8O8Q8PoOb o8oo   "      << std::endl;
	file << " dOB69QO8PdUOpugoO9bD     dOB69QO8PdUOpugoO9bD "     << std::endl;
	file << " CgggbU8OU qOp qOdoUOdcb  CgggbU8OU qOp qOdoUOdcb"   << std::endl;
	file << "   6OuU  /p u gcoUodpP       6OuU  /p u gcoUodpP"    << std::endl;
	file << "     \\|/   douUP               \\|/   douUP  "      << std::endl;
	file << "       \\||||/                    \\||||/  "         << std::endl;
	file << "        |||||                      ||||| "           << std::endl;
	file << "        |||||                      ||||| "           << std::endl;
	file << "        |||||                      ||||| "           << std::endl;
	file << "        |||||                      |||||  "          << std::endl;

	file.close();
}


const char* ShrubberyCreatingForm::FileOpenException::what() const throw() {
    return "Could not open or create the shrubbery file.";
}
	   


