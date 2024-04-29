#include "Shape.h"

// char*		m_shapeName;
// 	static int	s_totalNumOfShapes;
// protected: Point		m_centerPoint;

// Creates a new shape (name=sn,centerPoint = (0,0))
Shape::Shape(const char *sn = "noName")
{
    m_shapeName = new char[strlen(sn)];
    strcpy(m_shapeName, sn);
    m_centerPoint = (0,0);
    s_totalNumOfShapes++;
}
// copy constructor of shape
Shape::Shape(const Shape &other)
{
}
// shape destructor
Shape::~Shape()
{
}

// sets the shape's name
void Shape::setName(const char *name)
{
}
// sets the center point
void Shape::setCenter(const Point &p)
{
}
// returns the shape's name
const char *Shape::getName() const
{
    return m_shapeName;
}
// returns the center point
Point Shape::getCenter() const
{
}
// set the shape's name and the center point
void Shape::setShape(const char *sn, const Point &other)
{
}
// returnS the total number of shapes
int Shape::numOfShapes()
{
    return s_totalNumOfShapes;
}

// operator=
const Shape &Shape::operator=(const Shape &other)
{
}

// returns the shape's area (rounded to int)
int Shape::calcArea() const
{
}

int Shape::calcPerimeter() const
{
}