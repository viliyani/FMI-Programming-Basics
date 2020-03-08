#include "Point3D.h"
#include <iostream>
#include <cmath>
using namespace std;

Point3D::Point3D() : Point2D(), z(0)
{
}

Point3D::Point3D(double xPar, double yPar, double zPar) : Point2D(xPar, yPar), z(zPar)
{
}

void Point3D::setZ(double zPar)
{
	z = zPar;
}

double Point3D::getZ() const
{
	return z;
}

double Point3D::getDistanceTo(const Point3D & obj) const
{
	return sqrt(((obj.getX() - getX())*(obj.getX() - getX())) + ((obj.getY() - getY())*(obj.getY() - getY())) + ((obj.z - z)*(obj.z - z)));
}

void Point3D::print() const
{
	cout << endl;
	cout << "___ Point3D ___" << endl;
	cout << "x: " << getX() << endl;
	cout << "y: " << getY() << endl;
	cout << "z: " << z << endl;
	cout << endl;
}
