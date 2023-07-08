#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <sstream>

std::string intToStr(int num)
{
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

Animal *allocThinkingAnimal(int i)
{
    Animal *animal;
    std::string msg;

    animal = i % 2 == 0 ? static_cast<Animal *>(new Dog("cute dog"))
                        : static_cast<Animal *>(new Cat("cute cat"));
    msg = i % 2 == 0 ? "th idea a dog is cuter than a cat"
                     : "th idea a cat is cuter than a dog";
    for (int j = 0; j <= i; j++)
        animal->addIdea(intToStr(j) + msg);
    return (animal);
}

// 릭검사 valgrind --leak-check=yes ./ex01
int main()
{
    std::cout << "======= basic test1 ======" << std::endl;
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << std::endl;
        delete j; // should not create a leak
        delete i;
    }

    std::cout << std::endl;
    std::cout << "======= basic test2 ======" << std::endl;
    {
        Animal *animals[10];
        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog("dog1");
            else
                animals[i] = new Cat("cat1");
            std::cout << animals[i]->getType() << "\n\n";
        }
        for (int i = 0; i < 10; i++)
        {
            delete animals[i];
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "======= brain test ======" << std::endl;
    {
        Animal *animals[10];

        for (int i = 0; i < 10; i++)
        {
            animals[i] = allocThinkingAnimal(i);
            std::cout << animals[i]->getType() << "\n\n";
        }
        std::cout << "\n\n";
        for (int i = 0; i < 10; i++)
        {
            animals[i]->think();
            delete animals[i];
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "======= deep copy test ======" << std::endl;
    {
        Cat *cat1 = new Cat("cat1");
        std::cout << std::endl;
        Cat cat2 = *cat1;
        std::cout << std::endl;
        Cat cat3(cat2);

        std::cout << std::endl;
        delete cat1;

        cat2.addIdea("cat2 it's my own brain");
        cat3.addIdea("cat3 it's my own brain");

        std::cout << std::endl;
        std::cout << "cat2 think: ";
        cat2.think();

        std::cout << std::endl;
        std::cout << "cat3 think: ";
        cat3.think();

        std::cout << std::endl;
    }
    return 0;
}
