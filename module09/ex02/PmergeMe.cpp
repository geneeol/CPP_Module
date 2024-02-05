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

    // TODO: 인풋개수 0개, 1개, 2개, 3개, 4개 적은 수일 때 테스트
    // TODO: 중복되는 수 관련 처리
    while (input[i])
    {
        val = strtod(input[i], &endptr);
        if (endptr[0] != '\0' || val < 0 || val != std::floor(val))
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

void PmergeMe::printContainer(const std::vector<int> &vec)
{
    std::cout << "vec: ";
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
    size_t i = 0;
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

bool PmergeMe::isAcendingOrder(std::vector<int> &vec)
{
    for (size_t i = 0; i + 1 < vec.size(); i++)
    {
        if (vec[i] > vec[i + 1])
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

// 8개 짜리
// half = 4
// 0 1 2 3 4 5 6 7 || 0 4 / 1 5 / 2 6 / 3 7

// 9개 짜리
// half = 4
// 0 1 2 3 4 5 6 7 8  || 0 4 / 1 5 / 2 6 / 3 7 / 8
void PmergeMe::divide(std::vector<int> &vec, std::vector<int> &main_chain, std::vector<int> &sub_chain)
{
    std::vector<int>::iterator it = vec.begin();
    size_t half = vec.size() / 2;

    for (size_t i = 0; i < half; i++, it++)
    {
        // std::cout << "i: " << i << " it: " << *it << " it+half: " << *(it + half) << std::endl;
        if (*it < *(it + half))
            std::swap(*it, *(it + half));
    }
    if (vec.size() == 0)
        throw PmergeMeException("Trying to divide Empty vector");
    main_chain.assign(vec.begin(), vec.begin() + half);
    sub_chain.assign(vec.begin() + half, vec.end());
    // std::cout << "main_chain: ";
    // printContainer(main_chain);
    // std::cout << "sub_chain: ";
    // printContainer(sub_chain);
    // main_chain = std::vector<int>(vec.begin(), vec.begin() + half);
    // sub_chain = std::vector<int>(vec.begin() + half, vec.end());
}

// main: 10 15 20 24 / sub: 5 8 14 19 / prev_sub: ?
// main: 20 24 / sub 10 15 / prev_sub: 5 8 14 19 -> prev_sub': 14 19 5 8
/// main: return 20 24 (초기조건)

// insertion
// main 20 24 / sub 10 15 / prev_sub 14 19 5 8 <- sub_chain내에 빈번한 swap이 발생할 수 밖에 없음

// 23 10 16 31 | 11 8 14 25
// orig: 23 10 16 31
// sorted: 10 16 23 31
// target: 11 8 14 25
// alligned: 8 14 11 25

// orig - target 짝이 맞음, sorted - alligned 짝을 맞출 예정
// TODO: 중복값 허용하면 find에서 문제가 생길수도
std::vector<int> PmergeMe::allignSubChain(std::vector<int> &sorted, std::vector<int> &orig,
                                          std::vector<int> &old_sub_chain)
{
    std::vector<int> alligned_sub_chain;

    if (sorted.size() != orig.size())
        throw PmergeMeException("sorted and orig have different sizes");
    for (size_t i = 0; i < sorted.size(); i++)
    {
        // orig에서 sorted[i]의 위치 찾기
        // 위에서 찾은 위치에 해당하는 target의 값을 alligned_sub_chain에 넣기
        // 만약 중복값이 있으면? 여기서 에러 발생 가능성 농후
        std::vector<int>::iterator it = std::find(orig.begin(), orig.end(), sorted[i]);
        alligned_sub_chain.push_back(old_sub_chain[std::distance(orig.begin(), it)]);
    }
    if (old_sub_chain.size() > sorted.size())
    {
        if (old_sub_chain.size() == 0)
            throw PmergeMeException("sub chain can't be empty");
        alligned_sub_chain.push_back(old_sub_chain[old_sub_chain.size() - 1]);
    }
    return alligned_sub_chain;
}

// idx: 0 1  2  3  4  5  6
// num: 1 5 10 15 25 30 35 << 13
// 1. left = 0 right = 7 mid = 3
// 2. left = 0 right = 3 mid = 1
// 3. left = 2 right = 3 mid = 2
void PmergeMe::binaryInsertionElem(std::vector<int> &main_chain, int target)
{
    size_t left = 0;
    size_t right = main_chain.size();
    size_t mid = 0;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (main_chain[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    main_chain.insert(main_chain.begin() + left, target);
}

std::vector<int> PmergeMe::binaryInsertion(std::vector<int> &main_chain, std::vector<int> &sub_chain)
{
    // 0 1 1 3 5 11
    size_t t_pp = 1;
    size_t t_p = 1;
    size_t t = 0;

    while (t < sub_chain.size())
    {
        t = t_p + 2 * t_pp;

        // a1은 누가?
        // 3, 2 삽입
        // 5, 4 삽입
        // 11, 10, 9, 8, 7, 6 삽입
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
    if (!isAcendingOrder(sorted_main_chain))
        throw PmergeMeException("sorted_main_chain is not sorted");
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

void PmergeMe::sortAndPrint(const char **input)
{
    initInput(input);
    std::cout << "Before: ";
    printContainer(vec);
    std::cout << "After: ";
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    printContainer(sortedVec);
    std::cout << "----------------------\n\n";

    runTimer(vec);
    // runTimer(deq);

    if (!isAcendingOrder(vec))
        throw PmergeMeException("vec is not sorted");
    printContainer(vec);
    // checkSorted();
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
    std::cout << "----------------------\n\n";

    runTimer(vec);
    // runTimer(deq);

    if (!isAcendingOrder(vec))
        throw PmergeMeException("vec is not sorted");
    // printContainer(vec);
    // checkSorted();
}