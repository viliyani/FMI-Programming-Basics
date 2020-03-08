#include "Console.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>

// https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int/37864920
bool is_Integer(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

void Console::printWelcome() const
{
	std::cout << "Welcome! Enter command. For help, enter '?'\n\n";
}

void Console::printHelp() const
{
	std::cout << "--> Commands available:\n";
	std::cout << "- print\n";
	std::cout << "- create <rectangle/circle/line> <params>\n";
	std::cout << "- erase <index>\n";
	std::cout << "- translate vertical=<value> horizontal=<value> {<index>}\n";
	std::cout << "- within <rectangle/circle> <params>\n";
	std::cout << "- save\n";
	std::cout << "- saveas <filename>\n";
	std::cout << "- open <filename>\n";
	std::cout << "- close\n";
	std::cout << "- exit\n";
}

void Console::printInvalidInput() const
{
	std::cout << "Invalid input! \n";
}

void Console::printAllFigures() const
{
	if (this->figures.size() == 0) {
		std::cout << "No available figures! \n";
	}
	else {
		for (int i = 0; i < figures.size(); i++)
		{
			std::cout << i + 1 << ". ";
			figures[i]->print();
			std::cout << std::endl;
		}
	}
}

void Console::createFigure(std::vector<std::string>& parameters)
{
	Figure * newFigure;

	if (parameters[1] == "rectangle" || parameters[1] == "circle" || parameters[1] == "line") {
		FigureCreator creator(parameters[1], parameters);

		if (creator.isValidInput()) {
			newFigure = creator.create();
		}
		else {
			return;
		}
	}
	else {
		std::cout << "You want to create invalid figure! \n";
		return;
	}

	this->figures.push_back(newFigure);
	std::cout << "Successfully created " << parameters[1] << " (" << this->figures.size() << ")\n";
}

void Console::eraseFigure(std::vector<std::string>& parameters)
{
	if (parameters.size() < 2) {
		std::cout << "Error! No figure number is given! \n";
		return;
	}

	if (!is_Integer(parameters[1])) {
		std::cout << "Error! Figure number need to be integer!" << std::endl;
		return;
	}

	int removeIdx = stoi(parameters[1]);

	if (!(removeIdx >= 1 && removeIdx <= figures.size())) {
		std::cout << "There is no figure number " << removeIdx << "\n";
		return;
	}

	Figure * figure = figures[removeIdx - 1];

	figures.erase(figures.begin() + removeIdx - 1);

	std::cout << "Erased a " << figure->getType() << " (" << removeIdx << ")\n";

	delete figure;
}

void Console::translateFigure(std::vector<std::string>& parameters)
{
	if (parameters.size() < 3) {
		std::cout << "Error! Please, give vertical and horizontal! \n";
		return;
	}

	if (!((parameters[2].find("horizontal=") != std::string::npos) && (parameters[1].find("vertical=") != std::string::npos))) {
		std::cout << "Error! Please, give attributes vertical and horizontal! \n";
		return;
	}

	if ((parameters[2].find('=') + 1) == parameters[2].size() || (parameters[1].find('=') + 1) == parameters[1].size()) {
		std::cout << "Error! Please, give values for vertical and horizontal! \n";
		return;
	}


	std::string str_x = parameters[2].substr(parameters[2].find('=') + 1, parameters[2].size());
	std::string str_y = parameters[1].substr(parameters[1].find('=') + 1, parameters[1].size());

	if (!(is_Integer(str_x) && is_Integer(str_y))) {
		std::cout << "Error! Give integers for vertical and horizontal!" << std::endl;
		return;
	}

	int tx = stoi(str_x);
	int ty = stoi(str_y);

	if (parameters.size() == 4) {
		// Validate figure number
		if (!is_Integer(parameters[3])) {
			std::cout << "Error! Figure number need to be integer!" << std::endl;
			return;
		}

		int figureIdx = stoi(parameters[3]);

		if (!(figureIdx >= 1 && figureIdx <= figures.size())) {
			std::cout << "There is no figure number " << figureIdx << "\n";
			return;
		}

		// Translate only this figure
		figures[figureIdx - 1]->translate(tx, ty);

		std::cout << "Translated " << figures[figureIdx - 1]->getType() << " (" << (figureIdx) << ") \n";
	}
	else {
		// Translate All Figures
		if (figures.size() > 0) {
			for (int i = 0; i < figures.size(); i++) {
				figures[i]->translate(tx, ty);
			}

			std::cout << "Translated all figures\n";
			return;
		}
		else {
			std::cout << "No available figures for translating!\n";
			return;
		}
	}
}

void Console::within(std::vector<std::string>& parameters)
{
	if (parameters.size() < 5) {
		std::cout << "Error! Please, give enough parameters! \n";
		return;
	}

	if (!((parameters[1].find("rectangle") != std::string::npos) || (parameters[1].find("circle") != std::string::npos))) {
		std::cout << "Error! Choose within - rectangle or circle! \n";
		return;
	}

	// Within Rectangle
	if (parameters[1].find("rectangle") != std::string::npos) {
		int rx = stoi(parameters[2]);
		int ry = stoi(parameters[3]);
		int rwidth = stoi(parameters[4]);
		int rheight = stoi(parameters[5]);

		int br = 1;

		for (int i = 0; i < figures.size(); i++) {
			if (figures[i]->withinRectangle(rx, ry, rwidth, rheight)) {
				std::cout << (br++) << ". ";
				figures[i]->print();
				std::cout << std::endl;
			}
		}
	}

	// Within Circle
	if (parameters[1].find("circle") != std::string::npos) {
		int cx = stoi(parameters[2]);
		int cy = stoi(parameters[3]);
		int cr = stoi(parameters[4]);

		int br = 1;

		for (int i = 0; i < figures.size(); i++) {
			if (figures[i]->withinCircle(cx, cy, cr)) {
				std::cout << (br++) << ". ";
				figures[i]->print();
				std::cout << std::endl;
			}
		}
	}

}

void Console::openFile(std::vector<std::string>& parameters, std::ifstream & file)
{
	if (openedFile != "none") {
		std::cout << "Currently, the file \""<< openedFile << "\" is opened. If you want to open another file, first close currently opened file! \n";
		return;
	}

	if (parameters.size() != 2) {
		std::cout << "Error! To open file, enter only the command - open <filename> \n";
		return;
	}

	file.open(parameters[1], std::ios::in);

	if (!file.good())
	{
		std::cout << "Problem with file open!" << std::endl;
		return;
	}

	openedFile = parameters[1];

	std::string line = "";

	// # Extract figures from the file
	std::regex check_type("^.*<(.+?) .*$");
	std::smatch matches;

	Figure * newFigure;

	FigureExtractor figExtractor;

	while (std::getline(file, line))
	{
		std::regex_search(line, matches, check_type);

		if (matches[1] == "rect") {
			newFigure = figExtractor.createRectangle(line);
			if (newFigure != nullptr) {
				figures.push_back(newFigure);
			}
		}

		if (matches[1] == "circle") {
			newFigure = figExtractor.createCircle(line);
			if (newFigure != nullptr) {
				figures.push_back(newFigure);
			}
		}

		if (matches[1] == "line") {
			newFigure = figExtractor.createLine(line);
			if (newFigure != nullptr) {
				figures.push_back(newFigure);
			}
		}

	}

	std::cout << "Successfully opened " << parameters[1] << "\n";
	file.close();
}

void Console::closeFile(std::ifstream & fileGet, std::ofstream & filePut)
{
	if (openedFile == "none") {
		std::cout << "No open file is available! \n";
		return;
	}

	fileGet.close();
	filePut.close();

	std::cout << "Successfully closed " << openedFile << "\n";

	openedFile = "none";

	// Clear figures
	std::vector<Figure*>::iterator iter;
	for (iter = figures.begin(); iter != figures.end(); ++iter)
	{
		delete *iter;
	}
	figures.clear();
}

void Console::saveFile(std::ofstream & filePut)
{
	if (openedFile == "none") {
		std::cout << "No open file is available! \n";
		return;
	}

	filePut.open(openedFile, std::ofstream::out | std::ofstream::trunc);

	if (!filePut.good())
	{
		std::cout << "File open problem in saving! \n";
		return;
	}

	filePut << "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg Public \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg>\n";

	for (int i = 0; i < figures.size(); i++)
	{
		filePut << figures[i]->svgCode();
	}

	filePut << "</svg>\n";

	std::cout << "Successfully saved to " << openedFile << " \n";
}

void Console::saveAsFile(std::vector<std::string>& parameters, std::ofstream & filePut)
{
	if (openedFile == "none") {
		std::cout << "No open file is available! \n";
		return;
	}

	if (parameters.size() != 2) {
		std::cout << "Error! To save as file, enter only the command - saveas <filename> \n";
		return;
	}

	filePut.open(parameters[1], std::ofstream::out | std::ofstream::trunc);

	if (!filePut.good())
	{
		std::cout << "File open problem in saving! \n";
		return;
	}

	filePut << "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg Public \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg>\n";

	for (int i = 0; i < figures.size(); i++)
	{
		filePut << figures[i]->svgCode();
	}

	filePut << "</svg>\n";

	std::cout << "Successfully saved to " << parameters[1] << " \n";
}

std::vector<std::string> Console::splitInput(std::string & str) const
{
	// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string

	std::istringstream iss(str);

	std::vector<std::string> result{ std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>{} };

	return result;
}

void Console::start()
{
	// ### Main Program Controller ###

	// Print welcome message
	printWelcome();

	// String input for user option and helper variables
	std::string input;

	// Here will be setted user chosen operation
	std::string operation;

	// Parameters in option
	std::vector<std::string> parameters;

	// File stream
	std::ifstream fileGet;
	std::ofstream filePut;

	// Infinite loop for operations
	while (true) {
		// User need to enter operation
		std::cout << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);

		// Parameters
		parameters = splitInput(input);

		// Get first word, which is user operation
		operation = parameters[0];


		// Check operation
		if (operation == "?") {
			// ## Help ##
			printHelp();
		}
		else if (operation == "print" && openedFile != "none") {
			// ## Print All Figures ##
			printAllFigures();
		}
		else if (operation == "create" && openedFile != "none") {
			// ## Create New Figure ##
			createFigure(parameters);
		}
		else if (operation == "erase" && openedFile != "none") {
			// ## Erase Figure ##
			eraseFigure(parameters);
		}
		else if (operation == "translate" && openedFile != "none") {
			// ## Translate ##
			translateFigure(parameters);
		}
		else if (operation == "within" && openedFile != "none") {
			// ## Within ##
			within(parameters);
		}
		else if (operation == "open") {
			// ## Open ##
			openFile(parameters, fileGet);
		}
		else if (operation == "close" && openedFile != "none") {
			// ## Close ##
			closeFile(fileGet, filePut);
		}
		else if (operation == "save" && openedFile != "none") {
			// ## Save ##
			saveFile(filePut);
		}
		else if (operation == "saveas" && openedFile != "none") {
			// ## Save As ##
			saveAsFile(parameters, filePut);
		}
		else if (operation == "exit") {
			// ## Exit ##
			std::cout << "Exit \n\n";
			break;
		}
		else {
			// ## Invalid Operation is given ##
			std::cout << "Invalid operation! If you need help, enter '?'\n";
		}
	}


}
