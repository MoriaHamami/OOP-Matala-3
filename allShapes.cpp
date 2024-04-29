#include "allShapes.h"

// Shape** m_arr;
// int		m_size;

// constructor, zero elements
allShapes::allShapes()
{

} 
// copy c'tor - deep copy
allShapes::allShapes(const allShapes &other)
{

} 
// destructor to all elements
allShapes::~allShapes()
{

} 

// returns the number of shapes{
int allShapes::getSize() const
{

} 

// add a new shape (deep copy) to the end of array
void allShapes::addShape(Shape *newShape)
{

} 
// remove shape by index
void allShapes::removeShape(int index)
{

} 
// returns the total area of all the shapes (rounded to int)
int allShapes::totalArea() const
{

} 
// returns the total Perimeter of all the shapes (rounded to int)
int allShapes::totalPerimeter() const
{

} 
// returns the total sum of circle areas (rounded to int)
int allShapes::totalCircleArea() const
{

} 
// returns the total sum of squar Perimeter (rounded to int)
int allShapes::totalSquarePerimeter() const
{

} 

// adds a new shape
const allShapes& allShapes::operator+=(Shape *newS)
{

} 
// returns the shape located at index ind
Shape* allShapes::operator[](int ind) const
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
