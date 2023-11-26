#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

struct Domino {
	std::string left;
	std::string right;
	//std::string getKey() {
	//	return (left + right);
	//}
};

class Collection
{
private:
	std::list<Domino> unsorted;
	//std::unordered_map<std::string, Domino> dominoPool;
	std::list<Domino> sorted;
	std::list<Domino>::iterator findDomino(std::string&, bool);
	Domino addDomino(std::list<Domino>::iterator, bool);
	//std::unordered_map<std::string, Domino> readFiles1(std::string);
	Domino readDomino(std::string);
public:
	Collection(std::string, std::string);
	void sortCollection();
	Domino placeRight();
	Domino placeLeft();
	bool isCompleted();
	void displayCollection();
	std::list<Domino> readFiles(std::string);
};