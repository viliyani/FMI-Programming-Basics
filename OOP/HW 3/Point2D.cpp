#include "Point2D.h"
#include <iostream>
#include <cmath>
using namespace std;

Point2D::Point2D() : x(0), y(0)
{
}

Point2D::Point2D(double xPar, double yPar) : x(xPar), y(yPar)
{
}

void Point2D::setX(double xPar)
{
	x = xPar;
}

void Point2D::setY(double yPar)
{
	y = yPar;
}

double Point2D::getX() const
{
	return x;
}

double Point2D::getY() const
{
	return y;
}

double Point2D::getDistanceTo(const Point2D & obj) const
{
	return sqrt(((obj.x - x)*(obj.x - x))+((obj.y - y)*(obj.y - y)));
}

void Point2D::print() const
{
	cout << endl;
	cout << "___ Point2D ___" << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << endl;
}
