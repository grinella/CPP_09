#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;
        if (iss >> date >> rate) {
            _exchangeRates[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    auto it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.end() || (it != _exchangeRates.begin() && it->first != date)) {
        --it;
    }
    return it->second;
}

void BitcoinExchange::evaluate(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float value;
        if (iss >> date >> value) {
            if (value < 0 || value > 1000) {
                std::cerr << "Error: value out of range." << std::endl;
                continue;
            }
            try {
                float rate = getExchangeRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
}