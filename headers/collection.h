#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

struct Domino {
	std::string left;
	std::string right;
};

class Collection
{
private:
	std::list<Domino> unsorted;
	std::list<Domino> sorted;
	std::list<Domino>::iterator findDomino(std::string&, bool);
	Domino addDomino(std::list<Domino>::iterator, bool);
	std::list<Domino> readFiles(std::string);
	Domino readDomino(std::string);
public:
	Collection(std::string, std::string);
	void sortCollection();
	Domino placeRight();
	Domino placeLeft();
	bool isCompleted();
	void displayCollection();
};