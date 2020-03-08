#pragma once
#include "Figure.h"

class Line : public Figure {
private:
	int x1;
	int y1;
	int x2;
	int y2;
public:
	Line();
	Line(int x1Par, int y1Par, int x2Par, int y2Par);

	void print() const override;

	std::string getType() const override;

	void translate(int xPar, int yPar) override;

	bool withinRectangle(int xPar, int yPar, int widthPar, int heightPar) override;
	bool withinCircle(int cxPar, int cyPar, int rPar) override;

	std::string svgCode() override;

};