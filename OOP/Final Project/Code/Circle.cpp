#include "Circle.h"
#include <math.h>

Circle::Circle() : cx(0), cy(0), r(0), fill("none")
{
}

Circle::Circle(int cxPar, int cyPar, int rPar, std::string fillPar) : cx(cxPar), cy(cyPar), r(rPar), fill(fillPar)
{
}

void Circle::print() const
{
	std::cout << "circle " << cx << " " << cy << " " << r << " " << fill;
}

std::string Circle::getType() const
{
	return "circle";
}

void Circle::translate(int xPar, int yPar)
{
	cx += xPar;
	cy += yPar;
}

bool Circle::withinRectangle(int xPar, int yPar, int widthPar, int heightPar)
{
	int x1 = xPar;
	int y1 = yPar;
	int x2 = xPar + widthPar;
	int y2 = yPar;
	int x3 = x2;
	int y3 = y2 + heightPar;
	int x4 = xPar;
	int y4 = yPar + heightPar;

	if ((x1 <= (cx+r) && y1 <= ((cy + r))) && ((x3 >= (cx + r) && y3 >= (cy + r)))) {
		return true;
	}

	return false;
}

bool Circle::withinCircle(int cxPar, int cyPar, int rPar)
{
	int distance = sqrt((cxPar - cx)*(cxPar - cx) + (cyPar - cy)*(cyPar - cy));

	if (distance <= (r - rPar)) {
		return true;
	}

	return false;
}

std::string Circle::svgCode()
{
	std::string result = "<circle cx=\"";
	result += std::to_string(cx) + "\" cy=\"" + std::to_string(cy) + "\" r=\"" + std::to_string(r) + "\" fill=\"" + fill + "\" />\n";
	return result;
}
