#include "Square.h"

// MORIA HAMAMI
// 315464347

// constructor. center point = (0,0), name=sn
Square::Square(double up, double down, double right, double left, const char *sn) : Quad(up, down, right, left, sn)
{
}
// destructor
Square::~Square()
{
}

// shifts the center of the square by x (right and left)
void Square::shiftX(int x)
{
    m_centerPoint = m_centerPoint + Point(x, 0);
}
// shifts the center of the square by y (up and down)
void Square::shiftY(int y)
{
    m_centerPoint = m_centerPoint + Point(0, y);
}
