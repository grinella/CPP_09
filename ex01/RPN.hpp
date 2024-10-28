#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    RPN();
    ~RPN();
    int evaluate(const std::string& expression);

private:
    bool isOperator(const std::string& token) const;
    int performOperation(int operand1, int operand2, const std::string& op) const;
};