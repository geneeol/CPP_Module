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

    std::getline(dbFile, line);
    while (std::getline(dbFile, line))
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
    for (std::map<std::string, double>::iterator it = db.begin(); it != db.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
}

std::map<std::string, double>::iterator BitcoinExchange::findClosestLowerDate(const std::string &inputDate)
{
    std::map<std::string, double>::iterator it = db.lower_bound(inputDate);

    if (it == db.begin() && it->first != inputDate)
        throw std::exception();

    if (it != db.end() && it->first == inputDate)
        return it;

    if (it != db.begin())
        --it;

    return it;
}

void BitcoinExchange::calcAndPrint()
{
    std::string line;
    t_coinVal coinVal;

    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;
        try
        {
            coinVal = parseInputLine(line);
            std::map<std::string, double>::iterator it = findClosestLowerDate(coinVal.date);
            double result = coinVal.val * it->second;
            std::cout << coinVal.date << " => " << coinVal.val << " = " << result << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Error: not valid input data => " << line << std::endl;
        }
    }
}

bool BitcoinExchange::invalidDate(const std::string &date)
{
    if (date.length() != 10)
        return true;
    int year, month, day;
    std::istringstream dateStream(date);
    char dash1, dash2;
    char junk;

    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dateStream.fail() || dash1 != '-' || dash2 != '-' || (dateStream >> junk))
    {
        return true;
    }

    if (month < 1 || month > 12 || day < 1)
    {
        return true;
    }

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1])
    {
        return true;
    }

    return false;
}

t_coinVal BitcoinExchange::parseInputLine(const std::string &line)
{
    std::istringstream lineStream(line);

    size_t delimPos = line.find('|');
    if (delimPos == std::string::npos)
    {
        throw std::exception();
    }

    std::string dateStr = line.substr(0, delimPos);
    std::string valueStr = line.substr(delimPos + 1);
    std::istringstream valueStream(valueStr);
    double value;
    char junk;

    if (dateStr.length() != 11 || dateStr.back() != ' ')
        throw std::exception();
    dateStr.erase(dateStr.length() - 1);
    if (valueStr.empty() || valueStr.front() != ' ')
        throw std::exception();

    if (invalidDate(dateStr) || !(valueStream >> value) || (valueStream >> junk) ||
        value < static_cast<double>(MIN_VAL) || value > static_cast<double>(MAX_VAL))
        throw std::exception();
    return (t_coinVal){dateStr, value};
}