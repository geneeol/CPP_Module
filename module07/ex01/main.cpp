#include "iter.hpp"

void multiply2(int &elem)
{
    elem *= 2;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    for (size_t i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    iter(arr, 5, multiply2);
    for (size_t i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    // iter(arr, 5, printData);
    return (0);
}