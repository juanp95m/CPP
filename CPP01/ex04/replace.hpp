#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

bool processFile(const std::string &filename, std::ifstream &infile, std::ofstream &outfile);
std::string replaceLine(std::string line, const std::string &s1, const std::string &s2);


#endif