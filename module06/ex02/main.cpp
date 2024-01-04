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
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "reference is A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "reference is B" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "reference is C" << std::endl;
        return;
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
    Base b1;
    Base &b2 = b1;

    identify(base);
    identify(*base);
    identify(NULL);
    identify(b2);

    delete base;
    return 0;
}