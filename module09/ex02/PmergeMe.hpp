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
    void sortAndPrint(const std::string &input);
    void sortAndPrint(const char **input);
    void initInput(const char **input);
    void initInput(const std::string &input);
    void printContainer(const std::vector<int> &vec);
    void printContainer(const std::deque<int> &deq);
    void runTimer(std::vector<int> &vec);
    void runTimer(std::deque<int> &deq);
    void divide(std::vector<int> &vec, std::vector<int> &main_chain, std::vector<int> &sub_chain);
    std::vector<int> allignSubChain(std::vector<int> &sorted, std::vector<int> &orign, std::vector<int> &old_sub_chain);
    std::vector<int> binaryInsertion(std::vector<int> &main_chain, std::vector<int> &sub_chain);
    void binaryInsertionElem(std::vector<int> &main_chain, int elem);
    std::vector<int> mergeInsertion(std::vector<int> vec);

    std::vector<int> mergeInsertion(std::deque<int> deq);
    void checkSorted();
    bool isAcendingOrder(std::vector<int> &vec);
    bool isDuplicated(std::vector<int> vec);
};