#pragma once

#include <fstream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange
{

  private:
    static const std::string dbFileName;

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
};
