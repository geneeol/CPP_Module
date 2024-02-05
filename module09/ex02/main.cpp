#include "PmergeMe.hpp"
#include "PmergeMeException.hpp"
#include <iostream>

int main(int argc, const char **argv)
{
    PmergeMe pmergeMe;

    (void)argc;
    (void)argv;
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