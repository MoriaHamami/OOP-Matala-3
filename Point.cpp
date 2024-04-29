#include "Point.h"

// int m_x;
// 	int m_y;

Point::Point(int x = 0, int y = 0)
{
}

Point::Point(const Point &other)
{
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
}
// sets the point with other values
void Point::setPoint(const Point &other)
{
}

// returns true if and only if the two points are equal
bool Point::operator==(const Point &other) const
{
}
// returns true if and only if the two points are not equal
bool Point::operator!=(const Point &other) const
{
}
// returns a new point with updated x(x+num) and y(y+num)
Point Point::operator+(int num) const
{
}
// updates the point with x(x+num) and y(y+num) and returns the updated point
const Point &Point::operator+=(int num)
{
}
// returns the sum of x and y
Point::operator int() const
{
}
// adds coordinates (x,y) and returns a new point
Point Point::operator+(const Point &other) const
{
}
// adds 1 to x and y and returns the updated point - postfix
Point Point::operator++(int)
{
}
// adds 1 to x and y and returns the updated point - prefix
const Point &Point::operator++()
{
}
// returns a new point with (x,y)*num
Point operator*(int num, const Point &other)
{
}
