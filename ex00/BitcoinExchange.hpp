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
    // Orthodox Canonical Form
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& databaseFile);
    void evaluate(const std::string& inputFile) const;
};

#endif
