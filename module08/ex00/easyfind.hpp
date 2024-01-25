#pragma once

#include <algorithm>
#include <sstream>

template <typename T>
std::string iter_to_str(typename T::iterator it, T &container)
{
    std::string str = "Not found";
    std::ostringstream oss;

    if (it != container.end())
    {
        oss << *it;
        str = oss.str();
    }
    return str;
}

template <typename T>
typename T::iterator easyfind(T &container, int target)
{
    return std::find(container.begin(), container.end(), target);
}
