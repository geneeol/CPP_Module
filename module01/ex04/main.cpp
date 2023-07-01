#include <fstream>
#include <iostream>
#include <sstream>

std::string replaceAll(std::string content, std::string target,
                       std::string replacement)
{
    std::string newString;
    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    newString.reserve(content.length()); // 재할당 최소화

    while ((findPos = content.find(target, lastPos)) != std::string::npos)
    {
        newString.append(content, lastPos, findPos - lastPos);
        newString += replacement;
        lastPos = findPos + target.length();
    }
    newString += content.substr(lastPos);
    return (newString);
}

// 파일을 읽어서 string으로 한번에 저장하는 방법
// https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
int main(int argc, char **argv)
{
    std::string fileName, s1, s2;
    std::ifstream origFile;
    std::ofstream newFile;
    size_t size;

    if (argc != 4)
    {
        std::cerr << "Usage: Arguments should be 3" << std::endl;
        return (1);
    }
    fileName = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    origFile.open(fileName.c_str());
    if (origFile.fail())
    {
        std::cerr << "Error opening file" << std::endl;
        return (1);
    }
    newFile.open((fileName + ".replace").c_str(),
                 std::ios::out | std::ios::trunc);
    if (newFile.fail())
    {
        std::cerr << "Error opening file" << std::endl;
        return (1);
    }
    origFile.seekg(0, std::ios::end);
    size = origFile.tellg();
    std::string content(size, '\0');
    origFile.seekg(0);
    origFile.read(&content[0], size);
    newFile << replaceAll(content, s1, s2);
    origFile.close();
    newFile.close();
}
