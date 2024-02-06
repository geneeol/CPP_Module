#include "PmergeMe.hpp"
#include "PmergeMeException.hpp"
#include <iostream>

int main(int argc, const char **argv)
{
    PmergeMe pmergeMe;

    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " [int] [int] ..." << std::endl;
        return 1;
    }
    try
    {
        pmergeMe.sortAndPrint(argv + 1);
    }
    catch (PmergeMeException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}