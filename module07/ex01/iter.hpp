#pragma once

#include <iostream>

template <typename T1, typename T2>
void iter(T1 *arr, size_t len, T2 f)
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void multiply2(T &elem)
{
    elem *= 2;
}

template <typename T>
static void printData(const T &elem)
{
    std::cout << elem << " ";
}