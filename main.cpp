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

void PmergeMe(std::vector<unsigned int> &initArray)
{
    std::sort(initArray.begin(), initArray.end());
}

void printTimeVec(std::vector<unsigned int> initArray, double elapsedTimeVec)
{
    std::cout << "Time to process a range of "
              << initArray.size() << " elements with std::vector : "
              << (elapsedTimeVec * 1000000)
              << " us" << std::endl;
}

int main(int ac, char **av)
{
    clock_t start, end;
    double elapsedTimeVec;
    if (ac > 1)
    {
        try
        {
            std::vector<unsigned int> initArray = setArray(ac, av);
            std::cout << "Before: ";
            print_container(initArray);
            start = clock();
            PmergeMe(initArray);
            end = clock();
            std::cout << "After: ";
            print_container(initArray);
            elapsedTimeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            printTimeVec(initArray, elapsedTimeVec);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}