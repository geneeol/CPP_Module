#include <fstream>
#include <iostream>

template <typename T> void ftOpenFile(T &file, std::string fileName)
{
    file.open(fileName);
    if (file.fail())
    {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
}

int main(void)
{
    std::string fileName, newFileName, s1, s2;
    std::ifstream origFile;
    std::ofstream newFile;

    std::cout << "Enter filename: ";
    std::cin >> fileName;
    std::cout << "Enter s1: ";
    std::cin >> s1;
    std::cout << "Enter s2: ";
    std::cin >> s2;

    origFile = ftOpenFile(fileName);
    newFile = ftOpenFile(fileName + ".replace");
}
