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

template<class it, class it2, class it3>
void mergeSort(it first1, it last1,
           it2 first2, it2 last2,
           it3 result) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *result = *first1;
            ++first1;
        } else {
            *result = *first2;
            ++first2;
        }
        ++result;
    }
    while (first1 != last1) {
        *result = *first1;
        ++first1;
        ++result;
    }
    while (first2 != last2) {
        *result = *first2;
        ++first2;
        ++result;
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
    mergeSort(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vector));
    }
    else
        InsertSort(vector);
}

int main(int argc, char **argv)
{
    clock_t vector_start, vector_end, deque_start, deque_end;
    std::vector<int> vec;
    std::deque<int> dq;

   try 
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
   catch (std::exception& e)
   {
       std::cerr << e.what() << std::endl;
   }
   return (0);
}