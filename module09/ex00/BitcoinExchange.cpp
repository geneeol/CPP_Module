#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

const std::string BitcoinExchange::dbFileName = "data.csv";

BitcoinExchange::BitcoinExchange(const std::string &filName)
{
    inputFile.open(filName);
    dbFile.open(dbFileName);

    if (!inputFile.is_open() || !dbFile.is_open())
        throw std::exception();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    inputFile.open(other.fileName);
    dbFile.open(dbFileName);

    if (!inputFile.is_open() || !dbFile.is_open())
        throw std::exception();
}

BitcoinExchange::~BitcoinExchange()
{
    inputFile.close();
    dbFile.close();
}

std::ifstream &BitcoinExchange::getInputFile()
{
    return inputFile;
}

std::ifstream &BitcoinExchange::getDbFile()
{
    return dbFile;
}

void BitcoinExchange::fillDbMap()
{
    std::string line;

    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string date;
        double rate;
        if (std::getline(iss, date, ',') && (iss >> rate))
            db[date] = rate;
    }
}

void BitcoinExchange::printDbMap()
{
    for (std::map<std::string, double>::iterator it = db.begin();
         it != db.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
}