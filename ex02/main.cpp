
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

void insertPairDeque(t_pair pair, std::deque<unsigned int> &lowPairs, std::deque<unsigned int> &highPairs)
{
    lowPairs.push_back(pair._first);
    if (pair.hasSecond)
        highPairs.push_back(pair._second);
}

void PmergeMeDeque(std::deque<unsigned int> &arr)
{
    std::deque<t_pair> vecOfPairs;
    std::deque<unsigned int>::iterator it = arr.begin();
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
    std::deque<unsigned int> lowPairs;
    std::deque<unsigned int> highPairs;
    i = 0;
    while (i < vecOfPairs.size())
    {
        swapIfNotOrde(vecOfPairs[i]);
        insertPairDeque(vecOfPairs[i], lowPairs, highPairs);
        i++;
    }
    // ------------------------------------------------------------------------------------------------
    std::deque<unsigned int> allPairs;
    for (std::deque<unsigned int>::iterator it = highPairs.begin(); it != highPairs.end(); ++it)
    {
        std::deque<unsigned int>::iterator pos = std::lower_bound(allPairs.begin(), allPairs.end(), *it, std::less<unsigned int>());
        allPairs.insert(pos, *it);
    }
    for (std::deque<unsigned int>::iterator it = lowPairs.begin(); it != lowPairs.end(); ++it)
    {
        std::deque<unsigned int>::iterator pos = std::lower_bound(allPairs.begin(), allPairs.end(), *it, std::less<unsigned int>());
        allPairs.insert(pos, *it);
    }
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
    std::cout << "After: ";
    print_container(allPairs);
    // ------------------------------------------------------------------------------------------------
}

std::vector<unsigned int> setArray(int ac, char **av)
{
    std::vector<unsigned int> initArray;
    for (int i = 1; i < ac; i++)
    {
        unsigned int prot;
        std::stringstream stream(av[i]);
        if (stream >> prot)
            initArray.push_back(prot);
        else
            throw std::runtime_error("Not a positive integer!");
    }
    return initArray;
}

std::deque<unsigned int> setDeque(int ac, char **av)
{
    std::deque<unsigned int> initDeque;
    for (int i = 1; i < ac; i++)
    {
        unsigned int prot;
        std::stringstream stream(av[i]);
        if (stream >> prot)
            initDeque.push_back(prot);
        else
            throw std::runtime_error("Not a positive integer!");
    }
    return initDeque;
}

void printTimeVec(std::vector<unsigned int> initArray, double elapsedTimeVec)
{
    std::cout << "Time to process a range of "
              << initArray.size() << " elements with std::vector : "
              << std::fixed
              << std::setprecision(6)
              << (elapsedTimeVec * 1000000)
              << " us" << std::endl;
}

void printTimeDeque(std::deque<unsigned int> initArray, double elapsedTimeVec)
{
    std::cout << "Time to process a range of "
              << initArray.size() << " elements with std::deque : "
              << std::fixed
              << std::setprecision(6)
              << (elapsedTimeVec * 1000000)
              << " us" << std::endl;
}

int main(int ac, char **av)
{
    clock_t start;
    clock_t end;
    double elapsedTimeVec;
    if (ac > 1)
    {
        try
        {
            std::vector<unsigned int> initArray = setArray(ac, av);
            std::deque<unsigned int> initDeque = setDeque(ac, av);
            // ------------------------------
            std::cout << "Before: ";
            print_container(initArray);
            // ------------------------------
            start = clock();
            PmergeMe(initArray);
            end = clock();
            elapsedTimeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            printTimeVec(initArray, elapsedTimeVec);
            // ------------------------------
            start = clock();
            PmergeMeDeque(initDeque);
            end = clock();
            elapsedTimeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            printTimeDeque(initDeque, elapsedTimeVec);
            // ------------------------------
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
