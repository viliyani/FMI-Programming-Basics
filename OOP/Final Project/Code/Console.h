#pragma once
#include "Figure.h"
#include "FigureCreator.h"
#include "FigureExtractor.h"
#include <vector>
#include <regex>

class Console {
private:
	std::string openedFile = "none";
	std::vector<Figure*> figures;

	// Prints
	void printWelcome() const;
	void printHelp() const;
	void printInvalidInput() const;

	// Print figures 
	void printAllFigures() const;

	// Create new figure
	void createFigure(std::vector<std::string> & parameters);

	// Erase figure
	void eraseFigure(std::vector<std::string> & parameters);

	// Translate
	void translateFigure(std::vector<std::string> & parameters);

	// Within
	void within(std::vector<std::string> & parameters);

	// Open
	void openFile(std::vector<std::string> & parameters, std::ifstream & file);

	// Close
	void closeFile(std::ifstream & fileGet, std::ofstream & filePut);

	// Save
	void saveFile(std::ofstream & filePut);

	// Save as
	void saveAsFile(std::vector<std::string> & parameters, std::ofstream & filePut);

	// Helper method for splitting user input in parameters
	std::vector<std::string> splitInput(std::string & str) const;
public:
	void start();


};