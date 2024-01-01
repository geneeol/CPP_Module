#pragma once

#include <string>

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

  public:
    static void convert(const std::string &str);
    static void convertChar(double d);
    static void convertInt(double d);
    static void convertFloat(double d);
    static void convertDouble(double d);
    // static void print() const;
};