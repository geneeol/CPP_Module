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

    void runTimer(std::vector<int> &vec);
    void runTimer(std::deque<int> &deq);

    void divide(std::vector<int> &vec, std::vector<int> &main_chain, std::vector<int> &sub_chain);
    void divide(std::deque<int> &deq, std::deque<int> &main_chain, std::deque<int> &sub_chain);

    std::vector<int> allignSubChain(std::vector<int> &sorted, std::vector<int> &orign, std::vector<int> &old_sub_chain);
    std::deque<int> allignSubChain(std::deque<int> &sorted, std::deque<int> &orign, std::deque<int> &old_sub_chain);

    std::vector<int> binaryInsertion(std::vector<int> &main_chain, std::vector<int> &sub_chain);
    std::deque<int> binaryInsertion(std::deque<int> &main_chain, std::deque<int> &sub_chain);

    void binaryInsertionElem(std::vector<int> &main_chain, int elem);
    void binaryInsertionElem(std::deque<int> &main_chain, int elem);

    std::vector<int> mergeInsertion(std::vector<int> vec);
    std::deque<int> mergeInsertion(std::deque<int> deq);

    void printContainer(const std::vector<int> &vec);
    void printContainer(const std::deque<int> &deq);
    void checkSorted();

    bool isAcendingOrder(std::vector<int> &vec);
    bool isAcendingOrder(std::deque<int> &deq);

    bool isDuplicated(std::vector<int> vec);
};