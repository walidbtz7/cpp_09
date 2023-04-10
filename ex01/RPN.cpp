
#include "RPN.hpp"

int isNumber(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

void parsing(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Wrong number of arguments!\n";
        std::exit(1);
    }
    std::string input = argv[1];
    int num_digits = 0;
    int num_ops = 0;
    for (int i = 0; i < (int) input.size(); i++) {
        char c = input[i];
        if (std::isdigit(c)) {
            num_digits++;
        } else if (c == '/' || c == '*' || c == '-' || c == '+') {
            num_ops++;
        } else if (!std::isspace(c)) {
            std::cerr << "Error: Invalid character in input: " << c << "\n";
            std::exit(1);
        }
    }
    if (num_digits == 0) {
        std::cerr << "Error: Input must contain at least one digit!\n";
        std::exit(1);
    }
    if (num_ops == 0) {
        std::cerr << "Error: Input must contain at least one operator!\n";
        std::exit(1);
    }
}
