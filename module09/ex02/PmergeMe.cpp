#include "PmergeMe.hpp"
#include "PmergeMeException.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::initInput(const char **input)
{
    int i = 0;
    int inputVal;
    double val;
    char *endptr;

    while (input[i])
    {
        val = strtod(input[i], &endptr);
        if (endptr[0] != '\0' || val <= 0 || val != std::floor(val))
            throw PmergeMeException("Invalid input");
        inputVal = static_cast<int>(val);
        vec.push_back(inputVal);
        deq.push_back(inputVal);
        i++;
    }
    if (isDuplicated(vec))
        throw PmergeMeException("Duplicated input");
}

void PmergeMe::initInput(const std::string &input)
{
    int i = 0;
    int val;
    std::istringstream iss(input);

    while (iss >> val)
    {
        vec.push_back(val);
        deq.push_back(val);
        i++;
    }
    if (isDuplicated(vec))
        throw PmergeMeException("Duplicated input");
}

bool PmergeMe::isAcendingOrder(std::vector<int> &vec)
{
    for (size_t i = 0; i + 1 < vec.size(); i++)
    {
        if (vec[i] > vec[i + 1])
            return false;
    }
    return true;
}

bool PmergeMe::isAcendingOrder(std::deque<int> &deq)
{
    for (size_t i = 0; i + 1 < deq.size(); i++)
    {
        if (deq[i] > deq[i + 1])
            return false;
    }
    return true;
}

bool PmergeMe::isDuplicated(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());
    for (size_t i = 0; i + 1 < vec.size(); i++)
    {
        if (vec[i] == vec[i + 1])
            return true;
    }
    return false;
}

void PmergeMe::divide(std::vector<int> &vec, std::vector<int> &main_chain, std::vector<int> &sub_chain)
{
    size_t half = vec.size() / 2;
    int larger;
    int smaller;

    if (vec.size() == 0)
        throw PmergeMeException("Trying to divide Empty vector");
    for (size_t i = 0; i < half; i++)
    {
        larger = std::max(vec[i], vec[i + half]);
        smaller = std::min(vec[i], vec[i + half]);
        main_chain.push_back(larger);
        sub_chain.push_back(smaller);
    }
    if (vec.size() % 2 != 0)
        sub_chain.push_back(vec[vec.size() - 1]);
}

void PmergeMe::divide(std::deque<int> &deq, std::deque<int> &main_chain, std::deque<int> &sub_chain)
{
    size_t half = deq.size() / 2;
    int larger;
    int smaller;

    if (deq.size() == 0)
        throw PmergeMeException("Trying to divide Empty deque");
    for (size_t i = 0; i < half; i++)
    {
        larger = std::max(deq[i], deq[i + half]);
        smaller = std::min(deq[i], deq[i + half]);
        main_chain.push_back(larger);
        sub_chain.push_back(smaller);
    }
    if (deq.size() % 2 != 0)
        sub_chain.push_back(deq[deq.size() - 1]);
}

std::vector<int> PmergeMe::allignSubChain(std::vector<int> &sorted, std::vector<int> &orig,
                                          std::vector<int> &old_sub_chain)
{
    std::vector<int> alligned_sub_chain;

    if (sorted.size() != orig.size())
        throw PmergeMeException("sorted and orig have different sizes");

    for (size_t i = 0; i < sorted.size(); i++)
    {
        std::vector<int>::iterator it = std::find(orig.begin(), orig.end(), sorted[i]);
        alligned_sub_chain.push_back(old_sub_chain[std::distance(orig.begin(), it)]);
    }

    if (old_sub_chain.size() > sorted.size())
        alligned_sub_chain.push_back(old_sub_chain[old_sub_chain.size() - 1]);

    return alligned_sub_chain;
}

std::deque<int> PmergeMe::allignSubChain(std::deque<int> &sorted, std::deque<int> &orig, std::deque<int> &old_sub_chain)
{
    std::deque<int> alligned_sub_chain;

    if (sorted.size() != orig.size())
        throw PmergeMeException("sorted and orig have different sizes");

    for (size_t i = 0; i < sorted.size(); i++)
    {
        std::deque<int>::iterator it = std::find(orig.begin(), orig.end(), sorted[i]);
        alligned_sub_chain.push_back(old_sub_chain[std::distance(orig.begin(), it)]);
    }

    if (old_sub_chain.size() > sorted.size())
        alligned_sub_chain.push_back(old_sub_chain.back());

    return alligned_sub_chain;
}

void PmergeMe::binaryInsertionElem(std::vector<int> &main_chain, int elem)
{
    size_t left = 0;
    size_t right = main_chain.size();
    size_t mid = 0;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (main_chain[mid] < elem)
            left = mid + 1;
        else
            right = mid;
    }
    main_chain.insert(main_chain.begin() + left, elem);
}

void PmergeMe::binaryInsertionElem(std::deque<int> &main_chain, int elem)
{
    size_t left = 0;
    size_t right = main_chain.size();
    size_t mid = 0;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (main_chain[mid] < elem)
            left = mid + 1;
        else
            right = mid;
    }
    main_chain.insert(main_chain.begin() + left, elem);
}

std::vector<int> PmergeMe::binaryInsertion(std::vector<int> &main_chain, std::vector<int> &sub_chain)
{
    size_t t_pp = 1;
    size_t t_p = 1;
    size_t t = 0;

    // jacobsthal number: 1 1 3 5 11 ...
    while (t < sub_chain.size())
    {
        t = t_p + 2 * t_pp;

        for (size_t j = std::min(t, sub_chain.size()); j > t_p; j--)
            binaryInsertionElem(main_chain, sub_chain[j - 1]);
        if (t_p == 1)
            binaryInsertionElem(main_chain, sub_chain[0]);
        t_pp = t_p;
        t_p = t;
    }
    return main_chain;
}

std::deque<int> PmergeMe::binaryInsertion(std::deque<int> &main_chain, std::deque<int> &sub_chain)
{
    size_t t_pp = 1;
    size_t t_p = 1;
    size_t t = 0;

    // jacobsthal number: 1 1 3 5 11 ...
    while (t < sub_chain.size())
    {
        t = t_p + 2 * t_pp;

        for (size_t j = std::min(t, sub_chain.size()); j > t_p; j--)
            binaryInsertionElem(main_chain, sub_chain[j - 1]);
        if (t_p == 1)
            binaryInsertionElem(main_chain, sub_chain[0]);
        t_pp = t_p;
        t_p = t;
    }
    return main_chain;
}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> vec)
{
    // 3개인 경우만 여기 걸리는 듯
    if (vec.size() == 1)
        return vec;
    if (vec.size() == 2)
    {
        if (vec[0] > vec[1])
            std::swap(vec[0], vec[1]);
        return vec;
    }
    std::vector<int> main_chain, sub_chain;
    divide(vec, main_chain, sub_chain);
    std::vector<int> sorted_main_chain = mergeInsertion(main_chain);
    sub_chain = allignSubChain(sorted_main_chain, main_chain, sub_chain);
    return binaryInsertion(sorted_main_chain, sub_chain);
}

std::deque<int> PmergeMe::mergeInsertion(std::deque<int> deq)
{
    if (deq.size() == 1)
        return deq;
    if (deq.size() == 2)
    {
        if (deq[0] > deq[1])
            std::swap(deq[0], deq[1]);
        return deq;
    }
    std::deque<int> main_chain, sub_chain;
    divide(deq, main_chain, sub_chain);
    std::deque<int> sorted_main_chain = mergeInsertion(main_chain);
    sub_chain = allignSubChain(sorted_main_chain, main_chain, sub_chain);
    return binaryInsertion(sorted_main_chain, sub_chain);
}

void PmergeMe::runTimer(std::vector<int> &vec)
{
    clock_t start, end;
    double elapsed;

    start = clock();
    vec = mergeInsertion(vec);
    end = clock();
    elapsed = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << elapsed << " us"
              << std::endl;
}

void PmergeMe::runTimer(std::deque<int> &deq)
{
    clock_t start, end;
    double elapsed;

    start = clock();
    deq = mergeInsertion(deq);
    end = clock();
    elapsed = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << elapsed << " us"
              << std::endl;
}

void PmergeMe::sortAndPrint(const char **input)
{
    initInput(input);
    std::cout << "Before: ";
    printContainer(vec);
    std::cout << "After: ";
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    printContainer(sortedVec);

    runTimer(vec);
    runTimer(deq);

    checkSorted();
}

void PmergeMe::sortAndPrint(const std::string &input)
{
    initInput(input);
    std::cout << "Before: ";
    printContainer(vec);
    std::cout << "After: ";
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    printContainer(sortedVec);

    runTimer(vec);
    runTimer(deq);

    checkSorted();
}

void PmergeMe::printContainer(const std::vector<int> &vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int> &deq)
{
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::checkSorted()
{
    if (vec.size() != deq.size())
        throw PmergeMeException("vector and deque have different sizes");
    if (!isAcendingOrder(vec))
        throw PmergeMeException("vector is not sorted");
    if (!isAcendingOrder(deq))
        throw PmergeMeException("deque is not sorted");
}
