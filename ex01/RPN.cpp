#include "RPN.hpp"

// Costruttore di default
RPN::RPN() {}

// Costruttore di copia
RPN::RPN(const RPN &other) {
    *this = other;
}

// Operatore di assegnazione
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack; // Copia lo stato dello stack
    }
    return *this;
}

// Distruttore
RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(char op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: Invalid expression");
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    int result = 0;
    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        if (b == 0) {
            throw std::runtime_error("Error: Division by zero");
        }
        result = a / b;
    }

    _stack.push(result);
}

int RPN::evaluate(const std::string &expression) {
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            performOperation(token[0]);
        } else {
            int value;
            try {
                value = std::stoi(token);
            } catch (...) {
                throw std::runtime_error("Error: Invalid token");
            }
            _stack.push(value);
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: Invalid expression");
    }

    return _stack.top();
}
