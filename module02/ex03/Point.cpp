#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
}

Point &Point::operator=(const Point &point)
{
    x = point.x;
    y = point.y;
    return (*this);
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
    return (x);
}

const Fixed &Point::getY() const
{
    return (y);
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << "Point(" << point.getX() << ", " << point.getY() << ")";
    return os;
}
