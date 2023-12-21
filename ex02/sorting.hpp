#ifndef SORTING_HPP
#define SORTING_HPP

// io
#include <iostream>
#include <sstream>
#include "sorting.hpp"
// STL
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
// Time
#include <ctime>
#include <iomanip>
// Err
#include <exception>

std::string redText = "\033[1;31m";
std::string blueText = "\033[1;34m";
std::string yellowText = "\033[1;33m";
std::string resetText = "\033[0m";

void PmergeMe(const std::vector<unsigned int>& arr);

#include <iostream>
#include <vector>
#include <algorithm>

bool isOddLength(const std::vector<int>& arr);
int findStraggler(std::vector<int>& arr);
std::vector<std::vector<int>> createPairs(const std::vector<int>& arr);
std::vector<std::vector<int>> sortEachPair(const std::vector<std::vector<int>>& splitArray);
void insertionSortPairs(std::vector<std::vector<int>>& A, int n);
int jacobsthal(int n);
std::vector<int> buildJacobInsertionSequence(const std::vector<int>& array);
void sortLargerValue(std::vector<std::vector<int>>& sortedSplitArray);
std::vector<int> createS(const std::vector<std::vector<int>>& sortedSplitArray, int straggler, bool printComparisonEstimation);
std::vector<int> mergeInsertionSort(std::vector<int> A);

#endif