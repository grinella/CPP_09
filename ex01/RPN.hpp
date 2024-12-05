#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <iostream>

class RPN {
public:
    RPN();                               // Costruttore di default
    RPN(const RPN &other);               // Costruttore di copia
    RPN &operator=(const RPN &other);    // Operatore di assegnazione
    ~RPN();                              // Distruttore

    int evaluate(const std::string &expression);

private:
    std::stack<int> _stack;

    bool isOperator(char c) const;
    void performOperation(char op);
};

#endif
