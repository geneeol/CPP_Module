#include "iter.hpp"

static void increment(int &elem)
{
    ++elem;
}

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    float arr3[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

    for (size_t i = 0; i < 5; i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;
    iter(arr1, 5, multiply2<int>);
    for (size_t i = 0; i < 5; i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    iter(arr2, 5, printData<int>);
    std::cout << std::endl;
    for (size_t i = 0; i < 5; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    iter(arr2, 5, increment);
    iter(arr2, 5, printData<int>);
    std::cout << std::endl;
    std::cout << std::endl;

    iter(arr3, 5, printData<float>);
    return (0);
}