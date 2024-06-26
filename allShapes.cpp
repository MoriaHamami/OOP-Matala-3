#include "allShapes.h"
#include "Circle.h"
#include "Square.h"
#include "Quad.h"
#include "Shape.h"

// MORIA HAMAMI
// 315464347

// Shape** m_arr;
// int		m_size;

// constructor, zero elements
allShapes::allShapes()
{
    m_size = 0;
    m_arr = new Shape *[m_size];
}
// copy c'tor - deep copy
allShapes::allShapes(const allShapes &other)
{
    m_size = other.getSize();
    m_arr = new Shape *[m_size];
    for (int i = 0; i < m_size; i++)
    {
        if (typeid(other.m_arr[i]) == typeid(Circle))
        {
            m_arr[i] = new Circle(*((Circle *)other.m_arr[i]));
        }
        else if (typeid(other.m_arr[i]) == typeid(Square))
        {

            m_arr[i] = new Square(*((Square *)other.m_arr[i]));
        }
        else if (typeid(other.m_arr[i]) == typeid(Quad))
        {

            m_arr[i] = new Quad(*((Quad *)other.m_arr[i]));
        }
    }
}
// destructor to all elements
allShapes::~allShapes()
{
    for (int i = 0; i < m_size; i++)
        delete m_arr[i];
    delete[] m_arr;
}

// returns the number of shapes{
int allShapes::getSize() const
{
    return m_size;
}

// add a new shape (deep copy) to the end of array
void allShapes::addShape(Shape *newShape)
{
    Circle *c = dynamic_cast<Circle *>(newShape);
    if (c)
    {
        *this += new Circle(*c);
        return;
    }
    Square *s = dynamic_cast<Square *>(newShape);
    if (s)
    {
        *this += new Square(*s);
        return;
    }
    else
    {
        Quad *q = dynamic_cast<Quad *>(newShape);
        if (q)
        {
            *this += new Quad(*q);
        }
    }
}
// remove shape by index
void allShapes::removeShape(int index)
{

    if (index >= m_size || index < 0)
        return;
    // Delete account
    Shape **temp = new Shape *[m_size - 1];
    int j = 0;
    for (int i = 0; i < m_size; i++)
    {
        if (i == index)
            continue;

        Circle *c = dynamic_cast<Circle *>(m_arr[i]);
        if (c)
        {
            temp[j++] = new Circle(*((Circle *)m_arr[i]));

            continue;
        }
        Square *s = dynamic_cast<Square *>(m_arr[i]);
        if (s)
        {
            temp[j++] = new Square(*((Square *)m_arr[i]));

            continue;
        }
        Quad *q = dynamic_cast<Quad *>(m_arr[i]);
        if (q)
        {
            temp[j++] = new Quad(*((Quad *)m_arr[i]));
        }
    }
    delete[] m_arr;

    m_arr = new Shape *[m_size - 1];
    for (int i = 0; i < m_size - 1; i++)
    {
        Circle *c1 = dynamic_cast<Circle *>(temp[i]);
        if (c1)
        {
            m_arr[i] = new Circle(*((Circle *)temp[i]));

            continue;
        }
        Square *s1 = dynamic_cast<Square *>(temp[i]);
        if (s1)
        {
            m_arr[i] = new Square(*((Square *)temp[i]));

            continue;
        }
        Quad *q1 = dynamic_cast<Quad *>(temp[i]);
        if (q1)
        {
            m_arr[i] = new Quad(*((Quad *)temp[i]));
        }
    }
    --m_size;
    temp = nullptr;
}
// returns the total area of all the shapes (rounded to int)
int allShapes::totalArea() const
{
    int totalArea = 0;
    for (int i = 0; i < m_size; i++)
    {
        totalArea += (int)m_arr[i]->calcArea();
    }
    return totalArea;
}
// returns the total Perimeter of all the shapes (rounded to int)
int allShapes::totalPerimeter() const
{
    int totalPerimeter = 0;
    for (int i = 0; i < m_size; i++)
    {
        totalPerimeter += (int)m_arr[i]->calcPerimeter();
    }
    return totalPerimeter;
}
// returns the total sum of circle areas (rounded to int)
int allShapes::totalCircleArea() const
{
    int totalCircleArea = 0;
    for (int i = 0; i < m_size; i++)
    {
        if (typeid(*m_arr[i]) != typeid(Circle))
            continue;
        totalCircleArea += m_arr[i]->calcArea();
    }
    return totalCircleArea;
}
// returns the total sum of squar Perimeter (rounded to int)
int allShapes::totalSquarePerimeter() const
{
    int totalSquarePerimeter = 0;
    for (int i = 0; i < m_size; i++)
    {
        if (typeid(*m_arr[i]) != typeid(Square))
            continue;
        totalSquarePerimeter += (int)m_arr[i]->calcPerimeter();
    }
    return totalSquarePerimeter;
}

// adds a new shape
const allShapes &allShapes::operator+=(Shape *newS)
{
    ++m_size;
    Shape **temp = new Shape *[m_size];

    for (int i = 0; i < m_size - 1; i++)
    {
        Circle *c = dynamic_cast<Circle *>(m_arr[i]);
        if (c)
        {
            temp[i] = new Circle(*((Circle *)m_arr[i]));

            continue;
        }
        Square *s = dynamic_cast<Square *>(m_arr[i]);
        if (s)
        {
            temp[i] = new Square(*((Square *)m_arr[i]));

            continue;
        }
        Quad *q = dynamic_cast<Quad *>(m_arr[i]);
        if (q)
        {
            temp[i] = new Quad(*((Quad *)m_arr[i]));
        }
    }

    Circle *c = dynamic_cast<Circle *>(newS);
    if (c)
    {
        temp[m_size - 1] = new Circle(*((Circle *)newS));
    }
    Square *s = dynamic_cast<Square *>(newS);
    if (s)
    {
        temp[m_size - 1] = new Square(*((Square *)newS));
    }
    else
    {
        Quad *q = dynamic_cast<Quad *>(newS);
        if (q)
        {
            temp[m_size - 1] = new Quad(*((Quad *)newS));
        }
    }

    m_arr = new Shape *[m_size];
    for (int i = 0; i < m_size; i++)
    {
        Circle *c1 = dynamic_cast<Circle *>(temp[i]);
        if (c1)
        {
            m_arr[i] = new Circle(*((Circle *)temp[i]));

            continue;
        }
        Square *s1 = dynamic_cast<Square *>(temp[i]);
        if (s1)
        {
            m_arr[i] = new Square(*((Square *)temp[i]));

            continue;
        }
        Quad *q1 = dynamic_cast<Quad *>(temp[i]);
        if (q1)
        {
            m_arr[i] = new Quad(*((Quad *)temp[i]));
        }
    }

    return *this;
}
// returns the shape located at index ind
Shape *allShapes::operator[](int ind) const
{
    if (m_arr == nullptr)
        return nullptr;
    return m_arr[ind];
}
// returns a new allShape with all elements located at this and other
allShapes allShapes::operator+(const allShapes &other) const
{
    allShapes resultShape;
    for (int i = 0; i < m_size; i++)
    {
        resultShape.addShape(m_arr[i]);
    }
    for (int i = 0; i < other.m_size; i++)
    {
        resultShape.addShape(other.m_arr[i]);
    }
    return resultShape;
}
// returns the number of elements
allShapes::operator int() const
{
    return m_size;
}
