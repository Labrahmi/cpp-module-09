
#include "sorting.hpp"

typedef struct s_pair
{
    unsigned int _first;
    unsigned int _second;
    bool hasNoSecond;
} t_pair;

void printPairs(std::vector<t_pair> &vecOfPairs)
{
    int i = 0;
    while (i < vecOfPairs.size())
    {
        std::cout << "(" << vecOfPairs[i]._first;
        if (vecOfPairs[i].hasNoSecond)
            std::cout << ", " << vecOfPairs[i]._second;
        std::cout << ")" << std::endl;
        i++;
    }
}

void swapIfNotOrde(t_pair &pair)
{
    unsigned int temp;
    if (pair._first > pair._second)
    {
        temp = pair._first;
        pair._first = pair._second;
        pair._second = temp;
    }
}

void PmergeMe(std::vector<unsigned int> &arr)
{
    std::vector<t_pair> vecOfPairs;
    std::vector<unsigned int>::iterator it = arr.begin();
    int i = 0;
    while (it != arr.end())
    {
        t_pair p;
        p.hasNoSecond = false;
        p._first = (*it);
        it++;
        if (it != arr.end())
        {
            p._second = (*it);
            p.hasNoSecond = true;
            it++;
        }
        vecOfPairs.push_back(p);
    }
    printPairs(vecOfPairs);
    std::cout << "-------------------------------" << std::endl;
    i = 0;
    while (i < vecOfPairs.size())
    {
        swapIfNotOrde(vecOfPairs[i]);
        i++;
    }
    printPairs(vecOfPairs);
}

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));
    // -------------------------------
    unsigned int arr_size = 16;
    std::vector<unsigned int> arr;
    for (size_t i = arr_size; i > 0; --i)
        arr.push_back(rand() % (100));
    print_container(arr);
    std::cout << "-------------------------------" << std::endl;
    PmergeMe(arr);
    return 0;
}
