#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input.txt>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        exchange.evaluate(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
