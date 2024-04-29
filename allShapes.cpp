#include "allShapes.h"
#include "Circle.h"
#include "Square.h"
#include "Quad.h"
#include "Shape.h"

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
        // Should I add an asteriks to the the first typeid too?
        // if (typeid(*(other.m_arr[i])) == typeid(Circle))
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
        // else
        // {
        //     m_arr[i] = new Shape(*((Shape*)other.m_arr[i]));
        // }
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
    m_arr += newShape;
}
// remove shape by index
void allShapes::removeShape(int index)
{
    if (index >= m_size || index < 0)
        return;
    if (m_size > 1)
    {
        delete m_arr[index];
        // if (typeid(m_arr[m_size - 1]) == typeid(m_arr[index]))
        // {
        m_arr[index] = m_arr[m_size - 1];
        // }
        // else if (typeid(m_arr[m_size-1]) == typeid(Circle))
        // {
        //     m_arr[index] = new Circle(*((Circle *)m_arr[i]));
        // }
        // else if (typeid(m_arr[m_size-1]) == typeid(Square))
        // {

        //     m_arr[index] = new Square(*((Square *)m_arr[i]));
        // }
        // else if (typeid(m_arr[m_size-1]) == typeid(Quad))
        // {

        //     m_arr[index] = new Quad(*((Quad *)m_arr[i]));
        // }
        delete m_arr[m_size - 1];
    }
    else
    {
        delete m_arr[index];
    }
    --m_size;
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
        if (typeid(*m_arr[i]) == typeid(Circle))
        {
            temp[i] = new Circle(*((Circle *)m_arr[i]));
        }
        else if (typeid(*m_arr[i]) == typeid(Square))
        {

            temp[i] = new Square(*((Square *)m_arr[i]));
        }
        else if (typeid(*m_arr[i]) == typeid(Quad))
        {

            temp[i] = new Quad(*((Quad *)m_arr[i]));
        }
        delete m_arr[i];
    }
    delete[] m_arr;
    // Copy last shape to the last cell
    if (typeid(newS) == typeid(Circle))
    {
        temp[m_size - 1] = new Circle(*((Circle *)newS));
    }
    else if (typeid(newS) == typeid(Square))
    {

        temp[m_size - 1] = new Square(*((Square *)newS));
    }
    else if (typeid(newS) == typeid(Quad))
    {

        temp[m_size - 1] = new Quad(*((Quad *)newS));
    }

    // m_arr = new Shape *[m_size];
    m_arr = temp;

    return *this;
}
// returns the shape located at index ind
Shape *allShapes::operator[](int ind) const
{
}
// returns a new allShape with all elements located at this and other
allShapes allShapes::operator+(const allShapes &other) const
{
}
// returns the number of elements
allShapes::operator int() const
{
}
