#include "BitcoinExchange.hpp"

void displayMap(std::map<std::string, float> &map)
{
    std::map<std::string, float>::iterator it = map.begin();
    std::map<std::string, float>::iterator ite = map.end();

    for (; it != ite; ++it)
    {
        std::cout << it->first << " | " << it->second << std::endl;
    }
}


int main(int argc, char **argv)
{
    std::map<std::string, float> data;
    if (argc == 2)
    {
        init_data("data.csv", data);
        //displayMap(data);
        format_input(argv[1], data); 
    }
}