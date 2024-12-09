#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_exchangeRates = other._exchangeRates; // Copia lo stato dell' _exchangeRates
        }
    return *this;;
}

void BitcoinExchange::loadDatabase(const std::string& databaseFile) {
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;

        if (std::getline(iss, date, ',') && iss >> rate) {
            _exchangeRates[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.begin() && it->first != date) {
        throw std::out_of_range("Error: date is before the first available rate.");
    }

    if (it == _exchangeRates.end() || it->first != date) {
        --it;
    }

    return it->second;
}

void BitcoinExchange::parseInput(const std::string& line, std::string& date, float& value) const {
    std::istringstream iss(line);
    char delimiter;

    if (!(iss >> date >> delimiter >> value) || delimiter != '|') {
        throw std::invalid_argument("Error: bad input.");
    }
}

void BitcoinExchange::evaluate(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        try {
            std::string date;
            float value;

            parseInput(line, date, value);

            if (value < 0) {
                std::cout << date << " => Error: not a positive number." << std::endl;
            } else if (value > 1000000) {
                std::cout << date << " => Error: too large a number." << std::endl;
            } else {
                float rate = getExchangeRate(date);
                std::cout << date << " => " << value * rate << std::endl;
            }
        } catch (const std::out_of_range& e) {
            std::cerr << line << " => " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << line << " => " << e.what() << std::endl;
        }
    }
    file.close();
}
