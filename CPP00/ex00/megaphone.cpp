#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		bool	isascii = false;
		for (int i = 1; i < argc; i++){
			for (int j = 0; argv[i][j]; j++){
				if ((unsigned char)argv[i][j] > 127)
					isascii = true;
			}
		}
		if (isascii){
			std::cout << "Error, only ascii." << std::endl;
			return (1);
		}
		else{
			for (int i = 1; i < argc; i++)
				for (int j = 0; argv[i][j]; j++)
					std::cout << (char) std::toupper(argv[i][j]);
				
		}
		std::cout << std::endl;
	}
	return (0);
}