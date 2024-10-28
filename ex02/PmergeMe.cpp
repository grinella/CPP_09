#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortSequence(const std::vector<int>& sequence) {
    std::vector<int> vec(sequence);
    std::list<int> lst(sequence.begin(), sequence.end());

    auto startVec = std::chrono::high_resolution_clock::now();
    mergeInsertSort(vec);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedVec = endVec - startVec;

    auto startLst = std::chrono::high_resolution_clock::now();
    mergeInsertSort(lst);
    auto endLst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedLst = endLst - startLst;

    std::cout << "Before: ";
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector: " << elapsedVec.count() << "s" << std::endl;
    std::cout << "Time to process a range of " << sequence.size() << " elements with std::list: " << elapsedLst.count() << "s" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    std::sort(vec.begin(), vec.end());
}

void PmergeMe::mergeInsertSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;
    lst.sort();
}