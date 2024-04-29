#include "Point.h"

// int m_x;
// 	int m_y;

Point::Point(int x = 0, int y = 0)
{
    setX(x);
    setY(y);
}

Point::Point(const Point &other)
{
    setX(other.getX());
    setY(other.getY());
}

Point::~Point()
{
}

// returns the x
int Point::getX() const
{
    return m_x;
}
// returns the y
int Point::getY() const
{
    return m_y;
}
// sets the x
void Point::setX(int x)
{
    m_x = x;
}
// sets the y
void Point::setY(int y)
{
    m_y = y;
}
// sets the x and y
void Point::setPoint(int x, int y)
{
    m_x = x;
    m_y = y;
}
// sets the point with other values
void Point::setPoint(const Point &other)
{
    m_x = other.getX();
    m_y = other.getY();
}

// returns true if and only if the two points are equal
bool Point::operator==(const Point &other) const
{
    return m_x == other.m_x && m_y == other.m_y;
}
// returns true if and only if the two points are not equal
bool Point::operator!=(const Point &other) const
{
    return !(*this == other);
}
// returns a new point with updated x(x+num) and y(y+num)
Point Point::operator+(int num) const
{
    Point *newPoint = new Point(*this);
    Point resultPoint(*this);
    newPoint->setX(newPoint->getX() + num);
    newPoint->setY(newPoint->getY() + num);
    return *newPoint;
}
// updates the point with x(x+num) and y(y+num) and returns the updated point
const Point &Point::operator+=(int num)
{
    setX(getX() + num);
    setY(getY() + num);
    return *this;
}
// returns the sum of x and y
Point::operator int() const
{
    return getX() + getY();
}
// adds coordinates (x,y) and returns a new point
Point Point::operator+(const Point &other) const
{
    Point *newPoint = new Point(*this);
    // Point *newPoint = new Point(other);
    // Point resultPoint(*this);
    newPoint->setX(other.getX() + getX());
    newPoint->setY(other.getY() + getY());
    return *newPoint;
}
// adds 1 to x and y and returns the updated point - postfix
Point Point::operator++(int)
{
    Point *newPoint = new Point(*this);
    //    Point resultPoint(*this);
    setX(getX() + 1);
    setY(getY() + 1);
    return *newPoint;
}
// adds 1 to x and y and returns the updated point - prefix
const Point &Point::operator++()
{
    setX(getX() + 1);
    setY(getY() + 1);
    return *this;
}
// returns a new point with (x,y)*num
Point operator*(int num, const Point &other)
{
     Point *newPoint = new Point(other);
    // Point *newPoint = new Point(other);
    // Point resultPoint(*this);
    newPoint->setX(other.getX() * num);
    newPoint->setY(other.getY() * num);
    return *newPoint;
}
