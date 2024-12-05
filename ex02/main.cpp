#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./pmergeme \"<numbers separated by spaces>\"\n";
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.loadData(argv[1]);
        std::cout << "Sorting data...\n";
        sorter.sortData();

        std::cout << "Sorted Vector: ";
        const std::vector<int>& vecData = sorter.getVectorData();
        for (std::vector<int>::const_iterator it = vecData.begin(); it != vecData.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";

        std::cout << "Sorted Deque: ";
        const std::deque<int>& deqData = sorter.getDequeData();
        for (std::deque<int>::const_iterator it = deqData.begin(); it != deqData.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
