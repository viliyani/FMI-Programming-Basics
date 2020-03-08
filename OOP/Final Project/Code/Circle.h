#pragma once
#include "Figure.h"

class Circle : public Figure {
private:
	int cx;
	int cy;
	int r;
	std::string fill;
public:
	Circle();
	Circle(int cxPar, int cyPar, int rPar, std::string fillPar);

	void print() const override;

	std::string getType() const override;

	void translate(int xPar, int yPar) override;

	bool withinRectangle(int xPar, int yPar, int widthPar, int heightPar) override;
	bool withinCircle(int cxPar, int cyPar, int rPar) override;

	std::string svgCode() override;

};