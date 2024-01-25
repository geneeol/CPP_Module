#pragma once

#include <exception>

template <typename T>
class Array
{
  private:
    T *arr;
    unsigned int arr_size;

  public:
    Array() : arr(new T[0]), arr_size(0) {}

    Array(unsigned int n) : arr(new T[n]), arr_size(n) {}

    Array(const Array &other) : arr(new T[0]) { *this = other; }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] arr;
            arr = new T[other.arr_size];
            for (unsigned int i = 0; i < other.arr_size; i++)
                arr[i] = other.arr[i];
            arr_size = other.arr_size;
        }
        return (*this);
    }

    ~Array() { delete[] arr; }

    T &operator[](unsigned int i)
    {
        if (i >= arr_size)
            throw std::exception();
        return (arr[i]);
    }

    T const &operator[](unsigned int i) const
    {
        if (i >= arr_size)
            throw std::exception();
        return (arr[i]);
    }

    unsigned int size(void) const { return (arr_size); }
};