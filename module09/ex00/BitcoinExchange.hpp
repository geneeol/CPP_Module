#pragma once

#include <fstream>
#include <map>
#include <sstream>
#include <string>

typedef struct
{
    std::string date;
    double val;
} t_coinVal;

class BitcoinExchange
{

  private:
    static const std::string dbFileName;
    static const int MAX_VAL = 1000;
    static const int MIN_VAL = 0;

  private:
    BitcoinExchange();
    BitcoinExchange &operator=(BitcoinExchange const &other);
    std::string fileName;
    std::ifstream inputFile;
    std::ifstream dbFile;
    std::map<std::string, double> db;

  public:
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange(const std::string &fileName);
    std::ifstream &getInputFile();
    std::ifstream &getDbFile();
    void fillDbMap();
    void printDbMap();
    std::map<std::string, double>::iterator findClosestLowerDate(const std::string &inputDate);
    void calcAndPrint();
    bool invalidDate(const std::string &date);
    t_coinVal parseInputLine(const std::string &line);
};
