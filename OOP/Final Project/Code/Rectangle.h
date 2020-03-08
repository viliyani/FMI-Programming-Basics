#pragma once
#include "Figure.h"

class Rectangle : public Figure {
private:
	int x;
	int y;
	int width;
	int height;
	std::string fill;
public:
	Rectangle();
	Rectangle(int xPar, int yPar, int widthPar, int heightPar, std::string fillPar);

	void print() const override;

	std::string getType() const override;

	void translate(int xPar, int yPar) override;

	bool withinRectangle(int xPar, int yPar, int widthPar, int heightPar) override;
	bool withinCircle(int cxPar, int cyPar, int rPar) override;

	std::string svgCode() override;

};