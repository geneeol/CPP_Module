#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base *generate(void)
{
    int i = rand() % 3;
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}

static void identify(Base *p)
{
    try
    {
        if (dynamic_cast<A *>(p))
            std::cout << "pointer is A" << std::endl;
        else if (dynamic_cast<B *>(p))
            std::cout << "pointer is B" << std::endl;
        else if (dynamic_cast<C *>(p))
            std::cout << "pointer is C" << std::endl;
        else
            throw std::exception();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: dynamic_cast with pointer failed" << std::endl;
    }
}

static void identify(Base &p)
{
    try
    {
        if (dynamic_cast<A *>(&p))
            std::cout << "reference is A" << std::endl;
        else if (dynamic_cast<B *>(&p))
            std::cout << "reference is B" << std::endl;
        else if (dynamic_cast<C *>(&p))
            std::cout << "reference is C" << std::endl;
        else
            std::cout << "reference is unknown" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: dynamic_cast with reference failed" << std::endl;
    }
}

int main(void)
{
    srand(time(NULL));

    Base *base = generate();

    identify(base);
    identify(*base);
    identify(NULL);

    delete base;
    return 0;
}