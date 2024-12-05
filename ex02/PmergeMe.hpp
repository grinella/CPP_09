#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <sstream> // Include per std::istringstream

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    // Utility functions
    void mergeSortVector(std::vector<int>& vec, int left, int right);
    void mergeVector(std::vector<int>& vec, int left, int mid, int right);

    void mergeSortDeque(std::deque<int>& deq, int left, int right);
    void mergeDeque(std::deque<int>& deq, int left, int mid, int right);

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

    // Core Functions
    void loadData(const std::string& data);
    void sortData();

    // Getters for Testing
    const std::vector<int>& getVectorData() const;
    const std::deque<int>& getDequeData() const;
};

#endif
