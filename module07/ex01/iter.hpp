#pragma once

#include <iostream>

template<typename T1, typename T2>
void iter(T1 *arr, size_t len, T2 f)
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

// template <typename T>
// void iter(T *arr, int len, void (*f)(T &elem))
// {
//     for (int i = 0; i < len; i++)
//         f(arr[i]);
// }

// template <typename T>
// void iter(T *arr, int len, void (*f)(const T &elem))
// {
//     for (int i = 0; i < len; i++)
//         f(arr[i]);
// }

// typedef void (*func)(int &elem);

template <typename T>
void iter(T *arr, int len, void (*f)(T elem))
{
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void printData(const T &elem)
{
    std::cout << elem << std::endl;
}

// class Awesome
// {
//   public:
//     Awesome(void);
//     template <typename T>
//     void printData(const T elem) const
//     {
//         std::cout << elem << std::endl;
//     }
// };
