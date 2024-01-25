#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : N(N) {}
Span::Span(const Span &other) : N(other.N), vec(other.vec) {}
Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        vec = other.vec;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n)
{
    if (vec.size() > N)
        throw std::exception();
    vec.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw std::exception();
    std::vector<int> tmp(vec);
    std::sort(tmp.begin(), tmp.end());
    unsigned int min = std::numeric_limits<unsigned int>::max();
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        unsigned int diff = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if (vec.size() < 2)
        throw std::exception();
    std::vector<int> tmp(vec);
    std::sort(tmp.begin(), tmp.end());
    return static_cast<unsigned int>(tmp.back() - tmp.front());
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (vec.size() + std::distance(begin, end) > N)
        throw std::exception();
    vec.insert(vec.end(), begin, end);
}