#include "FigureCreator.h"

// https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int/37864920
bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

FigureCreator::FigureCreator(std::string typePar, std::vector<std::string> & parametersPar) : type(typePar), parameters(parametersPar)
{
}

bool FigureCreator::isValidInput()
{
	if (type == "rectangle") {
		return validateRectangle();
	} else if (type == "circle") {
		return validateCircle();
	}
	else if(type == "line") {
		return validateLine();
	}
	else {

	}
	return false;
}

Figure * FigureCreator::create()
{
	if (type == "rectangle") {
		return createRectangle();
	}
	else if (type == "circle") {
		return createCircle();
	}
	else if (type == "line") {
		return createLine();
	}
	else {
		return nullptr;
	}
}

bool FigureCreator::validateRectangle()
{
	if (parameters.size() < 6) {
		std::cout << "Error! No enough parameters!" << std::endl;
		return false;
	}

	if (!(isInteger(parameters[2]) && isInteger(parameters[3]) && isInteger(parameters[4]) && isInteger(parameters[5]))) {
		std::cout << "Error! Parameters: x, y, width, height - need to be integers!" << std::endl;
		return false;
	}

	return true;
}

bool FigureCreator::validateCircle()
{
	if (parameters.size() < 5) {
		std::cout << "Error! No enough parameters!" << std::endl;
		return false;
	}

	if (!(isInteger(parameters[2]) && isInteger(parameters[3]) && isInteger(parameters[4]))) {
		std::cout << "Error! Parameters: cx, cy, r - need to be integers!" << std::endl;
		return false;
	}

	return true;
}

bool FigureCreator::validateLine()
{
	if (parameters.size() < 6) {
		std::cout << "Error! No enough parameters!" << std::endl;
		return false;
	}

	if (!(isInteger(parameters[2]) && isInteger(parameters[3]) && isInteger(parameters[4]) && isInteger(parameters[5]))) {
		std::cout << "Error! Parameters: x1, y1, x2, y2 - need to be integers!" << std::endl;
		return false;
	}
}

Rectangle * FigureCreator::createRectangle()
{
	int x = stoi(parameters[2]);
	int y = stoi(parameters[3]);
	int width = stoi(parameters[4]);
	int height = stoi(parameters[5]);
	std::string fill;

	if (parameters.size() == 7) {
		fill = parameters[6];
	}
	else {
		fill = "none";
	}

	Rectangle * temp = new Rectangle(x, y, width, height, fill);

	return temp;
}

Circle * FigureCreator::createCircle()
{
	int cx = stoi(parameters[2]);
	int cy = stoi(parameters[3]);
	int r = stoi(parameters[4]);
	std::string fill;

	if (parameters.size() == 6) {
		fill = parameters[5];
	}
	else {
		fill = "none";
	}

	Circle * temp = new Circle(cx, cy, r, fill);

	return temp;
}

Line * FigureCreator::createLine()
{
	int x1 = stoi(parameters[2]);
	int y1 = stoi(parameters[3]);
	int x2 = stoi(parameters[4]);
	int y2 = stoi(parameters[5]);

	Line * temp = new Line(x1, y1, x2, y2);

	return temp;
}


