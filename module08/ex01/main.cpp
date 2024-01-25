#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void test0()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << ">== test0 <===\n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n\n";
}

void test1()
{
    Span sp = Span(10000);
    std::vector<int> vec(10000);
    // TODO: cpp98 확인

    std::generate(vec.begin(), vec.end(), rand);
    sp.addNumber(vec.begin(), vec.end());

    std::cout << ">== test1 <===\n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n\n";
}

void test2()
{
    Span sp = Span(10000);
    std::vector<int> vec(10000);
    for (size_t i = 0; i < 10000; i++)
        vec[i] = rand() % 10000;
    sp.addNumber(vec.begin(), vec.end());

    std::cout << ">== test2 <===\n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n\n";
}

void test3()
{
    Span sp = Span(10);
    int arr[10] = {100, 90, 80, 70, 60, 50, 40, 30, 5, 10};
    for (size_t i = 0; i < 10; i++)
        sp.addNumber(arr[i]);

    std::cout << ">== test3 <===\n";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n\n";
}

int main(void)
{
    srand(time(NULL));
    test0();
    test1();
    test2();
    test3();
    return 0;
}