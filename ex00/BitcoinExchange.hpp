#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;

public:
    BitcoinExchange(const std::string& dbFile);
    ~BitcoinExchange();

    void evaluate(const std::string& inputFile);

private:
    void loadDatabase(const std::string& dbFile);
    float getExchangeRate(const std::string& date) const;
};