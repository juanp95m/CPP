#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter(){};


static bool isPseudoLiteral(const std::string& str){
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inf" || str == "+inf"  || str == "nan")
		return true;
	else
		return false;
}


static bool IsChar(const std::string& str) {
	
}

void ScalarConverter::convert(const std::string& str) {

}