#include "Circle.h"

// double m_radius;

// create a circle with radius=1, name=sn and center=(0,0)
Circle::Circle(double r = 1, const char *sn = "noName")
{
}
// copy constructor
Circle::Circle(const Circle &other)
{
}
// destructor
Circle::~Circle()
{
}

// returns the circle's radius
double Circle::getRadius() const
{
}
// set the radius
void Circle::setRadius(double r)
{
}

// returns the circle's area (rounded to int)
int Circle::calcArea() const
{
}
// returns the circle's Perimeter (rounded to int)
int Circle::calcPerimeter() const
{
}

// returns a new Circle with added radius
Circle operator+(int r, const Circle &other)
{
}
// operator= that copies all
const Circle &Circle::operator=(const Circle &other)
{
}

const Circle &Circle::operator=(const char *name)
{
}