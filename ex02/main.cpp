#include "PmergeMe.hpp"

template<typename T>
void InsertSort(T& vector)
{
    for (size_t i = 1; i < vector.size(); ++i) {
        for (size_t j = i; j > 0 && vector[j] < vector[j-1]; --j) {
            std::swap(vector[j], vector[j-1]);
        }
    }
}


template<typename T>
void MergeInsertSort(T& vector)
{
    if (vector.size() > 5)
    {
    size_t mid = vector.size() / 2;
    T left(vector.begin(), vector.begin() + mid);
    T right(vector.begin() + mid, vector.end());
    MergeInsertSort(left);
    MergeInsertSort(right);
    vector.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vector));
    }
    else
        InsertSort(vector);
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
        MergeInsertSort(vec);
        vector_end = clock();
        printMe("After", vec);
        deque_start = clock();
        MergeInsertSort(dq);
        deque_end = clock();
        std::cout << "Time to process a range of " << argc - 1 << " numbers using a vector: " << (vector_end - vector_start) / (double) CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " numbers using a deque: " << (deque_end - deque_start) / (double) CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
    }
    else 
    {
        std::cout << "Error: bad arguments" << std::endl;
        exit(0);
    } 
}