#pragma once

#include <ostream>

class Fixed
{
  private:
    int val;
    static const int fracBits = 8;

  public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed();
    Fixed(const int val);
    Fixed(const float val);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);