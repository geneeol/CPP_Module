#pragma once

#include <string>

class RPN
{
  private:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(RPN const &other);

  public:
    static void postfixCalc(std::string input);
};
