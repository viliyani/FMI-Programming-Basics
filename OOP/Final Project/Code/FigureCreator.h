#pragma once
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <vector>
#include <iostream>

class FigureCreator {
private:
	std::string type;
	std::vector<std::string> parameters;
public:
	FigureCreator() = default;
	FigureCreator(std::string typePar, std::vector<std::string> & parametersPar);
	
	bool isValidInput();
	Figure* create();

	// Valdators for each type
	bool validateRectangle();
	bool validateCircle();
	bool validateLine();

	// Creators for each type
	Rectangle* createRectangle();
	Circle* createCircle();
	Line* createLine();
};