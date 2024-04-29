#include "Quad.h"

// double m_up;
// 	double m_down;
// 	double m_right;
// 	double m_left;

// constructor. center point = (0,0), name=sn
Quad::Quad(double up = 0, double down = 0, double right = 0, double left = 0, const char *sn = "noName") : Shape(sn)
{
    m_up = up;
    m_down = down;
    m_left = left;
    m_right = right;
}
// copy constructr
Quad::Quad(const Quad &other) : Shape(other)
{
    m_up = other.m_up;
    m_down = other.m_down;
    m_left = other.m_left;
    m_right = other.m_right;
}
// destructor
Quad::~Quad()
{
}

// returns the quad's area (right*up) (rounded to int)
int Quad::calcArea() const
{
    return (int)(m_right * m_up);
}
// returns the quad's Perimeter (the sum of the four ribs) (rounded to int)
int Quad::calcPerimeter() const
{
    return (int)(m_right + m_left + m_up + m_down);
}
