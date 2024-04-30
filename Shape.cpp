#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Quad.h"

// MORIA HAMAMI
// 315464347

// char*		m_shapeName;
// 	static int	s_totalNumOfShapes;
// protected: Point		m_centerPoint;

int Shape::s_totalNumOfShapes=0;

// Creates a new shape (name=sn,centerPoint = (0,0))
Shape::Shape(const char *sn)
{
    m_shapeName = new char[strlen(sn) + 1];
    strcpy(m_shapeName, sn);
    m_centerPoint = Point(0, 0);
    // if(s_totalNumOfShapes) s_totalNumOfShapes=1;
    // else 
    s_totalNumOfShapes++;
}
// copy constructor of shape
Shape::Shape(const Shape &other)
{
    m_shapeName = new char[strlen(other.m_shapeName) + 1];
    strcpy(m_shapeName, other.getName());
    m_centerPoint = Point(other.m_centerPoint);
    //  if(!s_totalNumOfShapes) s_totalNumOfShapes=1;
    // else 
    s_totalNumOfShapes++;
}
// shape destructor
Shape::~Shape()
{
    if (m_shapeName != nullptr)
    {
        delete[] m_shapeName;
    }
    // s_totalNumOfShapes--;
}

// sets the shape's name
void Shape::setName(const char *name)
{
    if (name == nullptr)
        return;
    delete[] m_shapeName;
    m_shapeName = new char[strlen(name) + 1];
    strcpy(m_shapeName, name);
}
// sets the center point
void Shape::setCenter(const Point &p)
{
    m_centerPoint = p;
}
// returns the shape's name
const char *Shape::getName() const
{
    return m_shapeName;
}
// returns the center point
Point Shape::getCenter() const
{
    return m_centerPoint;
}
// set the shape's name and the center point
void Shape::setShape(const char *sn, const Point &other)
{
    setName(sn);
    setCenter(other);
}
// returnS the total number of shapes
int Shape::numOfShapes()
{
    if(!s_totalNumOfShapes) s_totalNumOfShapes = 0;
    return s_totalNumOfShapes;
}

// operator=
const Shape &Shape::operator=(const Shape &other)
{
    if (this != &other)
    {
        delete[] m_shapeName;
        m_shapeName = new char[strlen(other.m_shapeName) + 1];
        strcpy(m_shapeName, other.m_shapeName);
        m_centerPoint = other.m_centerPoint;
    }
    return *this;
}

// returns the shape's area (rounded to int)
int Shape::calcArea() const
{
    int area = 0;
    const Circle *circ = dynamic_cast<const Circle *>(this);
    const Square *squ = dynamic_cast<const Square *>(this);
    const Quad *qua = dynamic_cast<const Quad *>(this);
    if (circ)
    {
        area = circ->calcArea();
    }
    else if (squ)
    {
        area = squ->calcArea();
    }
    else if (qua)
    {
        area = qua->calcArea();
    }
    return area;
}

int Shape::calcPerimeter() const
{
    int perim = 0;
    const Circle *circ = dynamic_cast<const Circle *>(this);
    const Square *squ = dynamic_cast<const Square *>(this);
    const Quad *qua = dynamic_cast<const Quad *>(this);
    if (circ)
    {
        perim = circ->calcPerimeter();
    }
    else if (squ)
    {
        perim = squ->calcPerimeter();
    }
    else if (qua)
    {
        perim = qua->calcPerimeter();
    }
    return perim;
}