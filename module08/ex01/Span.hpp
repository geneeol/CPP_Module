#include <algorithm>
#include <exception>
#include <vector>

class Span
{
  private:
    Span();
    unsigned int N;
    std::vector<int> vec;

  public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};