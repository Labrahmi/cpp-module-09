
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "sorting.hpp"

std::vector<int> split_vec(const std::vector<int>& arr, int mode = 0)
{
    size_t half_size = (arr.size() / 2);
    std::vector<int> temp;
    if (mode == 0)
        temp.assign(arr.begin(), arr.begin() + half_size);
    else
        temp.assign(arr.begin() + half_size, arr.end());
    std::cout << yellowText << x++ << ": " << resetText;
    if (temp.size() == 2)
    {
        if (temp[0] > temp[1])
        {
            int temp_val = temp[0];
            temp[0] = temp[1];
            temp[1] = temp_val;
        }
    }
    print_container(temp, mode);
    return temp;
}

void PmergeMe(const std::vector<int>& arr)
{
    if (arr.size() > 2)
    {
        PmergeMe(split_vec(arr, 0));
        PmergeMe(split_vec(arr, 1));
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    // -------------------------------
    unsigned int arr_size = 16;
    std::vector<int> arr;
    for (size_t i = arr_size; i > 0; --i)
        arr.push_back(i);
    print_container(arr, 2);
    std::cout << "<-------------------------->" << std::endl;
    // -------------------------------
    PmergeMe(arr);
    return 0;
}
