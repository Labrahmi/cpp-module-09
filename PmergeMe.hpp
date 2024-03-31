#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <ctime>
#include <algorithm>



template <typename T>
void print_container(T container)
{
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}