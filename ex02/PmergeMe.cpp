#include "PmergeMe.hpp"

void printMe(std::string name, std::vector<int> vec)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

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

template<typename T>
T InsertSort(T& vector)
{
    for (size_t i = 1; i < vector.size(); ++i) {
        for (size_t j = i; j > 0 && vector[j] < vector[j-1]; --j) {
            std::swap(vector[j], vector[j-1]);
        }
    }
    return vector;
}


template<typename T>
void MergeInsertSort(T& vector)
{
    if (vector.size() <= 5)
        return InsertSort(vector);
    size_t mid = vector.size() / 2;
    T left(vector.begin(), vector.begin() + mid);
    T right(vector.begin() + mid, vector.end());
    MergeSort(left);
    MergeSort(right);
    vector.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vector));
}