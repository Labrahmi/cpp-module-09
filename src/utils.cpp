#include "PmergeMe.hpp"

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

void printTimeVec(std::vector<unsigned int> initArray, double elapsedTimeVec)
{
    std::cout << "Time to process a range of "
              << initArray.size() << " elements with std::vector : "
              << (elapsedTimeVec * 1000000)
              << " us" << std::endl;
}
