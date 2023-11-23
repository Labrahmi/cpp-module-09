
#include "sorting.hpp"

typedef struct s_pair
{
    unsigned int _first;
    unsigned int _second;
    bool hasSecond;
} t_pair;

void printPairs(std::vector<t_pair> &vecOfPairs)
{
    size_t i = 0;
    while (i < vecOfPairs.size())
    {
        std::cout << "(" << vecOfPairs[i]._first;
        if (vecOfPairs[i].hasSecond)
            std::cout << ", " << vecOfPairs[i]._second;
        std::cout << ")" << std::endl;
        i++;
    }
}

void swapIfNotOrde(t_pair &pair)
{
    unsigned int temp;
    if ((pair.hasSecond) && (pair._first > pair._second))
    {
        temp = pair._first;
        pair._first = pair._second;
        pair._second = temp;
    }
}

void insertPair(t_pair pair, std::vector<unsigned int> &lowPairs, std::vector<unsigned int> &highPairs)
{
    lowPairs.push_back(pair._first);
    if (pair.hasSecond)
        highPairs.push_back(pair._second);
}

void PmergeMe(std::vector<unsigned int> &arr)
{
    std::vector<t_pair> vecOfPairs;
    std::vector<unsigned int>::iterator it = arr.begin();
    size_t i = 0;
    while (it != arr.end())
    {
        t_pair p;
        p.hasSecond = false;
        p._first = (*it);
        it++;
        if (it != arr.end())
        {
            p._second = (*it);
            p.hasSecond = true;
            it++;
        }
        vecOfPairs.push_back(p);
    }
    std::vector<unsigned int> lowPairs;
    std::vector<unsigned int> highPairs;
    i = 0;
    while (i < vecOfPairs.size())
    {
        swapIfNotOrde(vecOfPairs[i]);
        insertPair(vecOfPairs[i], lowPairs, highPairs);
        i++;
    }
    // ------------------------------------------------------------------------------------------------
    std::vector<unsigned int> allPairs;
    for (std::vector<unsigned int>::iterator it = highPairs.begin(); it != highPairs.end(); ++it)
    {
        std::vector<unsigned int>::iterator pos = std::lower_bound(allPairs.begin(), allPairs.end(), *it, std::less<unsigned int>());
        allPairs.insert(pos, *it);
    }
    for (std::vector<unsigned int>::iterator it = lowPairs.begin(); it != lowPairs.end(); ++it)
    {
        std::vector<unsigned int>::iterator pos = std::lower_bound(allPairs.begin(), allPairs.end(), *it, std::less<unsigned int>());
        allPairs.insert(pos, *it);
    }
    std::cout << "allPairs: ";
    print_container(allPairs);
    // ------------------------------------------------------------------------------------------------
}

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));
    // -------------------------------
    unsigned int arr_size = 3000;
    std::vector<unsigned int> arr;
    for (size_t i = arr_size; i > 0; --i)
        arr.push_back(rand() % (10000)); // i
    std::cout << "init container: ";
    print_container(arr);
    std::cout << "-------------------------------\n\n" << std::endl;
    PmergeMe(arr);
    return 0;
}
