#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortSequence(const std::vector<int>& sequence);

private:
    void mergeInsertSort(std::vector<int>& vec);
    void mergeInsertSort(std::list<int>& lst);
};