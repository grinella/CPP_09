#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;

    void parseInput(const std::string& line, std::string& date, float& value) const;
    float getExchangeRate(const std::string& date) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string& databaseFile);
    void evaluate(const std::string& inputFile) const;
};

#endif
