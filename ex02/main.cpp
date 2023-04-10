#include "PmergeMe.hpp"

template <typename T>
void printMe(std::string name, std::vector<T> vec)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    clock_t vector_start, vector_end, deque_start, deque_end;
    std::vector<int> vec;
    std::deque<int> dq;

    if (argc >= 3)
    {
        parse(vec, dq, argc, argv);
        printMe("Before", vec);
        vector_start = clock();
        vector_end = clock();
        printMe("After", vec);
        deque_start = clock();
        deque_end = clock();
        std::cout << "Time to process a range of " << argc - 1 << " numbers using a vector: " << (vector_end - vector_start) / (double)CLOCKS_PER_SEC << " seconds" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " numbers using a deque: " << (deque_end - deque_start) / (double)CLOCKS_PER_SEC << " seconds" << std::endl;
    }
    else 
    {
        std::cout << "Error: bad arguments" << std::endl;
        exit(0);
    } 
}