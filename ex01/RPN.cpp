#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<int> stack;
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: insufficient values for operation.");
            }
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            int result = performOperation(operand1, operand2, token);
            stack.push(result);
        } else {
            stack.push(std::stoi(token));
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid RPN expression.");
    }

    return stack.top();
}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int operand1, int operand2, const std::string& op) const {
    if (op == "+") {
        return operand1 + operand2;
    } else if (op == "-") {
        return operand1 - operand2;
    } else if (op == "*") {
        return operand1 * operand2;
    } else if (op == "/") {
        if (operand2 == 0) {
            throw std::runtime_error("Error: division by zero.");
        }
        return operand1 / operand2;
    } else {
        throw std::runtime_error("Error: unknown operator.");
    }
}