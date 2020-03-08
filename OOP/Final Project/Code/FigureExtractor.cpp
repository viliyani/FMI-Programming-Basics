#include "FigureExtractor.h"

Rectangle * FigureExtractor::createRectangle(std::string & line)
{
	int x, y, width, height;
	std::string fill;

	std::regex reg_attributes("^.*<(.+?) .*x=\"([0-9]+)\" .*y=\"([0-9]+)\" .*width=\"([0-9]+)\" .*height=\"([0-9]+)\" .*fill=\"([a-z]+)\".*$");
	std::smatch matches;

	std::regex_search(line, matches, reg_attributes);

	if (matches.size() < 6) {
		std::cout << "Extracting problem!\n";
		return nullptr;
	}

	x = std::stoi(matches[2]);
	y = std::stoi(matches[3]);
	width = std::stoi(matches[4]);
	height = std::stoi(matches[5]);
	fill = matches[6];

	Rectangle * temp = new Rectangle(x, y, width, height, fill);

	return temp;
}

Circle * FigureExtractor::createCircle(std::string & line)
{
	int cx, cy, r;
	std::string fill;

	std::regex reg_attributes("^.*<(.+?).*cx=\"([0-9]+)\" .*cy=\"([0-9]+)\" .*r=\"([0-9]+)\" .*fill=\"([a-z]+)\".*$");
	std::smatch matches;
	
	std::regex_search(line, matches, reg_attributes);

	if (matches.size() < 6) {
		std::cout << "Extracting problem!\n";
		return nullptr;
	}

	cx = std::stoi(matches[2]);
	cy = std::stoi(matches[3]);
	r = std::stoi(matches[4]);
	fill = matches[5];

	Circle * temp = new Circle(cx, cy, r, fill);

	return temp;
}

Line * FigureExtractor::createLine(std::string & line)
{
	int x1, y1, x2, y2;

	std::regex reg_attributes("^.*<(.+?).*x1=\"([0-9]+)\" .*y1=\"([0-9]+)\" .*x2=\"([0-9]+)\" .*y2=\"([0-9]+)\".*$");
	std::smatch matches;

	std::regex_search(line, matches, reg_attributes);

	if (matches.size() < 6) {
		std::cout << "Extracting problem!\n";
		return nullptr;
	}

	x1 = std::stoi(matches[2]);
	y1 = std::stoi(matches[3]);
	x2 = std::stoi(matches[4]);
	y2 = std::stoi(matches[5]);

	Line * temp = new Line(x1, y1, x2, y2);

	return temp;
}
