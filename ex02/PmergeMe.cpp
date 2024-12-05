#include "PmergeMe.hpp"

// Orthodox Canonical Form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

// Utility Functions for Merge Sort (Vector)
void PmergeMe::mergeSortVector(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortVector(vec, left, mid);
        mergeSortVector(vec, mid + 1, right);
        mergeVector(vec, left, mid, right);
    }
}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1;
    std::size_t k = 0;

    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }
    while (i <= mid) temp[k++] = vec[i++];
    while (j <= right) temp[k++] = vec[j++];

    for (std::size_t p = 0; p < temp.size(); ++p) {
        vec[left + p] = temp[p];
    }
}

// Utility Functions for Merge Sort (Deque)
void PmergeMe::mergeSortDeque(std::deque<int>& deq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortDeque(deq, left, mid);
        mergeSortDeque(deq, mid + 1, right);
        mergeDeque(deq, left, mid, right);
    }
}

void PmergeMe::mergeDeque(std::deque<int>& deq, int left, int mid, int right) {
    std::deque<int> temp(right - left + 1);
    int i = left, j = mid + 1;
    std::size_t k = 0;

    while (i <= mid && j <= right) {
        if (deq[i] <= deq[j]) {
            temp[k++] = deq[i++];
        } else {
            temp[k++] = deq[j++];
        }
    }
    while (i <= mid) temp[k++] = deq[i++];
    while (j <= right) temp[k++] = deq[j++];

    for (std::size_t p = 0; p < temp.size(); ++p) {
        deq[left + p] = temp[p];
    }
}


// Core Functions
void PmergeMe::loadData(const std::string& data) {
    std::istringstream ss(data); // Cambiato da std::stringstream a std::istringstream
    int number;
    while (ss >> number) {
        _vectorData.push_back(number);
        _dequeData.push_back(number);
    }
    if (ss.fail() && !ss.eof()) {
        throw std::invalid_argument("Invalid input data");
    }
}

void PmergeMe::sortData() {
    clock_t start = clock();
    mergeSortVector(_vectorData, 0, _vectorData.size() - 1);
    clock_t end = clock();
    std::cout << "Vector sort time: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";

    start = clock();
    mergeSortDeque(_dequeData, 0, _dequeData.size() - 1);
    end = clock();
    std::cout << "Deque sort time: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds\n";
}

const std::vector<int>& PmergeMe::getVectorData() const {
    return _vectorData;
}

const std::deque<int>& PmergeMe::getDequeData() const {
    return _dequeData;
}
