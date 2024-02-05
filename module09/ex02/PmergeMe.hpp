#pragma once

#include <deque>
#include <vector>

class PmergeMe
{
  private:
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    std::vector<int> vec;
    std::deque<int> deq;

  public:
    PmergeMe();
    ~PmergeMe();
    void sortAndPrint(const char **input);
    void initInput(const char **input);
    void printContainer(const std::vector<int> &vec);
    void printContainer(const std::deque<int> &deq);
    void timer(std::vector<int> &vec);
    void timer(std::deque<int> &deq);
    // std::vector<int> divide(const std::vector<int> &curr,
    //                         std::vector<int> &main_chain,
    //                         std::vector<int> &sub_chain);
    std::vector<int> mergeInsertion(std::vector<int> vec);
    std::vector<int> mergeInsertion(std::deque<int> deq);
    void checkSorted();
};