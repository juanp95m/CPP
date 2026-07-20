#include "replace.hpp"

int main(int argc, char **argv)
{
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (argc != 4){
		std::cout << "Error: invalid arguments number" << std::endl;
		return 1;
	}
	if (s1.empty()){
		std::cout << "Error: S1 cannot be empty" << std::endl;
		return 1;
	}
	std::ifstream infile;
	std::ofstream outfile;
	if (!processFile(filename, infile, outfile))
		return 1;
	std::string line;
	while (std::getline(infile, line)){
		outfile << replaceLine(line, s1, s2) << std::endl;
	}
	infile.close();
	outfile.close();

	return 0;
}
