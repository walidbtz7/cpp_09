#include "PmergeMe.hpp"

int isNumber(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

void parse(std::vector<int>& vec, std::deque<int>& dq, int argc, char **argv)
{
	int tmp;
	size_t i;

    i = 1;
    for (int i = 1; i < argc; ++i) {
        if (isNumber(argv[i])) {
            tmp = std::stoi(argv[i]);
            vec.push_back(tmp);
            dq.push_back(tmp);
        } 
        else
        {
            std::cout << "Error: bad arguments" << std::endl;
            exit(0);
        }
    }
	while (i < vec.size() && vec[i] > vec[i-1])
		i++;
	if (i == vec.size() )
	{
		std::cout << "Numbers are already sorted!" << std::endl;
		exit (0);
	}
}
