#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>

void printVect(std::vector<int> vect)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << "\n";
}

void printVectOfVect(std::vector<std::vector<int> > vect)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        for (size_t j = 0; j < vect[i].size(); j++)
        {
            std::cout << vect[i][j] << " ";
        }
    }
    std::cout << "\n";
}

bool compareV(const std::vector<int> &a, const std::vector<int> &b)
{
    return (a.back() < b.back());
}

bool compareD(const std::deque<int> &a, const std::deque<int> &b)
{
    return (a.back() < b.back());
}

void sortVector(std::vector<std::vector<int> > &input, int index)
{
    std::vector<int> remain;
    if (input.size() == 1)
        return;
    if (input.size() % 2 != 0)
    {
        remain = input.back();
        input.pop_back();
    }
    size_t i = 0;
    std::vector<std::vector<int> > output;
    while (i < input.size())
    {
        if (i + 1 >= input.size())
            break;
        std::vector<int> firstVector = input[i];
        std::vector<int> secondVector = input[i + 1];
        std::vector<int> pair;

        if (firstVector.back() > secondVector.back())
            std::swap(firstVector, secondVector);

        pair.insert(pair.end(), firstVector.begin(), firstVector.end());
        pair.insert(pair.end(), secondVector.begin(), secondVector.end());

        output.push_back(pair);
        i += 2;
    }
    input.clear();
    input = output;
    sortVector(input, index * 2);

    std::vector<int> oneVector;
    for (size_t i = 0; i < input.size(); i++)
    {
        std::vector<int> yp = input[i];
        for (size_t j = 0; j < yp.size(); j++)
            oneVector.push_back(yp[j]);
    }
    std::vector<std::vector<int> > mainchin;
    std::vector<std::vector<int> > pend;
    for (size_t count = 0; count < oneVector.size(); count += index * 2)
    {
        std::vector<int> first, second;
        for (size_t i = count; i < count + index; i++)
            first.push_back(oneVector[i]);
        for (size_t i = count + index; i < count + (index * 2); i++)
            second.push_back(oneVector[i]);
        pend.push_back(first);
        mainchin.push_back(second);
    }
    if (remain.size() > 0)
        pend.push_back(remain);
    if (!pend.empty())
    {
        mainchin.insert(mainchin.begin(), pend.front());
        pend.erase(pend.begin());

        for (std::vector<std::vector<int> >::iterator it = pend.begin(); it < pend.end(); it++)
        {
            std::vector<std::vector<int> >::iterator iter = std::lower_bound(mainchin.begin(), mainchin.end(), *it, compareV);
            mainchin.insert(iter, *it);
        }
    }
    input.assign(mainchin.begin(), mainchin.end());
}

void sortDeque(std::deque<std::deque<int> > &input, int index)
{
    std::deque<int> remain;
    if (input.size() == 1)
        return;
    if (input.size() % 2 != 0)
    {
        remain = input.back();
        input.pop_back();
    }
    size_t i = 0;
    std::deque<std::deque<int> > output;
    while (i < input.size())
    {
        if (i + 1 >= input.size())
            break;
        std::deque<int> firstDeque = input[i];
        std::deque<int> secondDeque = input[i + 1];
        std::deque<int> pair;

        if (firstDeque.back() > secondDeque.back())
            std::swap(firstDeque, secondDeque);

        pair.insert(pair.end(), firstDeque.begin(), firstDeque.end());
        pair.insert(pair.end(), secondDeque.begin(), secondDeque.end());

        output.push_back(pair);
        i += 2;
    }
    input.clear();
    input = output;
    sortDeque(input, index * 2);

    std::deque<int> oneDeque;
    for (size_t i = 0; i < input.size(); i++)
    {
        std::deque<int> yp = input[i];
        for (size_t j = 0; j < yp.size(); j++)
            oneDeque.push_back(yp[j]);
    }
    std::deque<std::deque<int> > mainchin;
    std::deque<std::deque<int> > pend;
    for (size_t count = 0; count < oneDeque.size(); count += index * 2)
    {
        std::deque<int> first, second;
        for (size_t i = count; i < count + index; i++)
            first.push_back(oneDeque[i]);
        for (size_t i = count + index; i < count + (index * 2); i++)
            second.push_back(oneDeque[i]);
        pend.push_back(first);
        mainchin.push_back(second);
    }
    if (remain.size() > 0)
        pend.push_back(remain);
    if (!pend.empty())
    {
        mainchin.insert(mainchin.begin(), pend.front());
        pend.erase(pend.begin());

        for (std::deque<std::deque<int> >::iterator it = pend.begin(); it < pend.end(); it++)
        {
            std::deque<std::deque<int> >::iterator iter = std::lower_bound(mainchin.begin(), mainchin.end(), *it, compareD);
            mainchin.insert(iter, *it);
        }
    }
    input.assign(mainchin.begin(), mainchin.end());
}

int main(int ac, char **av)
{
    std::vector<std::vector<int> > inputVector;
    std::deque<std::deque<int> > inputDeque;

    if (ac < 2)
        return 1;
    int i = 1;
    while (av[i])
    {
        int number;
        std::stringstream iss(av[i]);
        iss >> number;

        std::vector<int> tempVector;
        std::deque<int> tempDeque;

        tempVector.push_back(number);
        tempDeque.push_back(number);

        inputVector.push_back(tempVector);
        inputDeque.push_back(tempDeque);

        i++;
    }

    std::cout << "Before: ";
    printVectOfVect(inputVector);

    clock_t time_start_vector = clock();
    sortVector(inputVector, 1);
    clock_t time_end_vector = clock();

    std::cout << "After: ";
    printVectOfVect(inputVector);
    std::cout << std::endl;

    clock_t time_start_deque = clock();
    sortDeque(inputDeque, 1);
    clock_t time_end_deque = clock();

    double time_vector_us = static_cast<double>(time_end_vector - time_start_vector) / CLOCKS_PER_SEC;
    double time_deque_us = static_cast<double>(time_end_deque - time_start_deque) / CLOCKS_PER_SEC;

    // ----------------------------------------------------------------------------------------------------------------------------------------
    std::cout << std::fixed << std::setprecision(5)
              << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << time_vector_us << " s" << std::endl;
    // ----------------------------------------------------------------------------------------------------------------------------------------
    std::cout << std::fixed << std::setprecision(5)
              << "Time to process a range of " << inputDeque.size() << " elements with std::deque: " << time_deque_us << " s" << std::endl;
    // ----------------------------------------------------------------------------------------------------------------------------------------
    return 0;
}
