#include <iostream>
#include <string>
#include <fstream>

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
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()){
		std::cout << "Cannot open infile" << std::endl;
		return 1;
	}

	std::string outfileName = filename + ".replace";

	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open()){
		std::cout << "Cannot open outfile" << std::endl;
		infile.close();
		return 1;
	}
	infile.close();
	outfile.close();

	return 0;
}