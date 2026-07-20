#include "replace.hpp"

bool processFile(const std::string &filename, std::ifstream &infile, std::ofstream &outfile){
	
	std:: string outfileName;
	infile.open(filename.c_str());
	if (!infile.is_open()){
		std::cout << "Cannot open infile" << std::endl;
		return false;
	}

	outfileName = filename + ".replace";
	outfile.open(outfileName.c_str());
	if (!outfile.is_open()){
		std::cout << "Cannot open outfile" << std::endl;
		infile.close();
		return false;
	}
	return true;
}