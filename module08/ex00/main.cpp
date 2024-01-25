#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
    std::list<int> lst;
    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        lst.push_back(i);
        vec.push_back(i);
    }

    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "easyfind(lst, 5): " << iter_to_str(easyfind(lst, 5), lst) << std::endl;
    std::cout << "easyfind(vec, 5): " << iter_to_str(easyfind(vec, 5), vec) << std::endl;
    std::cout << "easyfind(lst, 42): " << iter_to_str(easyfind(lst, 42), lst) << std::endl;
    std::cout << "easyfind(vec, 42): " << iter_to_str(easyfind(vec, 42), vec) << std::endl;
    return 0;
}