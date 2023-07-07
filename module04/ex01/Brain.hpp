#pragma once
#include <string>

#define MAX_IDEAS 100

class Brain
{
  private:
    std::string ideas[MAX_IDEAS];
    int size;

  public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    std::string getIdea(int idx) const;
    void addIdea(const std::string &idea);
    int getSize() const;
};