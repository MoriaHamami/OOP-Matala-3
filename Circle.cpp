#include "Circle.h"

// MORIA HAMAMI
// 315464347

// double m_radius;

// create a circle with radius=1, name=sn and center=(0,0)
Circle::Circle(double r, const char *sn ) : Shape(sn)
{
    setRadius(r);
}
// copy constructor
Circle::Circle(const Circle &other) : Shape(other)
{
    setRadius(other.getRadius());
}
// destructor
Circle::~Circle()
{
    // The name will get deleted by Shape class
}

// returns the circle's radius
double Circle::getRadius() const
{
    return m_radius;
}
// set the radius
void Circle::setRadius(double r)
{
    m_radius = r;
}

// returns the circle's area (rounded to int)
int Circle::calcArea() const
{
    return (int)(PI * (m_radius * m_radius));
}
// returns the circle's Perimeter (rounded to int)
int Circle::calcPerimeter() const
{
    return (int)(2 * PI * m_radius);
}

// returns a new Circle with added radius
Circle operator+(int r, const Circle &other)
{
    Circle *newCircle = new Circle(other);
    newCircle->setRadius(other.getRadius() + r);
    newCircle->setName(other.getName());
    newCircle->setCenter(other.getCenter());
    return *newCircle;
}
// operator= that copies all
const Circle &Circle::operator=(const Circle &other)
{
    Shape::operator=(other);
    setRadius(other.m_radius);
    return *this;
}

const Circle &Circle::operator=(const char *name)
{
    setName(name);
    return *this;
}