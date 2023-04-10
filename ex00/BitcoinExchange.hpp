#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <cstdlib>
# include <fstream> 
# include <map>


void init_data(std::string filename, std::map<std::string, float> &map);
void format_input(std::string input, std::map<std::string, float> &map);
#endif