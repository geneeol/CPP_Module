#include "RPN.hpp"
#include "RPNException.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

void RPN::postfixCalc(std::string input)
{
    std::stack<int> stack;
    std::istringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
        {
            stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw RPNException("Error: Insufficient operands for operation");

            int val2 = stack.top();
            stack.pop();
            int val1 = stack.top();
            stack.pop();
            int result;

            switch (token[0])
            {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0)
                        throw RPNException("Error: Division by zero");
                    result = val1 / val2;
                    break;
                default:
                    throw RPNException("Error: Unknown operator");
            }
            stack.push(result);
        }
        else
        {
            throw RPNException("Error: Invalid token '" + token + "'");
        }
    }
    if (stack.size() != 1)
    {
        throw RPNException("Error: Malformed expression - final stack size is not 1");
    }
    std::cout << stack.top() << std::endl;
}