#include "PmergeMe.hpp"
#include "PmergeMeException.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::initInput(const char **input)
{
    int i = 0;
    int inputVal;
    double val;
    char **endptr;

    // TODO: 인풋개수 0개, 1개, 2개, 3개, 4개 적은 수일 때 테스트
    // TODO: 중복되는 수 관련 처리
    while (input[i])
    {
        val = strtod(input[i], endptr);
        if (endptr[0] != '\0' || val < 0 || val != std::floor(val))
            throw PmergeMeException("Invalid input");
        inputVal = static_cast<int>(val);
        vec.push_back(inputVal);
        deq.push_back(inputVal);
        i++;
    }
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
    int i = 0;
    size_t vecSize = vec.size();

    if (vecSize != deq.size())
        throw PmergeMeException("vector and deque have different sizes");
    std::deque<int>::iterator it = deq.begin();
    for (i = 0; i + 1 < vecSize; i++, it++)
    {
        if (vec[i] > vec[i + 1])
            throw PmergeMeException("vector is not sorted");
        if (*it > *(it + 1))
            throw PmergeMeException("deque is not sorted");
    }
}

std::vector<int> PmergeMe::divide(const std::vector<int> &curr, std::vector<int> &main_chain,
                                  std::vector<int> &sub_chain)
{
    std::vector<int>::const_iterator it = curr.begin();
    size_t halfOfSize = curr.size() / 2;
}

// divide에서 main_chain 리턴 -> 계속 divide 타고 들어가게, divide에 대응되는 subchain은 어떻게 build?
std::vector<int> PmergeMe::mergeInsertion(std::vector<int> vec)
{
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
    std::vector<int> sorted = mergeInsertion(main_chain);
}

void PmergeMe::timer(std::vector<int> &vec)
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

void PmergeMe::sortAndPrint(const char **input)
{
    initInput(input);
    std::cout << "Before: ";
    printContainer(vec);
    std::cout << "After: ";
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    printContainer(sortedVec);

    timer(vec);
    timer(deq);

    checkSorted();
}