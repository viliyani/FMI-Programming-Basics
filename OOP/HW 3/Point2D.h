#pragma once

class Point2D {
private:
	double x;
	double y;
public:
	Point2D();
	Point2D(double xPar, double yPar);

	void setX(double xPar);
	void setY(double yPar);

	double getX() const;
	double getY() const;

	double getDistanceTo(const Point2D & obj) const;
	
	void print() const;
};