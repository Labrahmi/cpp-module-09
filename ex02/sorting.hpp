#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "sorting.hpp"

std::string redText = "\033[1;31m";
std::string blueText = "\033[1;34m";
std::string yellowText = "\033[1;33m";
std::string resetText = "\033[0m";

void PmergeMe(const std::vector<unsigned int>& arr);

template <typename T>
void print_container(T container)
{
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

#endif