#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "========= basic tests =========" << std::endl;
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        std::cout << std::endl;
        delete meta;
        delete j;
        delete i;
    }

    std::cout << std::endl;
    std::cout << "========= basic tests2 =========" << std::endl;
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();

        std::cout << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();

        std::cout << std::endl;
        delete meta;
        delete i;
    }

    std::cout << std::endl;
    std::cout << "========= trivial tests =========" << std::endl;
    {
        Cat obj1;
        std::cout << std::endl;
        Cat obj2 = obj1;
        std::cout << std::endl;
        Cat obj3(obj1);
        std::cout << std::endl;
        Cat obj4;
        std::cout << std::endl;
        Cat obj5("obj5");

        std::cout << std::endl;
        obj4 = obj1;

        std::cout << std::endl;
        obj1.makeSound();
        obj2.makeSound();
        obj3.makeSound();
        obj4.makeSound();
        obj5.makeSound();

        std::cout << std::endl;
    }
    return 0;
}
