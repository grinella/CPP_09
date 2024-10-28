#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i) {
        int num;
        std::istringstream iss(argv[i]);
        if (!(iss >> num) || num < 0) {
            std::cerr << "Error: invalid input " << argv[i] << std::endl;
            return 1;
        }
        sequence.push_back(num);
    }

    try {
        PmergeMe pmerge;
        pmerge.sortSequence(sequence);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
