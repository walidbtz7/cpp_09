#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map<std::string, float> data;
    if (argc == 2)
    {
        init_data("data.csv", data);
        format_input(argv[1], data); 
    }
}