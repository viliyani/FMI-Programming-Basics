#include "Line.h"

Line::Line() : x1(0), y1(0), x2(0), y2(0)
{
}

Line::Line(int x1Par, int y1Par, int x2Par, int y2Par) : x1(x1Par), y1(y1Par), x2(x2Par), y2(y2Par)
{
}

void Line::print() const
{
	std::cout << "line " << x1 << " " << y1 << " " << x2 << " " << y2;
}

std::string Line::getType() const
{
	return "line";
}

void Line::translate(int xPar, int yPar)
{
	x1 += xPar;
	y1 += yPar;
	x2 += xPar;
	y2 += yPar;
}

bool Line::withinRectangle(int xPar, int yPar, int widthPar, int heightPar)
{
	int tx1 = xPar;
	int ty1 = yPar;
	int tx2 = xPar + widthPar;
	int ty2 = yPar;
	int tx3 = x2;
	int ty3 = y2 + heightPar;
	int tx4 = xPar;
	int ty4 = yPar + heightPar;

	if ((tx1 <= x1 && ty1 <= y1) && (tx2 >= x2 && ty2 <= y2) && (tx3 >= x2 && ty3 >= y2) && (tx4 <= x1 && ty4 >= y1)) {
		return true;
	}

	return false;
}

bool Line::withinCircle(int cxPar, int cyPar, int rPar)
{
	if ((cxPar - x1)*(cxPar - x1) + (cyPar - y1)*(cyPar - y1) > rPar*rPar) {
		return false;
	}

	if ((cxPar - x2)*(cxPar - x2) + (cyPar - y2)*(cyPar - y2) > rPar*rPar) {
		return false;
	}

	return true;
}

std::string Line::svgCode()
{
	std::string result = "<line x1=\"";
	result += std::to_string(x1) + "\" y1=\"" + std::to_string(y1) + "\" x2=\"" + std::to_string(x2) + "\" y2=\"" + std::to_string(y2) + "\" />\n";
	return result;
}
