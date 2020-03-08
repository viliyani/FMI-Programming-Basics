#include "Rectangle.h"

Rectangle::Rectangle() : x(0), y(0), width(0), height(0), fill("none")
{
}

Rectangle::Rectangle(int xPar, int yPar, int widthPar, int heightPar, std::string fillPar) : x(xPar), y(yPar), width(widthPar), height(heightPar), fill(fillPar)
{
}

void Rectangle::print() const
{
	std::cout << "rectangle " << x << " " << y << " " << width << " " << height << " " << fill;
}

std::string Rectangle::getType() const 
{
	return "rectangle";
}

void Rectangle::translate(int xPar, int yPar)
{
	x += xPar;
	y += yPar;
}

bool Rectangle::withinRectangle(int xPar, int yPar, int widthPar, int heightPar)
{
	int r1x1 = x;
	int r1y1 = y;
	int r1x2 = x + width;
	int r1y2 = y;
	int r1x3 = r1x2;
	int r1y3 = r1y2 + height;
	int r1x4 = x;
	int r1y4 = y + height;

	int r2x1 = xPar;
	int r2y1 = yPar;
	int r2x2 = xPar + widthPar;
	int r2y2 = yPar;
	int r2x3 = r2x2;
	int r2y3 = r2y2 + heightPar;
	int r2x4 = xPar;
	int r2y4 = yPar + heightPar;

	if ((r1x1 >= r2x1 && r1y1 >= r2y1) && (r1x2 <= r2x2 && r1y2 >= r2y2)
		&& ((r1x3 <= r2x3 && r1y3 <= r2y3)) && (r1x4 >= r2x4 && r1y4 <= r2y4)) {
		return true;
	}

	return false;
}

bool Rectangle::withinCircle(int cxPar, int cyPar, int rPar)
{
	int x1 = x;
	int y1 = y;
	int x2 = x + width;
	int y2 = y;
	int x3 = x2;
	int y3 = y2 + height;
	int x4 = x;
	int y4 = y + height;


	if ((cxPar - x1)*(cxPar - x1) + (cyPar - y1)*(cyPar - y1) > rPar*rPar) {
		return false;
	}

	if ((cxPar - x2)*(cxPar - x2) + (cyPar - y2)*(cyPar - y2) > rPar*rPar) {
		return false;
	}

	if ((cxPar - x3)*(cxPar - x3) + (cyPar - y3)*(cyPar - y3) > rPar*rPar) {
		return false;
	}

	if ((cxPar - x4)*(cxPar - x4) + (cyPar - y4)*(cyPar - y4) > rPar*rPar) {
		return false;
	}

	return true;
}

std::string Rectangle::svgCode()
{
	std::string result = "<rect x=\"";
	result += std::to_string(x) + "\" y=\"" + std::to_string(y) + "\" width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\" fill=\"" + fill + "\" />\n";
	return result;
}
