#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

class CollectionC {
private:
	std::list<std::pair<std::string, std::string>> listA;
	std::list<std::pair<std::string, std::string>> listResults;
	std::list<std::pair<std::string, int>> listP;
	std::pair<std::string, std::string> firstDomino;

public:
	CollectionC(std::string, std::string);
	void displayLine();
};

static bool sortByFirstString(const std::pair<std::string, std::string>&, const std::pair<std::string, std::string>&);
static bool sortBySecondString(const std::pair<std::string, std::string>&, const std::pair<std::string, std::string>&);
static bool sortByFirstElement(const std::pair<std::string, int>&, const std::pair<std::string, int>&);
static bool sortBySecondElement(const std::pair<std::string, int>&, const std::pair<std::string, int>&);