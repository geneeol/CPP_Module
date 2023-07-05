#pragma once

#include "Fixed.hpp"

class Point
{
  private:
    Fixed x;
    Fixed y;

  public:
    Point();
    Point(const float x, const float y);
    Point(const Point &point);
    Point &operator=(const Point &point);
    ~Point();

    const Fixed &getX() const;
    const Fixed &getY() const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);