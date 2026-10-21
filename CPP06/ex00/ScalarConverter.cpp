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


static bool isPseudoLiteral(const std::string& str) {
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf" ||
		str == "-inf"  || str == "+inf"  || str == "inf"  || str == "nan")
		return true;
	else
		return false;
}


static bool IsChar(const std::string& str) {
	if (str.length() == 1 && !isdigit(static_cast<int>(str[0])))
		return true;
	else
		return false;
}

static bool IsInt(const std::string& str){
	if (str.empty())
		return false;
	if (std::isspace(static_cast<unsigned char>(str[0])))
		return false;
	char* endptr = NULL;
	errno = 0;
	long num = std::strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str())
		return false;
	if (*endptr != '\0')
		return false;
	if (errno == ERANGE)
		return false;
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return false;
	return true;
}

static bool IsFloat(const std::string& str){
	if (str.empty() || std::isspace(static_cast<unsigned char>(str[0])))
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	char* endptr = NULL;
	errno = 0;
	std::strtof(str.c_str(), &endptr);
	if (errno == ERANGE)
	 	return false;
	if (endptr == str.c_str())
		return false;
	if (*endptr == 'f' && *(endptr + 1) =='\0')
		return true;
	else
		return false;
}

static bool IsDouble(const std::string& str){
	if (str.empty() || std::isspace(static_cast<unsigned char>(str[0])))
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	char* endptr = NULL;
	errno = 0;
	std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE)
	 	return false;
	if (endptr == str.c_str())
		return false;
	if (*endptr == '\0')
		return true;
	else
		return false;
}

static void printPseudoLiteral(const std::string& str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}


static void printChar(const std::string& str) {
	char ch = str[0];

	std::cout << "char: '" << ch << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(ch) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(ch) << std::endl;
}

static void printInt(const std::string& str) {
	long num = std::strtol(str.c_str(), NULL, 10);

	// Evaluación para char
	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(num)))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// Int
	std::cout << "int: " << static_cast<int>(num) << std::endl;

	// Float y Double
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

static void printFloat(const std::string& str) {
	float num = std::strtof(str.c_str(), NULL);

	// Char
	if (num < 0.0f || num > 127.0f)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(num)))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// Int (control de límites)
	if (static_cast<double>(num) < static_cast<double>(std::numeric_limits<int>::min()) ||
		static_cast<double>(num) > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	// Float y Double
	std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

static void printDouble(const std::string& str) {
	double num = std::strtod(str.c_str(), NULL);

	// Char
	if (num < 0.0 || num > 127.0)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(num)))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// Int (control de límites)
	if (num < static_cast<double>(std::numeric_limits<int>::min()) ||
		num > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	// Float (control de desbordamiento a float)
	if (num < -static_cast<double>(std::numeric_limits<float>::max()) ||
		num > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;

	// Double
	std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	if (isPseudoLiteral(str)) {
		printPseudoLiteral(str);
		return;
	}
	if (IsChar(str)) {
		printChar(str);
		return;
	}
	if (IsInt(str)) {
		printInt(str);
		return;
	}
	if (IsFloat(str)) {
		printFloat(str);
		return;
	}
	if (IsDouble(str)) {
		printDouble(str);
		return;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}