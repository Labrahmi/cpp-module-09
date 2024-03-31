#include "PmergeMe.hpp"

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