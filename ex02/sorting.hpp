
#ifndef SORTING_HPP
#define SORTING_HPP

std::string redText = "\033[1;31m";
std::string blueText = "\033[1;34m";
std::string yellowText = "\033[1;33m";
std::string resetText = "\033[0m";

void PmergeMe(const std::vector<int>& arr);
std::vector<int> split_vec(const std::vector<int>& arr);
std::vector<int> merge_sorted_vectors(const std::vector<int>& left, const std::vector<int>& right);

int x = 0;

template <typename T>
void print_container(T container, int mode)
{
    if (mode == 0)
        std::cout << redText;
    else if (mode == 1)
        std::cout << blueText;
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << container[i] << " ";
    std::cout << resetText << std::endl;
}

#endif