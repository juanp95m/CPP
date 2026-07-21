#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	std::string lvls[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;
	std::string input = argv[1];

	for(int i = 0; i < 4; i++){
		if (input == lvls[i]){
			index = i;
			break;
		}
	}
	Harl harl;

	switch (index)
	{
	case 0:
		harl.complain("DEBUG");
		/* fall through */
	case 1:
		harl.complain("INFO");
		/* fall through */
	case 2:
		harl.complain("WARNING");
		/* fall through */
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return 0;
}