#pragma once
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <vector>
#include <iostream>
#include <regex>

class FigureExtractor {
private:

public:
	// Extractors for each type
	Rectangle* createRectangle(std::string & line);
	Circle* createCircle(std::string & line);
	Line* createLine(std::string & line);
};