#pragma once
#include "Point2D.h"

class Point3D : public Point2D{
private:
	double z;
public:
	Point3D();
	Point3D(double xPar, double yPar, double zPar);

	void setZ(double zPar);
	double getZ() const;

	double getDistanceTo(const Point3D & obj) const;

	void print() const;

};