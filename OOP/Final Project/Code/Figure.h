#pragma once
#include <iostream>
#include <string>

// https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int/37864920
/*bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}*/

class Figure {
private:

public:
	
	void drawFigure() const;

	virtual void print() const = 0;

	virtual std::string getType() const;

	virtual void translate(int xPar, int yPar) = 0;

	virtual bool withinRectangle(int xPar, int yPar, int widthPar, int heightPar) = 0;
	virtual bool withinCircle(int cxPar, int cyPar, int rPar) = 0;

	virtual std::string svgCode() = 0;

};